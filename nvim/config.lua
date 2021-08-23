-- Variables
local o = vim.opt
local g = vim.g
local home = os.getenv( "HOME" )
g.mapleader = ' '

-- General
lvim.format_on_save = true
lvim.lint_on_save = true
lvim.colorscheme = "nord"

-- Helper Function
local function map(mode, lhs, rhs, opts)
    local options = {noremap = true, silent = true}
    if opts then options = vim.tbl_extend('force', options, opts) end
    vim.api.nvim_set_keymap(mode, lhs, rhs, options)
end

-- Additional Plugins
lvim.plugins = {
    {"907th/vim-auto-save"},
    {"shaunsingh/nord.nvim"},
    {"psliwka/vim-smoothie"},
    {"easymotion/vim-easymotion"},
    {"mbbill/undotree"}
}

-- Undodir
g.undotree_WindowLayout = 2


-- Additional Leader bindings for WhichKey
lvim.builtin.which_key.mappings["a"] = { 
  "<cmd>CommentToggle<cr>","Comment"
}

-- Options
o.undodir = home .. '/.config/lvim/undodir'

-- Custom Keymappings
map('n', '<leader>u', '<cmd>UndotreeToggle<cr>')

-- Native Keymappings
vim.cmd([[
    autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"
    nnoremap <esc> :noh<return><esc>
    map <Up> <C-u>
    map <C-a> ggaG
    map <C-s> :TermExec cmd='python %' <CR>
    map <Down> <C-d>
    map  / <Plug>(easymotion-sn)
    omap / <Plug>(easymotion-tn)
    set noswapfile
    set relativenumber
    set ignorecase
    set wrap
    let g:auto_save = 1  " enable AutoSave on Vim startup
    let g:auto_save_silent = 1  " do not display the auto-save notification
    let bufferline = get(g:, 'bufferline', {})
    let bufferline.auto_hide = v:true
    let bufferline.animation = v:false
    let bufferline.closable = v:false
]])

lvim.builtin.dashboard.active = false
lvim.builtin.terminal.active = true
lvim.builtin.nvimtree.side = "left"
lvim.builtin.nvimtree.show_icons.git = 0

-- if you don't want all the parsers change this to a table of the ones you want
lvim.builtin.treesitter.ensure_installed = {}
lvim.builtin.treesitter.ignore_install = { "haskell" }
lvim.builtin.treesitter.highlight.enabled = true

-- Colemak
vim.cmd([[
  " Up/down/left/right {{{
      nnoremap m h|xnoremap m h|onoremap m h|
      nnoremap n j|xnoremap n j|onoremap n j|
      nnoremap e k|xnoremap e k|onoremap e k|
      nnoremap i l|xnoremap i l|onoremap i l|
  " }}}
  " Words forward/backward {{{
      " l/L = back word/WORD
      " u/U = end of word/WORD
      " y/Y = forward word/WORD
      nnoremap l b|xnoremap l b|onoremap l b|
      nnoremap L B|xnoremap L B|onoremap L B|
      nnoremap u e|xnoremap u e|onoremap u e|
      nnoremap U E|xnoremap U E|onoremap U E|
      nnoremap y w|xnoremap y w|onoremap y w|
      nnoremap Y W|xnoremap Y W|onoremap Y W|
      cnoremap <C-L> <C-Left>
      cnoremap <C-Y> <C-Right>
  " }}}
  " inSert/Replace/append (T) {{{
      nnoremap s i|
      nnoremap S I|
      nnoremap t a|
      nnoremap T A|
  " }}}
  " Change {{{
      nnoremap w c|xnoremap w c|
      nnoremap W C|xnoremap W C|
      nnoremap ww cc|
  " }}}
  " Cut/copy/paste {{{
      nnoremap x x|xnoremap x d|
      nnoremap c y|xnoremap c y|
      nnoremap v p|xnoremap v p|
      nnoremap X dd|xnoremap X d|
      nnoremap C yy|xnoremap C y|
      nnoremap V P|xnoremap V P|
      nnoremap gv gp|xnoremap gv gp|
      nnoremap gV gP|xnoremap gV gP|
  " }}}
  " Undo/redo {{{
      nnoremap z u|xnoremap z :<C-U>undo<CR>|
      nnoremap gz U|xnoremap gz :<C-U>undo<CR>|
      nnoremap Z <C-R>|xnoremap Z :<C-U>redo<CR>|
  " }}}
  " Visual mode {{{
      nnoremap a v|xnoremap a v|
      nnoremap A V|xnoremap A V|
      nnoremap ga gv
      " Make insert/add work also in visual line mode like in visual block mode
      xnoremap <silent> <expr> s (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
      xnoremap <silent> <expr> S (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
      xnoremap <silent> <expr> t (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
      xnoremap <silent> <expr> T (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
  " }}}
  " Search {{{
      " f/F are unchanged
      nnoremap b t|xnoremap b t|onoremap b t|
      nnoremap B T|xnoremap B T|onoremap B T|
      nnoremap p ;|xnoremap p ;|onoremap b ;|
      nnoremap P ,|xnoremap P ,|onoremap P ,|
      nnoremap k n|xnoremap k n|onoremap k n|
      nnoremap K N|xnoremap K N|onoremap K N|
  " }}}
  " inneR text objects {{{
      " E.g. dip (delete inner paragraph) is now drp
      onoremap r i
  " }}}
  " Folds, etc. {{{
      nnoremap j z|xnoremap j z|
      nnoremap jn zj|xnoremap jn zj|
      nnoremap je zk|xnoremap je zk|
  " }}}
  " Overridden keys must be prefixed with g {{{
      nnoremap gX X|xnoremap gX X|
      nnoremap gK K|xnoremap gK K|
      nnoremap gL L|xnoremap gL L|
  " }}}
  " Window handling {{{
      nnoremap <C-W>h <C-W>h|xnoremap <C-W>h <C-W>h|
      nnoremap <C-W>n <C-W>j|xnoremap <C-W>n <C-W>j|
      nnoremap <C-W>e <C-W>k|xnoremap <C-W>e <C-W>k|
      nnoremap <C-W>i <C-W>l|xnoremap <C-W>i <C-W>l|
  " }}}
]])
