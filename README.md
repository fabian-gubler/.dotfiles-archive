# Dotfiles for my Linux installation
This repository is separated into three components:
- **config:** configuration files for my favorite programs
- **installer:** installing packages for freshly installed system
- **scripts:** for personal use

# Installation

```bash
# Run Individual Installer Scripts
cd ~/.dotfiles/installer
sudo bash 1-base.sh
sudo bash 2-packages.sh
sudo bash 3-advanced.sh

# Configuration
cd ~/.dotfiles/config
dotbot -c install.conf.yaml
```

# Todo Config
Plug an Play as a focus -> Config is on top of (not replacing) defaults
> Colemak Modifications for default vim Bindings

# Todo Ansible
- Add fedora version 36 as variable for rpmfusion

TODO: Automatic Updates | https://fedoraproject.org/wiki/AutoUpdates
TODO: Firefox
	NOTE: Test Upload speed of mozilla dir to nextcloud (easiest option)
	create user-defined profile or regular expression
	prefs.js

TODO: ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install
TODO: TLP Configuration

