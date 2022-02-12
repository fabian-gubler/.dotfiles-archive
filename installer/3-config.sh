# ------------------------------------------------------
# --- PACKAGES -----------------------------------------
# ------------------------------------------------------

# Typora | https://support.typora.io/Typora-on-Linux/
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -
sudo add-apt-repository 'deb https://typora.io/linux ./'
sudo apt update && sudo apt install typora

# Signal | https://signal.org/download/linux/
wget -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
cat signal-desktop-keyring.gpg | sudo tee -a /usr/share/keyrings/signal-desktop-keyring.gpg > /dev/null
echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg] https://updates.signal.org/desktop/apt xenial main' |\
sudo tee -a /etc/apt/sources.list.d/signal-xenial.list
sudo apt update && sudo apt install signal-desktop

# Alacritty | https://github.com/alacritty/alacritty/blob/master/INSTALL.md
cargo install alacritty

# Network manager
git clone https://github.com/firecat53/networkmanager-dmenu ~/.local/bin/networkmanager-dmenu

# Dragon
git clone https://github.com/mwh/dragon ~/Downloads/dragon
cd ~/Downloads/dragon
make

# Devour
git clone https://github.com/salman-abedin/devour.git ~/Downloads/devour
cd ~/Downloads/devour
sudo make install

# Nextcloud
sudo add-apt-repository ppa:nextcloud-devs/client
sudo apt install nextcloud-desktop
# ZSA wally cli
# ???

# Printer | Might require: sudo apt install hplip
# mkdir -p ~/HP-Laser
# cd ~/HP-Laser
# wget https://ftp.hp.com/pub/softlib/software13/printers/CLP150/uld-hp_V1.00.39.12_00.15.tar.gz
# tar -xf  uld-hp_V1.00.39.12_00.15.tar.gz
# cd ~/HP-Laser/uld
# sudo ./install-printer.sh

# Gotop | move to secrets
# 	https://github.com/xxxserxxx/gotop/releases
# 	mv gotop ~/.local/bin

# VPN setup | https://protonvpn.com/support/linux-openvpn/
# 1. network-manager-openvpn-gnome
# 2. run nm-connection-editor
# 3. Add according to guide
# 4. Connect via networkmanager-dmenu

# ------------------------------------------------------
# --- Configuration ------------------------------------
# ------------------------------------------------------

# Dotfiles
cd ~/.dotfiles/config
./install

# Virtual Machine
virsh net-define /usr/share/libvirt/networks/default.xml
virsh net-autostart default
virsh net-start default

# Pipewire | https://wiki.debian.org/PipeWire

# ------------------------------------------------------
# --- NPM ----------------------------------------------
# ------------------------------------------------------

# Nodejs v17 | https://github.com/nodesource/distributions/blob/master/README.md
sudo curl -fsSL https://deb.nodesource.com/setup_17.x | sudo bash -
sudo apt install -y nodejs

# Node Packages
NODE=(
	'create-react-app'			# React application
	'express-generator'			# Express application
	'tailwindcss'				# Styling
)

for PKG in "${NODE[@]}"; do
    echo "INSTALLING: $PKG"
    sudo sudo npm install -g "$PKG"
done
