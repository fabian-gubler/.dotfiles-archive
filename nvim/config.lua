-- Variables
local o = vim.opt
local g = vim.g
local cmd = vim.cmd
local keymap = vim.api.nvim_set_keymap
local home = os.getenv( "HOME" )

-- Set Additional Runtime Path
o.rtp:append(home .. "/.dotfiles/nvim")

-- Options
o.undodir = home .. '/.config/lvim/undodir'
o.swapfile = false
o.relativenumber = true
o.ignorecase = true
o.termguicolors = true
o.colorcolumn = "80"

-- Global
g.undotree_WindowLayout = 2
g.auto_save = 1
g.auto_save_silent = 1
g.mapleader = ' '
g.EasyMotion_keys='arstdhneioqwfpluygmbjzxcvk1234567890,'

-- Plugins
lvim.plugins = {
  {"907th/vim-auto-save"},
  {"karb94/neoscroll.nvim"},
  {"easymotion/vim-easymotion"},
  {"mbbill/undotree"},
  {"norcalli/nvim-colorizer.lua"},
  {"KabbAmine/zeavim.vim"},
  {"lukas-reineke/indent-blankline.nvim"},
  {"shaunsingh/nord.nvim"}
}

require'colorizer'.setup()
require('neoscroll').setup()

-- Lunarvim
lvim.colorscheme = "nord"
lvim.format_on_save = false
lvim.lint_on_save = false
lvim.lsp.diagnostics.virtual_text = false
lvim.builtin.dashboard.active = false
lvim.builtin.nvimtree.active = false
lvim.builtin.terminal.active = true
lvim.builtin.treesitter.highlight.enabled = true
lvim.builtin.treesitter.ensure_installed = "maintained"
lvim.builtin.treesitter.indent.disable["1"] = "python"
lvim.builtin.treesitter.indent.enable = true
lvim.builtin.cmp.mapping["<Tab>"] = nil
lvim.builtin.cmp.mapping["<S-Tab>"] = nil
lvim.builtin.cmp.experimental.ghost_text = false

-- Keymappings
keymap('n', '<leader>u', '<cmd>UndotreeToggle<cr>', {})
keymap('n', '<leader>a', '<cmd>lua require("Comment").toggle()<CR>', {})
keymap('v', '<leader>a', '<ESC><CMD>lua ___comment_gc(vim.fn.visualmode())<CR>', {})
keymap('', ',', '<Plug>(easymotion-s)', {})
keymap('', '/', '<Plug>(easymotion-sn)', {})
keymap('n', 'q', ':q<cr>', {})

-- Autocommands
cmd 'autocmd CmdlineEnter /,? :set hlsearch'
cmd 'autocmd CmdlineLeave /,? :set nohlsearch'
cmd 'autocmd TermOpen * startinsert'
cmd 'autocmd VimEnter * :silent exec "!kill -s SIGWINCH $PPID"'

-- Native
cmd([[
  let bufferline = get(g:, 'bufferline', {})
  let bufferline.auto_hide = v:true
  let bufferline.animation = v:false
  let bufferline.closable = v:false
]])

-- Files shared with Nvim Configuration
require('colemak') -- Sourced from dotfiles

-- Overwrite Lunarvim Binds
lvim.keys.normal_mode["<S-m>"] = ":BufferPrevious<cr>"
lvim.keys.normal_mode["<S-i>"] = ":BufferNext<cr>"
lvim.keys.normal_mode["<S-l>"] = nil

-- Whichkey
lvim.builtin.which_key.mappings["f"] = {
  "<cmd>Telescope file_browser<cr>", "File browser"
}

lvim.builtin.which_key.mappings["r"] = {
  ":split | terminal python3 %<cr>", "Run Python"
}

lvim.builtin.which_key.mappings["y"] = {
  ":%y+<cr>", "Yank to Clipboard"
}

lvim.builtin.which_key.mappings["t"] = {
  "<cmd>Telescope find_files<cr>", "Find files"
}

lvim.builtin.which_key.mappings["o"] = {
  name = "Open in",
  t = { ":!typora %<cr>", "Typora" },
  f = { ":!firefox %<cr>", "Firefox" },
  s = { ":terminal live-server<cr>", "Server" },
}

-- nvim.cmp binding for autocomplete
  -- Make update independent
      -- ["<Right>"] = cmp.mapping(function(fallback)
      --   if cmp.visible() then
      --     cmp.select_next_item()
      --     cmp.complete()
      --   else
      --     fallback()
      --   end
      -- end, {
      --   "i",
      --   "s",
      -- }),
