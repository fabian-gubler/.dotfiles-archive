# general
HISTFILE=$HOME/.dotfiles/config/zsh/.histfile
HISTSIZE=10000
SAVEHIST=10000
export MANPAGER='nvim +Man!'

# pure prompt
fpath+=$HOME/.dotfiles/config/zsh/pure
autoload -U promptinit; promptinit
prompt pure
zstyle ':prompt:pure:prompt:*' color "#D8DEE9"
PURE_PROMPT_SYMBOL="❯"
# PURE_PROMPT_SYMBOL="➜"
PURE_CMD_MAX_EXEC_TIME=99999999999999

# completion
zstyle :compinstall filename '/home/fabian/.dotfiles/config/zsh/.zshrc'
zstyle ':completion:*' completer _complete _ignored
zstyle :compinstall filename '/home/fabian/.dotfiles/config/zsh/.zshrc'
autoload -Uz compinit
compinit

# files to source
source "$ZDOTDIR/functions"
zsh_add_file "alias"

# keybinds
bindkey -e                        # emacs bindings
bindkey -s '^f' 'ranger^M'        # ranger
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
zsh_add_plugin "agkozak/zsh-z"

# should be automated
source ~/.dotfiles/config/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source ~/.dotfiles/config/zsh/plugins/zsh-autopair/autopair.zsh
