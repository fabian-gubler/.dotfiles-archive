local map = vim.api.nvim_set_keymap

map('n', 'q', ':q<cr>', {})
map('n', '<leader>a', '<cmd>lua require("Comment").toggle()<CR>', {})
map('v', '<leader>a', '<ESC><CMD>lua ___comment_gc(vim.fn.visualmode())<CR>', {})
