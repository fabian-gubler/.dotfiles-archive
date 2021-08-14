#!/bin/sh

# INTRODUCTION -----------------------------------------

echo
echo 'Starting the installation'
echo

# Cloning scripts repo
sudo pacman -S git --noconfirm --needed
git clone https://github.com/fabian-gubler/scripts.git "$HOME/scripts"

# Update packages
echo 'Synchronizing database and updating packages'
sudo pacman -Syu --noconfirm --needed

# MAIN -------------------------------------------------

$HOME/scripts/installer/1-software.sh
$HOME/scripts/installer/2-configuration.sh

# CONCLUSION -------------------------------------------
# Reboot prompt
while true; do
    read -p "Do you wish to reboot your system? [y/n]" yn
    case $yn in
        [Yy]* ) reboot; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
