#!/bin/bash

RGB="$(colorpicker --short --one-shot --preview)"
convert -size 150x150 xc:$RGB /tmp/rgb.png
echo "$RGB" | xsel -b
notify-send -i /tmp/rgb.png "RGB Colorpicker" "$RGB"
