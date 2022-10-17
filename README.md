# Dotfiles for my Linux installation
This repository is separated into three primary components:
- **config:** dotfiles for my favorite applications
- **roles:** ansible playbooks for automating installation
- **scripts:** bash scripts for personal use

# Installation

```bash
# Clone dotfiles repository
git clone --recursive https://github.com/fabian-gubler/.dotfiles

# Run Ansible Playbooks
bash scripts/install

# Dotfiles Configuration
bash config/configure.sh
```
# Done but not in ansible
- PAM Keyring | https://nurdletech.com/linux-notes/agents/keyring.html

# Todo Later
- SSH Setup (Github)
- Set AutoEnable=true in /etc/bluetooth/main.conf
