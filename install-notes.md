# Folder structure
- Config
- Scripts
- Secrets
- Installer

NODE=(
	'npm'						# Package manager
	'create-react-app'
)

# Useful Information
VPN Configuration
- https://www.smarthomebeginner.com/configure-openvpn-to-autostart-linux/

# Debian Packages
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
    'tlp'                         # Battery optimization

    # COMMAND LINE  ------------------------------------------------------
	'golang'
    'python3-pip'                 # Python packages
    'zsh'                         # Shell
    'tmux'                        # Terminal Multiplexer
    'git'                         # Version control
    'exa'                         # Better ls
    'wget'                        # Download web content
	'curl'						  # ""
    'ranger'                      # File explorer
    'devour'                      # Swallow programs

    # APPLICATIONS ---------------------------------------------------------------
    'qbittorrent'                 # Torrent client
	'xsane'                       # Scanning
    'unclutter'                   # Mouse timeout
    'flameshot'                   # Screenshot tool
    'timeshift'                   # Backup snapshots
    'baobab'                      # Disk space
    'firefox-esr'                     # Web browser
    'unzip'                       # Unzip directories

    # MEDIA -------------------------------------------------------------------
    'bluez'                       # Bluetooth protocol
    'pipewire'                    # Audio
    'pavucontrol'                 # Audio Control
    'sxiv'                        # Image viewer
    'mpv'                         # Media player
)

# Add Repo
	'protonvpn'					  # VPN Client
    'typora'                      # Markdown editor

# Build from Source
'zsa-wally-cli'               # Keyboard Layout
'gotop'                       # System monitoring
	https://github.com/xxxserxxx/gotop/releases
	mv gotop ~/.local/bin
'dragon-drag-and-drop-git'    # Drag and drop
	https://github.com/mwh/dragon
	make
	mv dragon ~/.local/bin
'alacritty'                   # Terminal
'networkmanager-dmenu'		  # Network manager
'neovim'					  # Text editor

PRGS=(


    # PRODUCTIVITY ------------------------------------------------------------
    'anki'                        # Flashcard app
    'zoom'                        # Virtual Classroom
    'teams'                       # Video Communication
    'masterpdfeditor'             # PDF editor (advanded)
    'okular'                      # PDF editor (light)
    'zathura'                     # PDF viewer

    # VIRTUALIZATION ----------------------------------------------------------
    'virtualbox'                  # OS virtualization
    'virtualbox-host-dkms'        # Kernel modules
    'virtualbox-guest-utils'      # Guest utilities
)
