# TODO: Backports (tmux)

# -----------------------------------------------------------------------------
# DEB PACKAGES
# -----------------------------------------------------------------------------

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
	'git'                         # Version control
	'exa'                         # Better ls
	'wget'                        # Download web content
	'curl'						  # ""
	'ranger'                      # File explorer
	'devour'                      # Swallow programs
	'unzip'                       # Unzip directories
	'todotxt-cli'				  # Todo List
	'latexmk'					  # Latex Compiler
	'texlive-full'				  # Latex Packages
	'imagemagick'				  # File conversion

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
