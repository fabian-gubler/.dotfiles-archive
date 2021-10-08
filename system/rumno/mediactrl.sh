#!/bin/sh

# Example script to show how rumno can be used in conjuction with amixer, xbacklight and the spotify dbus interface


# SINK=$( pactl list short sinks | grep RUNNING | sed -e 's,^\([0-9][0-9]*\)[^0-9].*,\1,' | head -n 1 )
# --background-color 3742526F
BIN="rumno -r 0.08 --icon-height 0.4 --bar-num-segments 10 --bar-segment-ratio 1.8"


# Define allowed parameters
VOLUME_INC="volume-inc"
VOLUME_DEC="volume-dec"
VOLUME_TOGGLE="volume-toggle"
BRIGHTNESS_INC="brightness-inc"
BRIGHTNESS_DEC="brightness-dec"
SPOTIFY_NEXT="spotify-next"
SPOTIFY_PREVIOUS="spotify-previous"
SPOTIFY_TOGGLE_PLAY_PAUSE="spotify-toggle-playPause"


# Execute action as specified in parameter
case $1 in
    $VOLUME_INC)
        amixer set Master 10%+ 
        NOW=$( amixer get Master |grep 'Right:' | awk -F'[]%[]' '{ print $2 }' );
        $BIN -v $NOW;
        amixer set Master unmute
        ;;
    $VOLUME_DEC)
        amixer set Master 10%-
        NOW=$( amixer get Master |grep 'Right:' | awk -F'[]%[]' '{ print $2 }' );
        $BIN -v $NOW;
        amixer set Master unmute
        ;;
    $VOLUME_TOGGLE)
        amixer set Master toggle;
        MUTED=$(pactl list sinks | grep Mute | cut -d " " -f 2)
        NOW=$( amixer get Master |grep 'Right:' | awk -F'[]%[]' '{ print $2 }' );
        if [ $MUTED = "no" ]
        then
            $BIN  -v $NOW;
        else
            $BIN  -v $NOW;
            rumno --custom-symbol $HOME/.dotfiles/system/rumno/build/res/volume_alt.svg;
        fi
        ;;
    $BRIGHTNESS_INC)
        xbacklight -inc 5;
        $BIN -b $( xbacklight -get ) ;
        ;;
    $BRIGHTNESS_DEC)
        xbacklight -dec 5;
        $BIN -b $( xbacklight -get ) ;
        ;;
    $SPOTIFY_NEXT)
        dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next;
        $BIN --next;
        ;;
    $SPOTIFY_PREVIOUS)
        dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous;
        $BIN --previous;
        ;;
    $SPOTIFY_TOGGLE_PLAY_PAUSE)
        # Spotify can be slow, checking the play status right after sending the play/pause signal might not change the state yet
        # To be safe, simply check the status before sending the signal and invert the result
        PLAYBACK_STATUS=$(dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:'org.mpris.MediaPlayer2.Player' string:'PlaybackStatus'|egrep -A 1 "string"|cut -b 26-|cut -d '"' -f 1|egrep -v ^$);
        dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause;
        if [ $PLAYBACK_STATUS = "Playing" ]
        then
            $BIN --pause;
        else
            $BIN --play;
        fi
        ;;
    *)
        echo -e "Unknown parameter '$1'\nAllowed parameters are: '$VOLUME_INC','$VOLUME_DEC','$VOLUME_TOGGLE','$BRIGHTNESS_INC','$BRIGHTNESS_DEC','$SPOTIFY_NEXT','$SPOTIFY_NEXT','$SPOTIFY_TOGGLE_PLAY_PAUSE'"
        ;;
esac
