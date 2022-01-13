# base packages
sudo apt install make gcc libx11-dev libxft-dev libxinerama-dev xorg

# dwm
cd ~/.dotfiles/suckless/dwm
sudo make clean install

# dmenu
cd ~/.dotfiles/suckless/dmenu
sudo make clean install

# startup files
cd ~/.dotfiles/config/xorg/
cp .xinitrc ~/.xinitrc
cp .xprofile ~/.xprofile
cp .Xresources ~/.Xresources
cp .zprofile ~/.zprofile
