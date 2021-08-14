#!/usr/bin/env bash

echo
echo "-------------------------------------"
echo "Welcome to the installation script. 
It installs my favorite software."
echo "-------------------------------------"
echo

# User confirmation dialog
while true; do
    read -p "Do you wish to proceed? [y/n]" yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

# -----------------------------------------------------

echo
echo "INSTALLING AUR HELPER"
echo

# Base-devel
sudo pacman -S base-devel --noconfirm --needed

# Yay
git clone https://aur.archlinux.org/yay.git "$HOME/downloads/yay"
cd $HOME/downloads/yay
makepkg -si --noconfirm

# ----------------------------------------------------

echo
echo "INSTALLING SOFTWARE"
echo


PKGS=(

    # SYSTEM ------------------------------------------
    'alacritty'                   # Terminal
    'zsh'                         # Shell
    'python-pip'                  # Python packages
    'lxappearance'                # GTK theme switcher
    'otf-san-francisco'           # Apple font
    'nerd-fonts-iosevka'          # Icons
    'wget'                        # Download web content
    'xrandr'                      # Monitor configuration
    'rust'                        # Programming language

    # UTILITIES ---------------------------------------
    'ranger'                      # File explorer
    'xsane'                       # Scanning
    'qbittorrent'                 # Torrent client
    'unclutter'                   # Mouse timeout
    'flameshot'                   # Screenshot tool
    'gcolor3'                     # Color picker
    'timeshift'                   # Backup snapshots
    'insync'                      # Cloud sync
    'gotop-bin'                   # System monitoring
    'polybar'                     # Taskbar
    'networkmanager-dmenu-git'    # Network manager
    'devour'                      # Swallow programs
    'dragon-drag-and-drop-git'    # Drag and drop
    'baobab'                      # Disk space
    'optimus-manager'             # GPU switcher

    # DEVELOPMENT -------------------------------------
    'git'                         # Version control
    'neovim'                      # Text editor
    'typora'                      # Markdown editor

    # WEB TOOLS ---------------------------------------
    'firefox'                     # Web browser
    'firefox-tridactyl-native'    # Vim integration
    'gdown'                       # GDrive download

    # MEDIA -------------------------------------------
    'alsa-utils'                  # For setting volume
    'bluez-utils'                 # Bluetooth support
    'feh'                         # Image viewer
    'mpv'                         # Media player
    'gimp'                        # Image manipulation
    'rofi-bluetooth-git'          # Bluetooth control
    'pavucontrol'                 # GTK audio control
  

    # PRODUCTIVITY ------------------------------------
    'anki'                        # Flashcard app
    'obs-studio'                  # Screen Recorder
    'thunar'                      # GTK file manager
    'zoom'                        # Virtual Classroom
    'teams'                       # Video Communication
    'zsa-wally'                   # Keyboard Layout
    'mailspring'                  # Email client
    'masterpdfeditor'             # PDF editor

    # PRINTER -----------------------------------------
    'cups'                        # Printer system
    'hplip'                       # HP drivers
    'system-config-printer'       # Gui tool

    # VIRTUALIZATION ----------------------------------
    'virtualbox'
    'virtualbox-host-modules-arch'
)

for PKG in "${PKGS[@]}"; do
    echo "INSTALLING: ${PKG}"
    sudo sudo -u $USER yay -S "$PKG" --noconfirm --needed
done

# REMOVING UNNEEDED PACKAGES ---------------------------

echo
echo "Removing clutter"
echo

# Packages
RMV=(
    'nitrogen'
    'volumeicon'
    'xfce4-settings'
)

# Removal
for RM in "${RMV[@]}"; do
    echo "REMOVING: ${RM}"
    sudo sudo -u $USER yay -R "$RM" --noconfirm 
done

# ------------------------------------------------------

echo
echo "RUMNO: Build program"

# Clone and build
git clone https://gitlab.com/natjo/rumno.git "$HOME/rumno"
cd $HOME/rumno
cargo build --release

# Put in Path
sudo cp $HOME/rumno/target/release/rumno /usr/local/bin/
sudo cp $HOME/rumno/target/release/rumno-background /usr/local/bin/

# Delete source
rm -rf $HOME/rumno

# ------------------------------------------------------

echo
echo "Done!"
echo "Script finished installation process"
echo
