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
zstyle ':prompt:pure:prompt:*' color "#D8DEE9"
PURE_CMD_MAX_EXEC_TIME=99999999999999

# The following lines were added by compinstall

zstyle ':completion:*' completer _complete _ignored
zstyle :compinstall filename '/home/fabian/.config/zsh/.zshrc'

autoload -Uz compinit
compinit
# End of lines added by compinstall

# Useful Functions
source /home/fabian/.config/zsh/plugins/fzf-tab/fzf-tab.plugin.zsh
source "$ZDOTDIR/zsh-functions"

# Files to source
zsh_add_file "zsh-aliases"


# Plugins
source /home/fabian/.dotfiles/zsh/plugins/z/zsh-z.plugin.zsh
zsh_add_plugin "zsh-users/zsh-completions"
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"


# Keybinds
bindkey -e                        # emacs bindings
bindkey -s '^f' 'ranger^M'        # ranger
bindkey -s '^t' 'exa -a^M'        # extended ls
bindkey -s '^x' '^L'              # clear terminal
bindkey -s '^p' 'ncpamixer^M'     # ncpamixer
bindkey -s '^z' 'lvim $(fzf --layout=reverse)\n'
bindkey "^[[1;5D" backward-word   # ctrl + m
bindkey "^[[1;5C" forward-word    # ctrl + m
bindkey "^[[3~" delete-char
