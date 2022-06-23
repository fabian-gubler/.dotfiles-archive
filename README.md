# Dotfiles for my Linux installation
This repository is separated into three primary components:
- **config:** configuration files for my favorite programs
- **roles:** ansible playbooks for automating installation
- **scripts:** bash scripts for personal use

# Installation

```bash
# Run Ansible Playbooks
bash bin/install.sh

# Configuration
bash config/configure.sh
```

# Todo Config
Plug an Play as a focus -> Config is on top of (not replacing) defaults
> Colemak Modifications for default vim Bindings

# Todo Ansible
- Add fedora version 36 as variable for rpmfusion
- Automatic Updates | https://fedoraproject.org/wiki/AutoUpdates
- Firefox
	- NOTE: Test Upload speed of mozilla dir to nextcloud (easiest option)
	- create user-defined profile or regular expression
	- prefs.js
- ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install
- TLP Configuration

