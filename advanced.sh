# TODO: Automatic Updates | https://fedoraproject.org/wiki/AutoUpdates
# TODO: Adding Swap Space for hibernation (~10GB)
#
# TODO: Firefox
# 	# create user-defined profile or regular expression
# 	# prefs.js
#
# TODO: Debug Packages
# 	# Dragon
# 	# Masterpdfeditor
#
# TODO: ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install
#
# TODO: TLP Configuration
# TODO: Printing Dependencies

# -----------------------------------------------------------------------------
# PYTHON PACKAGES
# -----------------------------------------------------------------------------

# Python Packages
PKG_PYTHON=(
	'ueberzug'					# Display Images
	'flake8'					# Python Linter
	'black'						# Python Formatter
)

# Installation Loop
for pkg in "${PKG_PYHON[@]}"; do
    echo "INSTALLING: $pkg"
    python3 -m pip install -U "$pkg"
done

# python3 -m pip install -U dotbot yt-dlp ueberzug flake8 black autorandr

# -----------------------------------------------------------------------------
# SIMLINK DIRECTORIES
# -----------------------------------------------------------------------------

# zotero
rm -rf ~/.zotero
ln -s ~/nextcloud/applications/.zotero ~/ # 6.0.4

# firefox
rm -rf ~/.mozilla
ln -s ~/nextcloud/applications/.mozilla ~/ # 91.7.0esr

# -----------------------------------------------------------------------------
# MISC PACKAGES
# -----------------------------------------------------------------------------

# Gotop | https://github.com/cjbassi/gotop
wget -O /tmp/gotop.tgz https://github.com/xxxserxxx/gotop/releases/download/v4.1.1/gotop_v4.1.1_linux_amd64.tgz
sudo tar -xvzf /tmp/gotop.tgz -C /usr/local/bin

# Network manager Dmenu
git clone https://github.com/firecat53/networkmanager-dmenu /usr/local/bin/networkmanager-dmenu

# Dragon
# git clone https://github.com/mwh/dragon /tmp/dragon
# cd /tmp/dragon
# sudo make

# Devour
git clone https://github.com/salman-abedin/devour.git /tmp/devour
cd /tmp/devour
sudo make install

# Typora
wget -O ~/Downloads/typora.tar.gz "https://download.typora.io/linux/Typora-linux-x64.tar.gz"
cd ~/Downloads
sudo tar xfvz typora.tar.gz
cd bin
sudo cp -r Typora-linux-x64 /opt/typora
sudo ln -s /opt/typora/Typora /usr/bin/typora

# Only Office | https://www.onlyoffice.com/de/download-desktop.aspx?from=desktop
wget -O /tmp/onlyoffice.rpm "https://download.onlyoffice.com/install/desktop/editors/linux/onlyoffice-desktopeditors.x86_64.rpm"
sudo dnf install -y /tmp/onlyoffice.rpm

# -----------------------------------------------------------------------------
# Options
# -----------------------------------------------------------------------------

# ZSH Default Shell
sudo kitty chsh -s $(which zsh)

# Crontabs
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.dotfiles && git add . && git commit -m"automated update" && git push origin main") | crontab -
(crontab -l 2>/dev/null; echo "0 * * * * cd ~/.config/nvim && git add . && git commit -m"automated update" && git push origin main"automated update" && git push origin main") | crontab -
(crontab -l 2>/dev/null; echo "*/1 * * * * ~/.dotfiles/scripts/utils/battery-notifier.sh") | crontab -

# Systemd
systemctl --user enable mpd
systemctl --user enable mpDris2

# Root Systemd
sudo systemctl enable tlp.service
