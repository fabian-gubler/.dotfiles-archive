# Folder structure
- Config
- Scripts
- Secrets
- Installer

NODE=(
	'npm'						# Package manager
	'create-react-app'
	'express-generator'
	'tailwindcss'
)

# Useful Information
VPN Configuration
- https://www.smarthomebeginner.com/configure-openvpn-to-autostart-linux/


# Debian Packages
sudo apt update

DEB=(
    # VIRTUAL MACHINES --------------------------------------------------------
	'qemu-system'
	'libvirt-daemon-system'
	'virt-manager'

    # SYSTEM ------------------------------------------------------------------
	'firmware-iwlwifi'		      # Bluetooth
	'fzf'						  # Fuzzy finder
	'redshift'					  # Night filter
    'adwaita-qt'                  # Adwaita dark
	'qt5ct'                       # Qt theming
	'xclip'					      # Clipboard
	'openvpn'					  # VPN client

    # COMMAND LINE  -----------------------------------------------------------
	'golang'					  # Programming Language
    'python3-pip'                 # Python Package Manager
    'zsh'                         # Shell
    'tmux'                        # Terminal Multiplexer
    'git'                         # Version control
    'exa'                         # Better ls
    'wget'                        # Download web content
	'curl'						  # ""
    'ranger'                      # File explorer
    'devour'                      # Swallow programs
    'unzip'                       # Unzip directories

    # APPLICATIONS ------------------------------------------------------------
    'qbittorrent'                 # Torrent client
	'xsane'                       # Scanning
    'unclutter'                   # Mouse timeout
    'flameshot'                   # Screenshot tool
    'timeshift'                   # Backup snapshots
    'baobab'                      # Disk space
    'firefox-esr'                 # Web browser
    'anki'                        # Flashcard app
    'zathura'                     # PDF viewer

    # MEDIA -------------------------------------------------------------------
    'bluez'                       # Bluetooth protocol
    'pipewire'                    # Audio
    'pavucontrol'                 # Audio Control
    'sxiv'                        # Image viewer
    'mpv'                         # Media player

)

# Typora 
# https://support.typora.io/Typora-on-Linux/
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -
sudo add-apt-repository 'deb https://typora.io/linux ./'
sudo apt update
sudo apt install typora

# Signal
# https://signal.org/download/linux/
wget -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
cat signal-desktop-keyring.gpg | sudo tee -a /usr/share/keyrings/signal-desktop-keyring.gpg > /dev/null
echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg] https://updates.signal.org/desktop/apt xenial main' |\
sudo tee -a /etc/apt/sources.list.d/signal-xenial.list
sudo apt update
sudo apt install signal-desktop

# Alacritty
cargo install alacritty

# Network manager
git clone https://github.com/firecat53/networkmanager-dmenu
cd networkmanager-dmenu
mv networkmanager-dmenu ~/.local/bin

# Dragon
git clone https://github.com/mwh/dragon
cd dragon
make
mv dragon ~/.local/bin


# Neovim
???

??? 'zsa-wally-cli'               # Keyboard Layout
'gotop'                       # System monitoring
	https://github.com/xxxserxxx/gotop/releases
	mv gotop ~/.local/bin

# Zotero
wget -qO- https://downloads.sourceforge.net/project/zotero-deb/install.sh | sudo bash
sudo apt update
sudo apt install zotero

