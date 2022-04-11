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
