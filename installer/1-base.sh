# necessary packages
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# dwm
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# dmenu
cd ~/.dotfiles/suckless/dmenu
sudo make clean install

# startup
ln -s ~/.dotfiles/installer/xorg/.xinitrc ~/.xinitrc
ln -s ~/.dotfiles/installer/xorg/.xprofile ~/.xprofile
