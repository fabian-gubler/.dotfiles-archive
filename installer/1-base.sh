# -----------------------------------------------------------------------------
# BASE UTILITES
# -----------------------------------------------------------------------------

# TODO: Clone Directory with Github Credentials
# TODO: Copy Apt Sources List

# Upgrade
sudo apt update
sudo apt upgrade

# PACKAGES
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# DWM
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# DMENU
cd /home/fabian/.dotfiles/suckless/dmenu
sudo make clean install

# STARTUP FILES
cd /home/fabian/.dotfiles/config/xorg/
cp .xinitrc /home/fabian/.xinitrc
cp .xprofile /home/fabian/.xprofile
cp .Xresources /home/fabian/.Xresources
cp .zprofile /home/fabian/.zprofile
