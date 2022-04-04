# Third-Party Sources
sudo dnf install -y https://mirrors.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm https://mirrors.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm

# -----------------------------------------------------------------------------
# FEDORA PACKAGES
# -----------------------------------------------------------------------------


GROUPS=(
	'networkmanager-submodules'
	'virtualization'
	'sound-and-video'
)


# Install
for GRP in "${GROUPS[@]}"; do
    echo "INSTALLING: $GRP"
    sudo dnf group install -y "$GRP" 
done

PACKAGES=(

	# SYSTEM ------------------------------------------------------------------
	'fzf'						# Fuzzy finder
	'redshift'					# Night filter
	'adwaita-qt5'				# Adwaita dark
	'xsetroot'					# Solid background
	'qt5ct'						# Qt theming
	'xclip'						# Clipboard
	'xbacklight'				# Screen Brightness
	'acpi'						# Battery info
	'picom'						# Compositor
	'arandr'					# Xrandr frontend
	'gnome-keyring'				# Keyring Daemon
	'seahorse'					# Keyring Gui
	'nextcloud'					# Cloud

	# PROGRAMMING LANGUAGES  --------------------------------------------------
	'nodejs'					# Node
	'lua'						# Lua
	'rust'						# Rust
	'golang'					# Go
	'python3-pip'				# Python Package Manager
	'cargo'						# Rust Package Manager

	# COMMAND LINE  -----------------------------------------------------------
	'neovim'					# Tex editor
	'zsh'						# Shell
	'kitty'						# Terminal
	'alacritty'					# Fallback Terminal
	'tmux'                      # Terminal Multiplexer
	'exa'                       # Better ls
	'ranger'                    # File explorer
	'texlive'					# Latex Packages
	'ncdu'						# Disk space
	'newsboat'					# RSS Reader

	# APPLICATIONS ------------------------------------------------------------
	'qbittorrent'               # Torrent client
	'xsane'                     # Scanning
	'unclutter-xfixes'          # Mouse timeout
	'timeshift'                 # Backup snapshots
	'firefox'					# Web browser
	'anki'						# Flashcard spaced repetition
	'chromium'					# Web browser (Backup)
	'zathura'                   # PDF viewer
	'sxiv'                      # Image viewer
	'mpv'                       # Media player
)

# Install
for PKG in "${PACKAGES[@]}"; do
    echo "INSTALLING: $PKG"
    sudo dnf install -y "$PKG" 
done
