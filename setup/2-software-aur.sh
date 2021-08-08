#!/usr/bin/env bash

echo
echo "INSTALLING AUR SOFTWARE"
echo

PKGS=(

    # SYSTEM ------------------------------------------
    'otf-san-francisco'           # Apple font

    # UTILITIES ---------------------------------------
    'timeshift'                   # Backup snapshots
    'insync'                      # Cloud sync
    'gotop-bin'                   # System monitoring
    'polybar'                     # Taskbar
    'networkmanager-dmenu-git'    # Network manager
    'devour'                      # Swallow programs

    # DEVELOPMENT -------------------------------------
    'typora'                      # Markdown editor

    # WEB TOOLS ---------------------------------------
    'firefox-tridactyl-native'    # Vim keybind

    # MEDIA -------------------------------------------
    'rofi-bluetooth-git'          # Bluetooth control
      
    # PRODUCTIVITY ------------------------------------
    'zoom'                        # Virtual Classroom
    'teams'                       # Video Communication
    'zsa-wally'                   # Keyboard Layout
    'mailspring'                  # Email client
    'masterpdfeditor'             # PDF editor
)

for PKG in "${PKGS[@]}"; do
    echo "INSTALLING: ${PKG}"
    sudo sudo -u $USER yay -S "$PKG" --noconfirm --needed
done

echo
echo "Done!"
echo
