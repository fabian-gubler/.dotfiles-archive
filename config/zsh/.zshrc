# General
HISTFILE=~/.dotfiles/config/zsh/.histfile
HISTSIZE=10000
SAVEHIST=10000
export MANPAGER='nvim +Man!'


# if [ -n "${NVIM_LISTEN_ADDRESS+x}" ]; then
#   export MANPAGER="/home/fabian/.local/bin/nvr -c 'Man!' -o -"
# fi


# Pure Prompt
fpath+=$HOME/.dotfiles/config/zsh/pure
zstyle :compinstall filename '/home/fabian/.dotfiles/config/zsh/.zshrc'
autoload -U promptinit; promptinit
prompt pure
zstyle ':prompt:pure:prompt:*' color "#D8DEE9"
PURE_PROMPT_SYMBOL="❯"
PURE_CMD_MAX_EXEC_TIME=99999999999999

# Completion
zstyle ':completion:*' completer _complete _ignored
zstyle :compinstall filename '/home/fabian/.dotfiles/config/zsh/.zshrc'
autoload -Uz compinit
compinit

# Files to source
source "$ZDOTDIR/functions"
zsh_add_file "alias"

# Keybinds
bindkey -e                        # emacs bindings
bindkey -s '^f' 'ranger^M'        # ranger
bindkey -s '^t' 'exa -a^M'        # extended ls
bindkey "^[[1;5D" backward-word   # ctrl + m
bindkey "^[[1;5C" forward-word    # ctrl + i
bindkey "^[[3~" delete-char       # make delete work


# Plugins
zsh_add_plugin "zsh-users/zsh-completions"
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"
zsh_add_plugin "Aloxaf/fzf-tab"
zsh_add_plugin "agkozak/zsh-z"

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/home/fabian/miniconda3/bin/conda' 'shell.zsh' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/home/fabian/miniconda3/etc/profile.d/conda.sh" ]; then
        . "/home/fabian/miniconda3/etc/profile.d/conda.sh"
    else
        export PATH="/home/fabian/miniconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

