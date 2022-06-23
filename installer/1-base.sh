# Installation Instructions
	# Download <Everything Netinstall> ISO
	# Choose <Swiss German> Keyboard layout
	# Choose <Custom Operating System>
	# Select Package Groups <NetworkManager> and <Standard>
	# Create user <fabian>
	# ... Reboot

# -----------------------------------------------------------------------------
# SSH & CLONE REPOSITORIES
# -----------------------------------------------------------------------------

# TODO: Clone Directory with Github Credentials

# NOTE: Nextcloud install + Dotbot for ssh file transfer

# start ssh-agent
# eval "$(ssh-agent -s)"

# add key
# ssh-add ~/.ssh/id_ed25519

# clone repo
# sudo dnf install git
# git clone --recursive git@github.com:fabian-gubler/.dotfiles.git /home/fabian/.dotfiles

# -----------------------------------------------------------------------------
# BASE UTILITES
# -----------------------------------------------------------------------------

# PACKAGES
sudo dnf install -y xorg-x11-server-Xorg xorg-x11-xinit libX11-devel libXft-devel libXinerama-devel
sudo dnf install -y make gcc mesa-dri-drivers

# sudo apt install -y xorg libx11-dev libxft-dev libxinerama-dev

# DWM
cd /home/fabian/.dotfiles/config/suckless/dwm
sudo make clean install

# DMENU
cd /home/fabian/.dotfiles/config/suckless/dmenu
sudo make clean install

# SLOCK
# cd /home/fabian/.dotfiles/config/suckless/slock
# sudo make clean install

# STARTUP FILES
cd /home/fabian/.dotfiles/config/xorg/
cp .xinitrc /home/fabian/.xinitrc
cp .xprofile /home/fabian/.xprofile
cp .Xresources /home/fabian/.Xresources
