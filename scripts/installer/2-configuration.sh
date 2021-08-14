#!/usr/bin/env bash

echo
echo "FINAL SETUP AND CONFIGURATION"

# ------------------------------------

echo
echo "RANGER: Configuring devicons"

git clone https://github.com/alexanderjeurissen/ranger_devicons ~/.config/ranger/plugins/ranger_devicons
echo "default_linemode devicons" >> $HOME/.dotfiles/ranger/rc.conf

# ------------------------------------

echo
echo "CUPS: Enable daemon"

sudo systemctl enable --now cups

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

# Clone repo
sudo rm -rf $HOME/dmenu
mkdir $HOME/dmenu
git clone https://git.suckless.org/dmenu "$HOME/dmenu"
cd ~/dmenu
sudo make install

# Getting Patch ready
wget https://tools.suckless.org/dmenu/patches/line-height/dmenu-lineheight-5.0.diff

echo "static unsigned int lineheight = 0;
static unsigned int min_lineheight = 8;" >> config.h 

# Patch
patch -p1 < dmenu-lineheight-5.0.diff 
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
git clone https://github.com/pantajoe/typora-nord-theme.git "$HOME/temp/typora"
cp $HOME/temp/typora/src/nord.css $HOME/.config/Typora/themes/
cp -r $HOME/temp/typora/src/nord $HOME/.config/Typora/themes/

# ------------------------------------

echo
echo "LUNARVIM: Single line install"

# Single line command
LVBRANCH=rolling bash <(curl -s https://raw.githubusercontent.com/lunarvim/lunarvim/rolling/utils/installer/install.sh) --overwrite

# ------------------------------------

echo
echo "DOTFILES: Deploying files"

# .secrets
echo "Deploying sensitive files"
sudo rm -rf $HOME/.secrets
mkdir $HOME/.secrets && cd $HOME/.secrets
git clone https://github.com/fabian-gubler/.secrets.git 
sudo ./install 

# .mozilla
echo "Dowload and extract mozilla folder"
sudo $HOME/.secrets/installer/gdrive.sh

# .dotfiles
sudo rm -rf $HOME/.dotfiles
echo "Deploying my dotfiles"
git clone https://github.com/fabian-gubler/.dotfiles.git "$HOME/.dotfiles" 
sudo $HOME/.dotfiles/install 


# ------------------------------------

echo
echo "HDD: Mounting and give ownership"

# Create group & add user
sudo groupadd data
sudo usermod -a -G data $USER

# Append sdb1 to fstab
sudo echo "# /dev/sdb1
UUID=3c01e926-8fa4-42ab-a988-0f83e7e05df5 /data    auto nosuid,nodev,nofail,x-gvfs-show 0 0" >> /etc/fstab
sudo mkdir /data
sudo mount -a

# Ownership permission
sudo chown $USER:data /data

# ------------------------------------

sudo sed -i -e 's|[# ]*HandleLidSwitch[ ]*=[ ]*.*|HandleLidSwitch=ignore|g' /etc/systemd/logind.conf
systemctl start optimus-manager.service

# ------------------------------------

### FINISH
