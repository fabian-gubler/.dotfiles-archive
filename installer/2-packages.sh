
cp /etc/apt/sources.list /etc/apt/sources.list.bak
ln -s ~/.dotfiles/installer/sources.list /etc/apt/sources.list

# Keys
wget -qO - https://typora.io/linux/public-key.asc | sudo apt-key add -

PACKAGES=(
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
	'arandr'				      # xrandr frontend

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

for PKG in "${PACKAGES[@]}"; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER apt install "$PKG"
done
