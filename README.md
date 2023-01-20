# Dotfiles for my Linux installation
This repository is separated into three primary components:
- **config:** dotfiles for my favorite applications
- **roles:** ansible playbooks for automating installation
- **scripts:** bash scripts for personal use

# Installation using Nix
I have recently migrated my setup towards NixOS.
Link of the repo can be found [here](https://github.com/fabian-gubler/nixos-config).

# Legacy Installation using Ansible

```bash
# Clone dotfiles repository
git clone --recursive https://github.com/fabian-gubler/.dotfiles

# Run Ansible Playbooks
bash scripts/install

# Dotfiles Configuration
bash config/configure.sh
```
# Automation Ideas
- [Automatic Upgrades](https://www.tecmint.com/dnf-automatic-install-security-updates-automatically-in-centos-8/)

# Audio on Tigerlake
Install SOF Drivers on [Link](https://github.com/thesofproject/sof-bin/releases)

## Notes
- Version: Tested with v.2.2.2
- Optional: /home/fabian/.dotfiles/config/audio/sound.sh
