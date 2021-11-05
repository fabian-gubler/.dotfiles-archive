local map = vim.api.nvim_set_keymap
local opt = { noremap = true }

map('n', 'q', ':q<cr>', opt)

-- Plugins
-- map('n', '<leader>d', ':lua vim.lsp.diagnostic.show_line_diagnostics()<CR>', opt)
map('n', '<leader>e', ':NvimTreeToggle<CR>', {})
map('n', '<leader>t', ':Telescope find_files<CR>', opt)
map('n', '<leader>a', '<cmd>lua require("Comment").toggle()<CR>', {})
map('v', '<leader>a', '<ESC><CMD>lua ___comment_gc(vim.fn.visualmode())<CR>', {})
map('', ',', '<Plug>(easymotion-s)', {})
map('', '/', '<Plug>(easymotion-sn)', {})
