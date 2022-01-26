# TODO: Backports (tmux)

PACKAGES=(
	# VIRTUAL MACHINES --------------------------------------------------------
	'qemu-system'
	'libvirt-daemon-system'
	'virt-manager'

	# SYSTEM ------------------------------------------------------------------
	'firmware-iwlwifi'			# Bluetooth
	'fzf'						# Fuzzy finder
	'redshift'					# Night filter
	'adwaita-qt'				# Adwaita dark
	'qt5ct'						# Qt theming
	'xclip'						# Clipboard
	'xbacklight'				# Screen Brightness
	'picom'						# Compositor
	'openvpn'					# VPN client
	'arandr'					# Xrandr frontend

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

# INSTALLATION
sudo apt update
sudo apt upgrade

for PKG in "${PACKAGES[@]}"; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER apt install "$PKG"
done
