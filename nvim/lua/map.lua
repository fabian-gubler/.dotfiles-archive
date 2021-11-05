local map = vim.api.nvim_set_keymap
local opt = { noremap = true }

-- Custom
map('n', 'q', ':q<cr>', opt)

-- Plugins
map('', ',', '<Plug>(easymotion-s)', {})
map('', '/', '<Plug>(easymotion-sn)', {})

-- Migrate to Whichkey
map('n', '<leader>e', ':NvimTreeToggle<CR>', {})
map('n', '<leader>t', ':Telescope find_files<CR>', {})
map('n', '<leader>a', '<cmd>lua require("Comment").toggle()<CR>', {})
map('v', '<leader>a', '<ESC><CMD>lua ___comment_gc(vim.fn.visualmode())<CR>', {})
