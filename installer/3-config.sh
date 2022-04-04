# -----------------------------------------------------------------------------
# NODE PACKAGES
# -----------------------------------------------------------------------------

# Nodejs v17 | https://github.com/nodesource/distributions/blob/master/README.md
curl -fsSL https://rpm.nodesource.com/setup_17.x | sudo bash -

# Node Packages
PKG_NODE=(
	'create-react-app'			# React application
)

# Installation Loop
for PKG in "${PKG_NODE[@]}"; do
    echo "INSTALLING: $PKG"
    sudo npm install -g "$PKG"
done

# -----------------------------------------------------------------------------
# PYTHON PACKAGES
# -----------------------------------------------------------------------------

# !!!
# sudo apt install -y python3-pip

# Python Packages
PKG_PYTHON=(
	'dotbot'					# Config files bootstrap
	'yt-dlp'					# Download YouTube Videos
	'ueberzug'					# Display Images
	'flake8'					# Python Linter
	'black'						# Python Formatter
)

# Installation Loop
for PKG in "${PKG_PYHON[@]}"; do
    echo "INSTALLING: $PKG"
    python3 -m pip install -U "$PKG"
done

# -----------------------------------------------------------------------------
# RUST PACKAGES
# -----------------------------------------------------------------------------

# Packages
PKG_CARGO=(
	'stylua'				# Lua formatter
)

# Installation Loop
for PKG in "${PKG_CARGO[@]}"; do
    echo "INSTALLING: $PKG"
    cargo install "$PKG"
done

# -----------------------------------------------------------------------------
# MISC PACKAGES
# -----------------------------------------------------------------------------


# TODO: ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install

# TODO: VPN setup | https://protonvpn.com/support/linux-openvpn/
	# 1. network-manager-openvpn-gnome
	# 2. run nm-connection-editor
	# 3. Add according to guide
	# 4. Connect via networkmanager-dmenu

# Gotop | https://github.com/cjbassi/gotop
wget https://github.com/xxxserxxx/gotop/releases/download/v4.1.1/gotop_v4.1.1_linux_amd64.tgz
sudo tar -xvzf gotop_v4.1.1_linux_amd64.tgz -C /usr/local/bin

# Typora | https://support.typora.io/Typora-on-Linux/
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -
sudo add-apt-repository 'deb https://typora.io/linux ./'
sudo apt update && sudo apt install -y typora

# Todo TXT | https://github.com/todotxt/todo.txt-cli
sudo git clone https://github.com/todotxt/todo.txt-cli todotxt
cd todotxt
make
make install

# Network manager Dmenu
git clone https://github.com/firecat53/networkmanager-dmenu $HOME/.local/bin/networkmanager-dmenu

# Dragon
git clone https://github.com/mwh/dragon /tmp/dragon
cd /tmp/dragon
make

# Devour
git clone https://github.com/salman-abedin/devour.git /tmp/devour
cd /tmp/devour
sudo make install

# Zotero
wget -qO- https://zotero.retorque.re/file/apt-package-archive/install.sh | sudo bash
sudo apt update
sudo apt install -y zotero

# Only Office | https://www.onlyoffice.com/de/download-desktop.aspx?from=desktop
wget -O /tmp/onlyoffice.deb https://download.onlyoffice.com/install/desktop/editors/linux/onlyoffice-desktopeditors_amd64.deb
sudo apt install -y /tmp/onlyoffice.deb

# Master PDF Editor | https://code-industry.net/free-pdf-editor/
wget -O /tmp/masterpdf.deb https://code-industry.net/public/master-pdf-editor-5.8.33-qt5.x86_64.deb
sudo apt install -y /tmp/masterpdf.deb

# -----------------------------------------------------------------------------
# Options
# -----------------------------------------------------------------------------

# ZSH Default Shell
sudo kitty chsh -s $(which zsh)

# Crontabs
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.dotfiles && git add . && git commit -m"automated update" && git push origin main") | crontab -
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.config/nvim && git add . && git commit -m"automated update" && git push origin main"automated update" && git push origin main") | crontab -

# -----------------------------------------------------------------------------
# ARCHIVED
# -----------------------------------------------------------------------------

# Bluetooth Autoconnect
# git clone https://github.com/jrouleau/bluetooth-autoconnect /tmp/bluetooth-autoconnect
# mv /tmp/bluetooth-autoconnect
# sudo mv bluetooth-autoconnect.service /etc/systemd/system/
# sudo mv bluetooth-autoconnect /usr/bin/
# sudo systemctl enable bluetooth-autoconnect.service

# Pipewire | https://wiki.debian.org/PipeWire
# sudo touch /etc/pipewire/media-session.d/with-pulseaudio
# sudo cp /usr/share/doc/pipewire/examples/systemd/user/pipewire-pulse.* /etc/systemd/user/
# systemctl --user daemon-reload
# systemctl --user --now disable pulseaudio.service pulseaudio.socket
# systemctl --user --now enable pipewire pipewire-pulse

# Signal | https://signal.org/download/linux/
# wget -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
# cat signal-desktop-keyring.gpg | sudo tee -a /usr/share/keyrings/signal-desktop-keyring.gpg > /dev/null
# echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg] https://updates.signal.org/desktop/apt xenial main' |\
# sudo tee -a /etc/apt/sources.list.d/signal-xenial.list
# sudo apt update && sudo apt install -y signal-desktop
