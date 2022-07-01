#!/bin/bash

ID=pf0yzukt
SRC=/home/kali/.dotfiles/config/firefox-kali
DEST=/home/fabian/.mozilla/firefox/${ID}.main

rm -rf $DEST/chrome
rm -rf $DEST/extensions
ln -s $SRC/chrome $DEST/chrome
ln -s $SRC/extensions $DEST/extensions


ln -sf $SRC/user.js $DEST/user.js
ln -sf $SRC/extensions.json $DEST/extensions.json
ln -sf $SRC/extension-settings.json $DEST/extension-settings.json
