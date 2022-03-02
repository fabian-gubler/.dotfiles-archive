# -----------------------------------------------------------------------------
# DEBIAN PACKAGES
# -----------------------------------------------------------------------------

# TODO: Backports: tmux

PACKAGES=(

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
	'nm-connection-editor'		# Manage Networks

	# COMMAND LINE  -----------------------------------------------------------
	'golang'					  # Programming Language
	'python3-pip'                 # Python Package Manager
	'zsh'                         # Shell
	'tmux'                        # Terminal Multiplexer
	'exa'                         # Better ls
	'wget'                        # Download web content
	'ranger'                      # File explorer
	'devour'                      # Swallow programs
	'unzip'                       # Unzip directories
	'todotxt-cli'				  # Todo List
	'texlive-full'				  # Latex Packages
	'ncdu'						  # Disk space

	# APPLICATIONS ------------------------------------------------------------
	'qbittorrent'                 # Torrent client
	'xsane'                       # Scanning
	'unclutter'                   # Mouse timeout
	'timeshift'                   # Backup snapshots
	'firefox-esr'                 # Web browser
	'anki'                        # Flashcard app
	'zathura'                     # PDF viewer

	# MEDIA -------------------------------------------------------------------
	'bluez'                       # Bluetooth protocol
	'pipewire'                    # Audio
	'pavucontrol'                 # Audio Control
	'sxiv'                        # Image viewer
	'mpv'                         # Media player

	# VIRTUAL MACHINES --------------------------------------------------------
	'qemu'
	'virt-manager'
	'bridge-utils'
)

# INSTALLATION
sudo apt update
sudo apt upgrade

for PKG in "${PACKAGES[@]}"; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER apt install "$PKG"
done
