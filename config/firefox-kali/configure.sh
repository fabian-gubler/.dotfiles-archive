#!/bin/bash

ID=vfzimg4s
SRC=/home/kali/.dotfiles/config/firefox-kali
DEST=/home/kali/.mozilla/firefox/${ID}.main

rm -rf $DEST/chrome
ln -s $SRC/chrome $DEST/chrome
ln -sf $SRC/user.js $DEST/user.js
ln -sf $SRC/extension-settings.json $DEST/extension-settings.json

rm -rf $DEST/extensions
ln -s $SRC/extensions $DEST/extensions
