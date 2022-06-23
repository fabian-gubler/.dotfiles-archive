#!/bin/bash
set -e

DOTFILES_DIR="$HOME/.dotfiles"
SSH_DIR="$HOME/.ssh"
EMAIL="fabian.gubler@proton.me"

# install ansible
if ! [ -x "$(command -v ansible)" ]; then
	sudo dnf install ansible -y
fi

# create ssh folder
if ! [[ -d "$SSH_DIR" ]]; then
  mkdir -p "$SSH_DIR"

  chmod 700 "$SSH_DIR"
fi

# ssh into this maschine
if ! [[ -f "$SSH_DIR/id_rsa" ]]; then

  ssh-keygen -b 4096 -t rsa -f "$SSH_DIR/id_rsa" -N "" -C "$USER@$HOSTNAME"

  cat "$SSH_DIR/id_rsa.pub" >> "$SSH_DIR/authorized_keys"

  chmod 600 "$SSH_DIR/authorized_keys"
fi

# github ssh keys
if ! [[ -f "$SSH_DIR/id_ed25519" ]]; then
  ssh-keygen -t ed25519 -f "$SSH/id_ed25519" -N "" -C "$EMAIL"
fi

# check for ansible requirements
if [[ -f "$DOTFILES_DIR/requirements.yml" ]]; then
  cd "$DOTFILES_DIR"

  ansible-galaxy install -r requirements.yml
fi

# change directory into the dotfiles folder
cd "$DOTFILES_DIR"

# run the playbook
ansible-playbook --diff "$DOTFILES_DIR/main.yml" --ask-become-pass --verbose
