local o = vim.opt
local g = vim.g
local home = os.getenv( "HOME" )
local cmd = vim.cmd

-- Global
g.nvim_tree_quit_on_open = 1 
g.undotree_WindowLayout = 2
g.auto_save = 1
g.auto_save_silent = 1
g.EasyMotion_keys='arstdhneioqwfpluygmbjzxcvk1234567890,'
g.nord_borders = 'true'

-- Options
o.relativenumber = true
o.showmode = false
o.cursorline = false
o.swapfile = false
o.splitbelow = true
o.splitright = true
o.ignorecase = true
o.termguicolors = true
o.smartcase = true
o.undodir = home .. '/.local/share/nvim/undodir'
o.undofile = true
o.clipboard = "unnamedplus"
o.smartindent = true
o.wrap = false
-- o.colorcolumn = "80"
o.timeoutlen = 500

-- Don't know yet
local indent = 4

o.shiftwidth = indent
o.tabstop = indent
o.softtabstop = indent
o.expandtab = false
o.hidden = true

-- Autocommands
cmd 'autocmd VimEnter * setlocal formatoptions-=c formatoptions-=r formatoptions-=o'
cmd 'autocmd CmdlineEnter /,? :set hlsearch'
cmd 'autocmd CmdlineLeave /,? :set nohlsearch'
