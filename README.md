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

# Todo Later
- SSH Setup (Github)
- ZSA wally cli | https://github.com/zsa/wally/wiki/Linux-install
- TLP Configuration

# Done but not in ansible
- PAM Keyring | https://nurdletech.com/linux-notes/agents/keyring.html
- Change what Closing lid does | sv /etc/systemd/logind.conf
