# Read desired time
TIME=$1

# Check Speaker (2 Seconds)
pactl set-sink-volume @DEFAULT_SINK@ 50%
mpv --length=2 ~/nextcloud/music/resonance.opus

# Alarm at time
at $TIME << ENDMARKER
pactl set-sink-volume @DEFAULT_SINK@ 50%
mpv --loop-file=inf --start=0 ~/nextcloud/music/resonance.opus
ENDMARKER
