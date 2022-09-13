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
bash bin/install.sh

# Dotfiles Configuration
bash config/configure.sh
```
# Done but not in ansible
- PAM Keyring | https://nurdletech.com/linux-notes/agents/keyring.html
- Change what Closing lid does | sv /etc/systemd/logind.conf

# Todo Later
- SSH Setup (Github)
- TLP Configuration

