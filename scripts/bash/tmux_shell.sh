#!/bin/bash

# executable=$(find ~/.dotfiles/scripts/bash -maxdepth 1 -perm -111 -type f | fzf)
path=~/.dotfiles/scripts/tmux

cd $path
executable=$(cd $path && fzf --reverse)
$executable
