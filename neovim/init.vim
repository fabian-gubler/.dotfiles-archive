call plug#begin(expand('~/.vim/plugged'))
Plug 'arcticicestudio/nord-vim'
call plug#end()

autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"
colorscheme nord
