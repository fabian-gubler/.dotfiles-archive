#!/bin/bash

executable=$(find ~/.dotfiles/scripts/bash -maxdepth 1 -perm -111 -type f | fzf)
$executable
