#!/bin/sh

aurhelper="yay"

# ------------------------------------------------------
# --- PART 1: INTRODUCTION------------------------------
# ------------------------------------------------------

echo
echo 'Some things need to be done first before running...'
echo

echo 'Synchronizing database and updating packages'
sudo pacman -Syu --noconfirm --needed

# Git
sudo pacman -S git --noconfirm --needed

# ------------------------------------------------------
# --- PART 2: INSTALLATION------------------------------
# ------------------------------------------------------

echo
echo "INSTALLING AUR HELPER"
echo

# Base-devel
sudo pacman -S base-devel --noconfirm --needed

# Build
if ! command -v $aurhelper &> /dev/null
then
    git clone https://aur.archlinux.org/yay.git "$HOME/downloads/yay"
    cd $HOME/downloads/yay
    makepkg -si --noconfirm
    rm -rf $HOME/downloads/yay
else
    echo "$aurhelper already Exists, skipping..."
fi

# ----------------------------------------------------

echo
echo "INSTALLING SOFTWARE"
echo

PRGS=(

    # LANGUAGES ---------------------------------------
    'python-pip'                  # Python packages
    'rust'                        # Programming language

    # DEVELOPMENT -------------------------------------
    'git'                         # Version control
    'neovim'                      # Text editor
    'typora'                      # Markdown editor

    # SYSTEM ------------------------------------------
    'alacritty'                   # Terminal
    'zsh'                         # Shell
    'lxappearance'                # GTK theme switcher
    'wget'                        # Download web content
    'exa'                         # Better ls
    'qt5ct'                       # Qt theming
    'adwaita-qt'                  # Adwaita dark

    # UTILITIES ---------------------------------------
    'ranger'                      # File explorer
    'ueberzug'                    # Image preview
    'xsane'                       # Scanning
    'qbittorrent'                 # Torrent client
    'unclutter'                   # Mouse timeout
    'flameshot'                   # Screenshot tool
    'timeshift'                   # Backup snapshots
    'insync'                      # Cloud sync
    'gotop-bin'                   # System monitoring
    'networkmanager-dmenu-git'    # Network manager
    'devour'                      # Swallow programs
    'dragon-drag-and-drop-git'    # Drag and drop
    'baobab'                      # Disk space
    'unzip'                       # Unzip directories
    'tmux'                        # Terminal Multiplexer
    'ncpamixer'                   # Cli Pavucontrol

    # WEB TOOLS ---------------------------------------
    'firefox'                     # Web browser
    'firefox-developer-edition'   # Web browser
    'firefox-tridactyl-native'    # Vim integration
    'newsboat'                    # RSS Feed
    'ytfzf'                       # YouTube search
    'ferdi'                       # Website Platform

    # MEDIA -------------------------------------------
    'alsa-utils'                  # For setting volume
    'bluez-utils'                 # Bluetooth support
    'bluez'                       # Bluetooth protocol
    'bluetooth-autoconnect'       # Trusted connect
    'pulseaudio-bluetooth'        # Bluetooth support
    'feh'                         # Image viewer
    'mpv'                         # Media player
    'pavucontrol'                 # GTK audio control

    # PRODUCTIVITY ------------------------------------
    'mailspring'                  # Email Client 
    'anki'                        # Flashcard app
    'pcmanfm-gtk3'                # GTK file manager
    'zoom'                        # Virtual Classroom
    'teams'                       # Video Communication
    'zsa-wally-cli'               # Keyboard Layout
    'masterpdfeditor'             # PDF editor (advanded)
    'okular'                      # PDF editor (light)
    'zathura'                     # PDF viewer
    'xournal'                     # PDF markup

    # SC-IM Dependencies ------------------------------
    'libxml2'
    'libzip'
    'gnuplot'
    'libxlsxwriter'

    # VIRTUALIZATION ----------------------------------
    'virtualbox'                  # OS virtualization
    'virtualbox-host-modules-arch'# Kernel modules
)

# Compare list with already installed packages
packages=$(comm -13 <(pacman -Qqe | sort) <(printf "%s\n" "${PRGS[@]}" | sort))

# Installation loop
for PKG in $packages; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER $aurhelper -S "$PKG" --noconfirm --needed
done

# ------------------------------------------------------

echo
echo "LUNARVIM: Single line install"

# Single line command
LVBRANCH=rolling bash <(curl -s https://raw.githubusercontent.com/lunarvim/lunarvim/rolling/utils/installer/install.sh) 

# -----------------------------------------------------

echo
echo "Done!"
echo "Script finished installation process"
echo

# ------------------------------------------------------
# --- PART 3: FINAL SETUP ------------------------------
# ------------------------------------------------------
echo
echo "FINAL SETUP AND CONFIGURATION"

# Systemd
sudo systemctl enable cups
sudo systemctl enable bluetooth.service
sudo systemctl enable pulseaudio-bluetooth-autoconnect

# tty | add FONT=ter-p32b
echo 'KEYMAP=de' | sudo tee /etc/vconsole.conf

# Keyboard
localectl set-x11-keymap us "" altgr-intl

# Wifi connect automatically
nmcli radio wifi on

ssh-keygen
cat $HOME/.ssh/id_rsa.pub

# User confirmation dialog
while true; do
    read -p "Add your ssh key to github settings [y/n]" yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

# Optional: git clone command

# FINISH -----------------------------------------------

# Reboot prompt
while true; do
    read -p "Do you wish to reboot your system? [y/n]" yn
    case $yn in
        [Yy]* ) reboot; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
