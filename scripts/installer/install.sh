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
echo "-------------------------------------"
echo "Welcome to the installation part of the script. 
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

# Build
if ! command -v $aurhelper &> /dev/null
then
    git clone https://aur.archlinux.org/yay.git "$HOME/downloads/yay"
    cd $HOME/downloads/yay
    makepkg -si --noconfirm
    break
else
    echo "$aurhelper already Exists, skipping..."
fi

# ----------------------------------------------------

echo
echo "INSTALLING SOFTWARE"
echo

PRGS=(

    # SYSTEM ------------------------------------------
    'alacritty'                   # Terminal
    'zsh'                         # Shell
    'python-pip'                  # Python packages
    'lxappearance'                # GTK theme switcher
    'otf-san-francisco'           # Apple font
    'nerd-fonts-iosevka'          # Icons
    'wget'                        # Download web content
    'rust'                        # Programming language
    'exa'                         # Ls alternative

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
    'virtualbox'                  # OS virtualization
    'virtualbox-host-modules-arch'
)

# Compare list with already installed packages
packages=$(comm -13 <(pacman -Qqe | sort) <(printf "%s\n" "${PRGS[@]}" | sort))

# ------------------------------------------------------

echo "The following programs will be installed:"
echo $packages


# Installation loop
for PKG in $packages; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER $aurhelper -S "$PKG" --noconfirm --needed
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
    sudo sudo -u $USER $aurhelper -R "$RM" --noconfirm 
done

# ------------------------------------------------------

echo
echo "RUMNO: Build program"

# Only install if doesnt exist
if ! command -v rumno &> /dev/null
then
    git clone https://gitlab.com/natjo/rumno.git "$HOME/rumno"
    cd $HOME/rumno
    cargo build --release
    break
else
    echo "Rumno already Exists, skipping..."
fi

# ------------------------------------------------------

echo
echo "Done!"
echo "Script finished installation process"
echo

# ------------------------------------------------------
# --- PART 3: FINAL SETUP ------------------------------
# ------------------------------------------------------

echo
echo "-------------------------------------"
echo "Welcome to the configuration part of the script. 
This will deploy my dotfiles and download some files."
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
echo
echo "FINAL SETUP AND CONFIGURATION"

# Clone dotfiles
sudo rm -rf $HOME/.dotfiles
cd ~
git clone https://github.com/fabian-gubler/.dotfiles.git 

# ------------------------------------

echo
echo "RANGER: Configuring devicons"

git clone https://github.com/alexanderjeurissen/ranger_devicons ~/.config/ranger/plugins/ranger_devicons
echo "default_linemode devicons" >> $HOME/.dotfiles/ranger/rc.conf

# ------------------------------------

echo
echo "ZSH: Configuring prompt"

# Create .zsh directory and clone repo
mkdir -p "$HOME/.config/zsh"
git clone https://github.com/sindresorhus/pure.git "$HOME/.config/zsh/pure"

# Delete .zshrc
sudo rm -rf $HOME/.zshrc

# ------------------------------------

echo
echo "MAILSPRILNG: Downloading nord theme"

mkdir $HOME/.config/Mailspring/packages
git clone https://github.com/faraadi/mailspring-nord-theme.git "$HOME/.config/Mailspring/packages/mailspring-nord-theme"

# ------------------------------------

echo
echo "MPV: uosc overlay"

mkdir $HOME/.config/mpv/scripts
git clone https://github.com/darsain/uosc.git "$HOME/.config/mpv/scripts/uosc.lua"

# ------------------------------------

echo
echo "DMENU: Build program"

cd $HOME/.dotfiles/dmenu
sudo make install

# ------------------------------------

echo
echo "GTK: theming"

mkdir $HOME/.themes

# GTK
git clone https://github.com/EliverLara/Nordic.git "$HOME/.themes/Nordic"

# qBittorrent
git clone https://github.com/jagannatharjun/qbt-theme.git "$HOME/.themes/qBittorrent"

# Typora
mkdir $HOME/temp
git clone https://github.com/pantajoe/typora-nord-theme.git "$HOME/temp/typora"
cp $HOME/temp/typora/src/nord.css $HOME/.config/Typora/themes/
cp -r $HOME/temp/typora/src/nord $HOME/.config/Typora/themes/

# ------------------------------------

echo
echo "LUNARVIM: Single line install"

# Single line command
LVBRANCH=rolling bash <(curl -s https://raw.githubusercontent.com/lunarvim/lunarvim/rolling/utils/installer/install.sh) 

# ------------------------------------

echo
echo "DOTFILES: Deploying files"

# .dotfiles
echo "Deploying my dotfiles"
cd $HOME/.dotfiles
./install

# .secrets
# echo "Deploying sensitive files"
# sudo rm -rf $HOME/.secrets
# mkdir $HOME/.secrets && cd $HOME/.secrets
# git clone https://github.com/fabian-gubler/.secrets.git 
# sudo ./install 

# .mozilla
# echo "Dowload and extract mozilla folder"
# sudo $HOME/.secrets/installer/gdrive.sh

# ------------------------------------

# echo
# echo "HDD: Mounting and give ownership"
# 
# # Create group & add user
# sudo groupadd data
# sudo usermod -a -G data $USER
# 
# # Append sdb1 to fstab
# sudo echo "# /dev/sdb1
# UUID=3c01e926-8fa4-42ab-a988-0f83e7e05df5 /data    auto nosuid,nodev,nofail,x-gvfs-show 0 0" >> /etc/fstab
# sudo mkdir /data
# sudo mount -a
# 
# # Ownership permission
# sudo chown $USER:data /data

# ------------------------------------

# Laptop lid
sudo sed -i -e 's|[# ]*HandleLidSwitch[ ]*=[ ]*.*|HandleLidSwitch=ignore|g' /etc/systemd/logind.conf

# Systemd
sudo systemctl start optimus-manager.service
sudo systemctl enable --now cups

# ------------------------------------

#

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
