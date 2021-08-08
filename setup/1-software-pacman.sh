#!/usr/bin/env bash

echo
echo "INSTALLING PACMAN SOFTWARE"
echo

PKGS=(

    # SYSTEM ------------------------------------------
    'alacritty'                   # Terminal
    'zsh'                         # Shell
    'yay'                         # AUR helper

    # UTILITIES ---------------------------------------
    'ranger'                      # File explorer
    'xsane'                       # Scanning
    'qbittorrent'                 # Torrent client
    'unclutter'                   # Mouse timeout

    # DEVELOPMENT -------------------------------------
    'git'                         # Version control
    'neovim'                      # Text editor

    # WEB TOOLS ---------------------------------------
    'firefox'                     # Web browser

    # MEDIA -------------------------------------------
    'feh'                         # Image viewer
    'mpv'                         # Media player
    'gimp'                        # Image manipulation
    
    # PRODUCTIVITY ------------------------------------
    'anki'                        # Flashcard app

    # VIRTUALIZATION ----------------------------------
    'virtualbox'
    'virtualbox-host-modules-arch'
)

for PKG in "${PKGS[@]}"; do
    echo "INSTALLING: ${PKG}"
    sudo pacman -S "$PKG" --noconfirm --needed
done

echo
echo "Done!"
echo
