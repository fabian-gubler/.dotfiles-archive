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

    # SYSTEM ------------------------------------------
    'alacritty'                   # Terminal
    'zsh'                         # Shell
    'lxappearance'                # GTK theme switcher
    'wget'                        # Download web content
    'exa'                         # Better ls
    'qt5ct'                       # Qt theming
    'adwaita-qt'                  # Adwaita dark
    'hsetroot'                    # Solid Background
    'snapd'                       # External packages

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
    'rofi'                        # Custom Menus
    'devour'                      # Swallow programs
    'dragon-drag-and-drop-git'    # Drag and drop
    'baobab'                      # Disk space
    'unzip'                       # Unzip directories
    'acpilight'                   # Backlight
    'tmux'                        # Terminal Multiplexer
    'touchegg'                    # Gesture support
    'touche'                      # Customize touchegg

    # SC-IM Dependencies ------------------------------
    'libxml2'
    'libzip'
    'gnuplot'
    'libxlsxwriter'

    # DEVELOPMENT -------------------------------------
    'git'                         # Version control
    'neovim'                      # Text editor
    'typora'                      # Markdown editor

    # WEB TOOLS ---------------------------------------
    'firefox'                     # Web browser
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
    'anki'                        # Flashcard app
    'pcmanfm-gtk3'                # GTK file manager
    'zoom'                        # Virtual Classroom
    'teams'                       # Video Communication
    'zsa-wally-cli'               # Keyboard Layout
    'masterpdfeditor'             # PDF editor

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

# SNAP PACKAGES ----------------------------------------

sudo systemctl enable snapd.service
sudo systemctl start snapd.service
sudo snap install mailspring

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

ssh-keygen
cat $HOME/.ssh/id_rsa.pub

# User confirmation dialog
while true; do
    read -p "Please add your ssh key to github settings [y/n]" yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

# Clone dotfiles
sudo rm -rf $HOME/.dotfiles
git clone git@github.com:fabian-gubler/.dotfiles.git "$HOME/.dotfiles"

# ------------------------------------

echo
echo "DOTFILES: Deploying files"

# .dotfiles
echo "Deploying my dotfiles"
cd $HOME/.dotfiles
sudo ./install

# ------------------------------------

# .secrets
sudo rm -rf $HOME/.secrets
git clone git@github.com:fabian-gubler/.secrets.git "$HOME/.secrets"
sudo $HOME/.secrets/install

# ------------------------------------

echo
echo "HDD: Mounting and give ownership"

# Create group & add user
sudo groupadd data
sudo usermod -a -G data $USER
sudo usermod -a -G video $USER

# Append sdb1 to fstab
sudo echo "# /dev/sdb1
UUID=3c01e926-8fa4-42ab-a988-0f83e7e05df5 /data    auto nosuid,nodev,nofail,x-gvfs-show 0 0" >> /etc/fstab
sudo mkdir /data
sudo mount -a

# Ownership permission
sudo chown $USER:data /data

# ------------------------------------

# Systemd
sudo systemctl enable optimus-manager.service
sudo systemctl enable cups
sudo systemctl enable bluetooth.service
sudo systemctl enable pulseaudio-bluetooth-autoconnect
sudo systemctl enable snapd.service

# tty | add FONT=ter-p32b
echo 'KEYMAP=de' | sudo tee /etc/vconsole.conf

# ------------------------------------

# Cleanup Unused Folders
cd ~
rmdir Desktop Documents Downloads Music Pictures Videos Templates Public
rm -rf $HOME/.config/volumeicon
rm -rf $HOME/.config/nitrogen
rm -rf $HOME/.config/i3status
rm -rf $HOME/.config/gsimplecal

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
