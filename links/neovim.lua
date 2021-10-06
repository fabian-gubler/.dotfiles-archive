-- Local
local o = vim.opt
local g = vim.g
local cmd = vim.cmd
local keymap = vim.api.nvim_set_keymap
local opt = { noremap = true }
local home = os.getenv( "HOME" )

-- Global
g.undotree_WindowLayout = 2
g.auto_save = 1
g.auto_save_silent = 1
g.mapleader = ' '

-- Options
o.undodir = home .. '/.config/lvim/undodir'
o.swapfile = false
o.relativenumber = true
o.ignorecase = true
o.termguicolors = true
o.colorcolumn = "80"

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
  {"lukas-reineke/indent-blankline.nvim"},
  {"cometsong/CommentFrame.vim"},
}

require'colorizer'.setup()

-- Custom Keymappings
keymap('n', '<C-c>', ':split | terminal python3 %<cr>', {})
keymap('n', '<C-s>', ':split | terminal parser %<cr>', {})
keymap('n', '<leader>a', ':CommentToggle<cr>', {})
keymap('v', '<leader>a', ':CommentToggle<cr>', {})
keymap('n', '<leader>u', '<cmd>UndotreeToggle<cr>', {})
keymap('', ',', '<Plug>(easymotion-overwin-f2)', {})
keymap('', '/', '<Plug>(easymotion-sn)', {})
keymap('n', 'q', ':q<cr>', {})
-- Autocommands
cmd 'autocmd CmdlineEnter /,? :set hlsearch'
cmd 'autocmd CmdlineLeave /,? :set nohlsearch'
cmd 'autocmd TermOpen * startinsert'
cmd 'autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"'

-- Lunarvim
lvim.colorscheme = "onedarker"
lvim.format_on_save = false
lvim.lint_on_save = false
lvim.lsp.diagnostics.virtual_text = false
lvim.builtin.dashboard.active = false
lvim.builtin.terminal.active = true
lvim.builtin.nvimtree.side = "left"
lvim.builtin.nvimtree.show_icons.git = 0
lvim.builtin.treesitter.highlight.enabled = true

-- Native
cmd([[
  let bufferline = get(g:, 'bufferline', {})
  let bufferline.auto_hide = v:true
  let bufferline.animation = v:false
  let bufferline.closable = v:false
]])

-- Overwrite Lunarvim Binds
lvim.keys.normal_mode["<S-m>"] = ":BufferPrevious<cr>"
lvim.keys.normal_mode["<S-i>"] = ":BufferNext<cr>"
lvim.keys.normal_mode["<S-l>"] = nil

-- Whichkey
lvim.builtin.which_key.mappings["f"] = {
  "<cmd>Telescope file_browser<cr>", "File browser"
}

lvim.builtin.which_key.mappings["t"] = {
  "<cmd>Telescope find_files<cr>", "Find files"
}

lvim.builtin.which_key.mappings["o"] = {
  name = "Open in",
  t = { ":!typora %<cr>", "Typora" },
  f = { ":!firefox-developer-edition %<cr>", "Firefox" },
}

-- COLEMAK REMAPPING ----------------------------------------------------------

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
keymap('x', 'x', 'd', opt)
keymap('', 'c', 'y', opt)
keymap('', 'v', 'p', opt)
keymap('n', 'C', 'yy', opt)
keymap('x', 'C', 'y', opt)
keymap('', 'V', 'P', opt)

-- undo / redo
keymap('n', 'z', 'u', opt)
keymap('x', 'z', ':<C-U>undo<cr>', opt)
keymap('n', 'Z', '<C-R>', opt)
keymap('x', 'Z', ':<C-U>redo<cr>', opt)

-- Visual mode
keymap('', 'a', 'v', opt)
keymap('', 'A', 'V', opt)

-- Search
keymap('', 'p', 't', opt)
keymap('', 'P', 'T', opt)
keymap('', 'h', ';', opt)
keymap('', 'k', 'n', opt)

-- Inner text objects (dip -> drp)
keymap('o', 'r', 'i', opt)

cmd([[
  " Make insert/add work also in visual line mode
  xnoremap <silent> <expr> s (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
  xnoremap <silent> <expr> S (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
  xnoremap <silent> <expr> t (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
  xnoremap <silent> <expr> T (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
]])
