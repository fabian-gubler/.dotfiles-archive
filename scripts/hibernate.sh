#!/bin/bash

# NOTE: DON'T RUN THIS SCRIPT, IT DOESN'T WORK YET

# -- SOURCES
# https://gist.github.com/eloylp/b0d64d3c947dbfb23d13864e0c051c67?permalink_comment_id=3936683
# https://linuxconfig.org/how-to-restore-hibernation-on-fedora-35
# -- SOURCES

# create subvolume
btrfs subvolume create /swap

# create swapfile
touch /swap/swapfile
chattr +C /swap/swapfile 
fallocate --length 33GiB /swap/swapfile
chmod 600 /swap/swapfile 
mkswap /swap/swapfile

# initramfs
# add_dracutmodules+=" resume "

cat <<-EOF | sudo tee /etc/dracut.conf.d/resume.conf
add_dracutmodules+=" resume "
EOF
sudo dracut -f

# check if contains resume module
sudo lsinitrd -m

# modify kernel
export UUID=$(findmnt -no UUID -T /swap/swapfile) && echo ${UUID}
TEST=resume=UUID=${UUID}"
GRUB_CMDLINE_LINUX="[...] resume=UUID=${UUID}"

# configure grub
sudo grub2-mkconfig -o /boot/grub2/grub.cfg
