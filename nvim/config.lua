-- Variables
local o = vim.opt
local g = vim.g
local keymap = vim.api.nvim_set_keymap
local opt = { noremap = true }
local home = os.getenv( "HOME" )
local cmd = vim.cmd
g.mapleader = ' '

-- Options
o.undodir = home .. '/.config/lvim/undodir'
o.swapfile = false
o.relativenumber = true
o.ignorecase = true
o.termguicolors = true

-- Global
g.undotree_WindowLayout = 2
g.auto_save = 1
g.auto_save_silent = 1

-- Autocommands
cmd 'autocmd CmdlineEnter /,? :set hlsearch'
cmd 'autocmd CmdlineLeave /,? :set nohlsearch'

-- Lunarvim
lvim.format_on_save = false
lvim.lint_on_save = false
lvim.lsp.diagnostics.virtual_text = false
lvim.colorscheme = "onedarker"

-- Additional Plugins
lvim.plugins = {
    {"907th/vim-auto-save"},
    {"shaunsingh/nord.nvim"},
    {"psliwka/vim-smoothie"},
    {"easymotion/vim-easymotion"},
    {"mbbill/undotree"},
    {"francoiscabrol/ranger.vim"},
    {"rbgrouleff/bclose.vim"},
    {"norcalli/nvim-colorizer.lua"},
}

-- Custom Keymappings
keymap('n', '<C-c>', ':split | terminal javac % && java %<cr>', {})
keymap('n', '<leader>a', ':CommentToggle<cr>', {})
keymap('v', '<leader>a', ':CommentToggle<cr>', {})
keymap('n', '<C-s>', ':split | terminal parser %<cr>', {})
keymap('n', '<leader>x', '<cmd>bd!<cr>', {})
keymap('n', '<leader>u', '<cmd>UndotreeToggle<cr>', {})
keymap('', ',', '<Plug>(easymotion-overwin-f2)', {})
keymap('', '/', '<Plug>(easymotion-sn)', {})
keymap('n', 'q', ':q<cr>', {})

-- Native
vim.cmd([[
    autocmd TermOpen * startinsert
    autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"
    let bufferline = get(g:, 'bufferline', {})
    let bufferline.auto_hide = v:true
    let bufferline.animation = v:false
    let bufferline.closable = v:false
]])

-- Overwrite Lunarvim Binds
lvim.keys.normal_mode["<S-m>"] = ":BufferPrevious<CR>"
lvim.keys.normal_mode["<S-i>"] = ":BufferNext<CR>"
lvim.keys.normal_mode["<S-l>"] = nil

-- Additional Leader bindings for WhichKey
-- lvim.builtin.which_key.mappings["a"] = {
--   "<cmd>CommentToggle<cr>","Comment"
-- }

-- Lunarvim
lvim.builtin.dashboard.active = false
lvim.builtin.terminal.active = true
lvim.builtin.nvimtree.side = "left"
lvim.builtin.nvimtree.show_icons.git = 0
lvim.builtin.treesitter.highlight.enabled = true

-- Colemak

-- left, right, down, up
keymap('', 'm', 'h', opt)
keymap('', 'n', 'j', opt)
keymap('', 'e', 'k', opt)
keymap('', 'i', 'l', opt)

-- l/L = back word/WORD
keymap('', 'l', 'b', opt)
keymap('', 'L', 'B', opt)

-- u/U = end of word/WORD
keymap('', 'u', 'e', opt)
keymap('', 'U', 'E', opt)

-- y/Y = forward word/WORD
keymap('', 'y', 'w', opt)
keymap('', 'Y', 'W', opt)

-- insert, append, change
keymap('n', 's', 'i', opt)
keymap('n', 'S', 'I', opt)
keymap('n', 't', 'a', opt)
keymap('n', 'T', 'A', opt)
keymap('n', 'w', 'c', opt)
keymap('x', 'w', 'c', opt)
keymap('n', 'ww', 'cc', opt)

-- cut, copy, paste
vim.cmd([[
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
