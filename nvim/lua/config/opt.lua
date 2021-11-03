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
o.ignorecase = true
o.termguicolors = true
o.undodir = home .. '/.config/lvim/undodir'
o.clipboard = "unnamedplus"
