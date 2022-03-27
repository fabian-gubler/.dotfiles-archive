# -----------------------------------------------------------------------------
# DEBIAN PACKAGES
# -----------------------------------------------------------------------------


PACKAGES=(

	# SYSTEM ------------------------------------------------------------------
	'firmware-iwlwifi'			# Bluetooth
	'fzf'						# Fuzzy finder
	'redshift'					# Night filter
	'adwaita-qt'				# Adwaita dark
	'hsetroot'					# Solid background
	'qt5ct'						# Qt theming
	'xclip'						# Clipboard
	'xbacklight'				# Screen Brightness
	'acpi'						# Battery info
	'picom'						# Compositor
	'openvpn'					# VPN client
	'arandr'					# Xrandr frontend
	'network-manager-gnome'		# Manage Networks
	'gnome-keyring'				# Keyring Daemon
	'seahorse'					# Keyring Gui


	# PROGRAMMING LANGUAGES  --------------------------------------------------
	'lua5.3'					  # Lua
	'luarocks'					  # Lua Package Manager
	'golang'					  # Go
	'cargo'						# Rust Package Manager

	# COMMAND LINE  -----------------------------------------------------------
	'zsh'                         # Shell
	'tmux'                        # Terminal Multiplexer
	'exa'                         # Better ls
	'wget'                        # Download web content
	'ranger'                      # File explorer
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
	'chromium'					  # Web browser (Backup)
	'zathura'                     # PDF viewer

	# MEDIA -------------------------------------------------------------------
	'bluez'                       # Bluetooth protocol
	'pipewire'                    # Audio
	'pavucontrol'                 # Audio Control
	'sxiv'                        # Image viewer
	'mpv'                         # Media player

	# VIRTUAL MACHINES --------------------------------------------------------
	# 'qemu'
	# 'virt-manager'
	# 'bridge-utils'
)

# SOURCES
sudo ln -s /home/fabian/.dotfiles/installer/sources.list /etc/apt/

# INSTALLATION
sudo apt update
sudo apt upgrade

for PKG in "${PACKAGES[@]}"; do
    echo "INSTALLING: $PKG"
    sudo sudo -u $USER apt install -y "$PKG" 
done
