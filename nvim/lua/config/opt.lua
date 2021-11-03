local o = vim.opt
local g = vim.g
local home = os.getenv( "HOME" )

-- Global
g.undotree_WindowLayout = 2
g.auto_save = 1
g.auto_save_silent = 1
g.mapleader = ' '
g.EasyMotion_keys='arstdhneioqwfpluygmbjzxcvk1234567890,'

-- Options
o.relativenumber = true
o.swapfile = false
o.ignorecase = true
o.termguicolors = true
o.hidden = true
o.smartcase = true
o.undodir = home .. '/.local/share/nvim/undodir'
o.colorcolumn = "80"
o.clipboard = "unnamedplus"
o.undofile = true
o.smartindent = true
o.wrap = false

-- Don't know yet
local indent = 4

o.shiftwidth = indent
o.tabstop = indent
o.softtabstop = indent
o.expandtab = false
