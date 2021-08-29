echo $PATH | grep -q "$HOME/.local/bin:" || export PATH="$HOME/.local/bin:$PATH"
[ -z "$DISPLAY" ] && [ $XDG_VTNR -eq 1 ] && startx
