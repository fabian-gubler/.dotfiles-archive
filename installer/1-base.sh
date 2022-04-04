# -----------------------------------------------------------------------------
# BASE UTILITES
# -----------------------------------------------------------------------------

# TODO: Clone Directory with Github Credentials

# Upgrade
sudo dnf update
sudo dnf upgrade

# PACKAGES
sudo dnf install -y xorg-x11-server-Xorg xorg-x11-xinit  libX11-devel libXft-devel libXinerama-devel

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

