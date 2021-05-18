# This is obsolete

let mapleader=" "


call plug#begin(expand('~/.vim/plugged'))
Plug 'arcticicestudio/nord-vim'
Plug '907th/vim-auto-save'
Plug 'tpope/vim-commentary'
Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'
call plug#end()

autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"
set noswapfile
colorscheme nord

let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"
let g:UltiSnipsEditSplit="vertical"

