# general
DOTDIR=$HOME/.dotfiles/config/zsh
HISTFILE=$DOTDIR/.histfile
HISTSIZE=10000
SAVEHIST=10000
export MANPAGER='nvim +Man!'

# pure prompt
fpath+=$DOTDIR/pure
autoload -U promptinit; promptinit
prompt pure
zstyle ':prompt:pure:prompt:*' color "#D8DEE9"
PURE_PROMPT_SYMBOL="❯"
# PURE_PROMPT_SYMBOL="➜"
PURE_CMD_MAX_EXEC_TIME=99999999999999

# completion
zstyle :compinstall filename '$DOTDIR/.zshrc'
zstyle ':completion:*' completer _complete _ignored
autoload -Uz compinit
compinit

# files to source
source "$ZDOTDIR/functions"
zsh_add_file "alias"

# follow dirs
source ~/.config/lf/lfcd.sh

# nix package manager
source $HOME/.nix-profile/etc/profile.d/nix.sh

# keybinds
bindkey -e                        # emacs bindings
# bindkey -s '^f' 'lfcd^M'        # ranger
bindkey -s '^f' 'lfcd\n'  # zsh
bindkey -s '^t' 'exa -a^M'        # extended ls

bindkey "^[[3~" delete-char       # make delete work
bindkey "^[[1~" beginning-of-line # home
bindkey "^[[4~" end-of-line		  # end

# plugins
zsh_add_plugin "zsh-users/zsh-completions"
zsh_add_plugin "zsh-users/zsh-autosuggestions"
zsh_add_plugin "zsh-users/zsh-syntax-highlighting"
zsh_add_plugin "hlissner/zsh-autopair"
zsh_add_plugin "Aloxaf/fzf-tab"

# should be automated
source $DOTDIR/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source $DOTDIR/plugins/zsh-autopair/autopair.zsh


# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/usr/bin/conda' 'shell.zsh' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/usr/etc/profile.d/conda.sh" ]; then
        . "/usr/etc/profile.d/conda.sh"
    else
        export PATH="/usr/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

