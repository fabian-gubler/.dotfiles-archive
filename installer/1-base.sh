# -----------------------------------------------------------------------------
# BASE UTILITES
# -----------------------------------------------------------------------------

# TODO: Clone Directory with Github Credentials
# TODO: Copy Apt Sources List

# Upgrade
sudo apt update
sudo apt upgrade

# PACKAGES
sudo apt install -y make gcc libx11-dev libxft-dev libxinerama-dev xorg

# DWM
cd /home/fabian/.dotfiles/config/suckless/dwm
sudo make clean install

# DMENU
cd /home/fabian/.dotfiles/config/suckless/dmenu
sudo make clean install

# STARTUP FILES
cd /home/fabian/.dotfiles/config/xorg/
cp .xinitrc /home/fabian/.xinitrc
cp .xprofile /home/fabian/.xprofile
cp .Xresources /home/fabian/.Xresources
cp .zprofile /home/fabian/.zprofile
