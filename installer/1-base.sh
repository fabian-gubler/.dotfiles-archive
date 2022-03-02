# -----------------------------------------------------------------------------
# BASE UTILITES
# -----------------------------------------------------------------------------

# TODO: Clone Directory with Github Credentials
# TODO: Copy Apt Sources List

# PACKAGES
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# DWM
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# DMENU
cd ~/.dotfiles/suckless/dmenu
sudo make clean install

# STARTUP FILES
cd ~/.dotfiles/config/xorg/
cp .xinitrc ~/.xinitrc
cp .xprofile ~/.xprofile
cp .Xresources ~/.Xresources
cp .zprofile ~/.zprofile
