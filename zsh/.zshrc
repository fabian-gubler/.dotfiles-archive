# Lines configured by zsh-newuser-install
HISTFILE=~/.config/zsh/.histfile
HISTSIZE=1000
SAVEHIST=1000
# End of lines configured by zsh-newuser-install

# Prompt
fpath+=$HOME/.config/zsh/pure
zstyle :compinstall filename '/home/fabian/.config/zsh/.zshrc'

autoload -U promptinit; promptinit
prompt pure

# Useful Functions
source "$ZDOTDIR/zsh-functions"

# Files to source
zsh_add_file "zsh-aliases"
# zsh_add_file "zsh-vim-mode"

# Plugins
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"

# Keybinds
bindkey -e                    # emacs bindings
bindkey -s '^o' 'ranger^M'    # open ranger
