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

# ZSA wally cli
# ???

# Gotop | move to secrets
# 	https://github.com/xxxserxxx/gotop/releases
# 	mv gotop ~/.local/bin

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

# ------------------------------------------------------
# --- NPM ----------------------------------------------
# ------------------------------------------------------

# Nodejs v17
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
