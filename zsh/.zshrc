# Lines configured by zsh-newuser-install
HISTFILE=~/.config/zsh/.histfile
HISTSIZE=1000
SAVEHIST=1000
export MANPAGER="lvim -c 'set ft=man' -"
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

# Plugins
zsh_add_plugin "zsh-users/zsh-completions"
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"

source /home/fabian/.dotfiles/zsh/plugins/z/zsh-z.plugin.zsh

# Keybinds
bindkey -e                    # emacs bindings
bindkey -s '^o' 'ranger^M'    # open ranger
bindkey -s '^t' 'exa -a^M'    # open ranger
