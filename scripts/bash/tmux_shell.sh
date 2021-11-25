#!/bin/bash

path=~/.dotfiles/scripts/tmux

cd $path
./$(cd $path && fzf --reverse --margin=1)
