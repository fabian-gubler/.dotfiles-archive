# necessary packages
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# install dwm
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# startup
ln -s ~/.dotfiles/scripts/installer/files/.xinitrc ~/.xinitrc
