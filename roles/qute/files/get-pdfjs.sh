#!/bin/bash

cd ~/.local/share/qutebrowser

rm -rf pdfjs
mkdir pdfjs
cd pdfjs

wget $(curl -s https://api.github.com/repos/mozilla/pdf.js/releases/latest | grep 'browser_' | grep legacy | cut -d\" -f4)
# wget https://github.com/mozilla/pdf.js/releases/download/v3.0.279/pdfjs-3.0.279-legacy-dist.zip

unzip pdfjs-3.*.zip && rm *.zip
