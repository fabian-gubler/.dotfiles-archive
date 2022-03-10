# Dotfiles for my Linux installation
This repository is separated into three components:
- **config:** configuration files for my favorite programs
- **installer:** installing packages for freshly installed system
- **scripts:** for personal use

# Installation

```bash
# Install Git
sudo apt install git

# Clone Repository
git clone https://github.com/fabian-gubler/.dotfiles.git ~/.dotfiles

# Run Intaller Scripts
cd ~/.dotfiles/installer
sudo bash 1-base.sh
sudo bash 2-packages.sh
sudo bash 3-config.sh
```
