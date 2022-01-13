# base packages
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# dwm
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# dmenu
cd ~/.dotfiles/suckless/dmenu
sudo make clean install

# startup
cd ~/.dotfiles/installer/xorg/
ln -s .xinitrc ~/.xinitrc
ln -s .xprofile ~/.xprofile
ln -s .Xresources ~/.Xresources
ln -s .zprofile ~/.zprofile
