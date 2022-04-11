# -----------------------------------------------------------------------------
# NODE PACKAGES
# -----------------------------------------------------------------------------

# Node Packages
PKG_NODE=(
	'create-react-app'			# React application
	'mdanki'					# Create Flashcards in Markdown
)

# Installation Loop
for PKG in "${PKG_NODE[@]}"; do
    echo "INSTALLING: $PKG"
    sudo npm install -g "$PKG"
done

# -----------------------------------------------------------------------------
# PYTHON PACKAGES
# -----------------------------------------------------------------------------

# Python Packages
# PKG_PYTHON=(
# 	'dotbot'					# Config files bootstrap
# 	'yt-dlp'					# Download YouTube Videos
# 	'ueberzug'					# Display Images
# 	'flake8'					# Python Linter
# 	'black'						# Python Formatter
# )

# Installation Loop
# for PKG in "${PKG_PYHON[@]}"; do
#     echo "INSTALLING: $PKG"
#     python3 -m pip install -U "$PKG"
# done

python3 -m pip install -U dotbot yt-dlp ueberzug flake8 black

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

# TODO FEDORA
	# Dragon
	# Masterpdfeditor

# TODO: ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install

# TODO: VPN setup | https://protonvpn.com/support/linux-openvpn/
	# 1. network-manager-openvpn-gnome
	# 2. run nm-connection-editor
	# 3. Add according to guide
	# 4. Connect via networkmanager-dmenu

# Gotop | https://github.com/cjbassi/gotop
wget -O /tmp/gotop.tgz https://github.com/xxxserxxx/gotop/releases/download/v4.1.1/gotop_v4.1.1_linux_amd64.tgz
sudo tar -xvzf /tmp/gotop.tgz -C /usr/local/bin

# Todo TXT | https://github.com/todotxt/todo.txt-cli
sudo git clone https://github.com/todotxt/todo.txt-cli /tmp/todotxt
cd /tmp/todotxt
sudo make
sudo make install

# Network manager Dmenu
git clone https://github.com/firecat53/networkmanager-dmenu /usr/local/bin/networkmanager-dmenu

# Dragon
git clone https://github.com/mwh/dragon /tmp/dragon
cd /tmp/dragon
sudo make

# Devour
git clone https://github.com/salman-abedin/devour.git /tmp/devour
cd /tmp/devour
sudo make install

# Zotero
# wget https://www.zotero.org/download/client/dl?channel=release&platform=linux-x86_64&version=6.0.4
# sudo tar -xvzf 

# Only Office | https://www.onlyoffice.com/de/download-desktop.aspx?from=desktop
wget -O /tmp/onlyoffice.rpm https://download.onlyoffice.com/install/desktop/editors/linux/onlyoffice-desktopeditors.x86_64.rpm
sudo dnf install -y /tmp/onlyoffice.rpm

# Master PDF Editor | https://code-industry.net/free-pdf-editor/
wget -O /tmp/masterpdf.rpm https://code-industry.net/public/master-pdf-editor-5.8.46-qt5.x86_64.rpm
sudo dnf install -y /tmp/masterpdf.rpm

# -----------------------------------------------------------------------------
# Options
# -----------------------------------------------------------------------------

# ZSH Default Shell
sudo kitty chsh -s $(which zsh)

# Crontabs
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.dotfiles && git add . && git commit -m"automated update" && git push origin main") | crontab -
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.config/nvim && git add . && git commit -m"automated update" && git push origin main"automated update" && git push origin main") | crontab -

# Systemd
systemctl --user enable mpd
systemctl --user enable mpDris2

# Root Systemd
sudo systemctl enable tlp.service

# Test if necessary
sudo usermod -aG audio fabian
