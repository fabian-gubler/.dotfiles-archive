# General
HISTFILE=~/.config/zsh/.histfile
HISTSIZE=10000
SAVEHIST=10000
export MANPAGER="lvim -c 'set ft=man' -"

# Pure Prompt
fpath+=$HOME/.config/zsh/pure
zstyle :compinstall filename '/home/fabian/.config/zsh/.zshrc'
autoload -U promptinit; promptinit
prompt pure
zstyle ':prompt:pure:prompt:*' color "#D8DEE9"
PURE_CMD_MAX_EXEC_TIME=99999999999999

# Completion
zstyle ':completion:*' completer _complete _ignored
zstyle :compinstall filename '/home/fabian/.config/zsh/.zshrc'
autoload -Uz compinit
compinit

# Files to source
source "$ZDOTDIR/functions"
zsh_add_file "alias"

# Keybinds
bindkey -e                        # emacs bindings
bindkey -s '^f' 'ranger^M'        # ranger
bindkey -s '^t' 'exa -a^M'        # extended ls
bindkey -s '^b' 'cd -^M'          # back in history
bindkey -s '^x' '^L'              # clear terminal
bindkey -s '^p' 'ncpamixer^M'     # ncpamixer
bindkey "^[[1;5D" backward-word   # ctrl + m
bindkey "^[[1;5C" forward-word    # ctrl + i
bindkey "^[[3~" delete-char       # make delete work
bindkey -s '^z' 'cd ~/.secrets/docs/ && devour zathura $(find * -type f | fzf --layout=reverse)^M'
bindkey -s '^d' 'cd ~/.dotfiles/links/ && lvim $(find * -type f | fzf --layout=reverse)^M'

# Plugins
zsh_add_plugin "zsh-users/zsh-completions"
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"
source /home/fabian/.dotfiles/zsh/plugins/z/zsh-z.plugin.zsh
source /home/fabian/.config/zsh/plugins/fzf-tab/fzf-tab.plugin.zsh
