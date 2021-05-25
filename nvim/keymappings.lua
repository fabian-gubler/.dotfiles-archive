-- --------------------------------------------------------------------------------
-- --- Custom Mappings 
-- --------------------------------------------------------------------------------

-- --- Global 
vim.cmd([[
    " Remove Highlight with "Esc"
    nnoremap <esc> :noh<return><esc>
]])
-- Disable Arrow Keys
vim.cmd([[
    map <Up> <Nop>
    map <Left> <Nop>
    map <Right> <Nop>
    map <Down> <Nop>
]])

-- Scrolling
vim.api.nvim_set_keymap('n', 'K', '<C-u>', {silent = true})
vim.api.nvim_set_keymap('n', 'J', '<C-d>', {silent = true})

-- Easy Motion
vim.cmd([[
    " Quick Find
    let g:EasyMotion_smartcase = 1
    nmap f <Plug>(easymotion-overwin-f2)

    "Move to Word
    map sw <Plug>(easymotion-bd-w)
    nmap sw <Plug>(easymotion-overwin-w)

    " Move to Line
    map sl <Plug>(easymotion-lineforward)
    map sj <Plug>(easymotion-j)
    map sk <Plug>(easymotion-k)
    map sh <Plug>(easymotion-linebackward)

    " Better Search
    map  S <Plug>(easymotion-sn)
    omap S <Plug>(easymotion-tn)
]])

-- better window movement
vim.api.nvim_set_keymap('n', '<C-h>', '<C-w>h', {silent = true})
vim.api.nvim_set_keymap('n', '<C-j>', '<C-w>j', {silent = true})
vim.api.nvim_set_keymap('n', '<C-k>', '<C-w>k', {silent = true})
vim.api.nvim_set_keymap('n', '<C-l>', '<C-w>l', {silent = true})

-- TODO fix this
-- Terminal window navigation
vim.cmd([[
  tnoremap <C-h> <C-\><C-N><C-w>h
  tnoremap <C-j> <C-\><C-N><C-w>j
  tnoremap <C-k> <C-\><C-N><C-w>k
  tnoremap <C-l> <C-\><C-N><C-w>l
  inoremap <C-h> <C-\><C-N><C-w>h
  inoremap <C-j> <C-\><C-N><C-w>j
  inoremap <C-k> <C-\><C-N><C-w>k
  inoremap <C-l> <C-\><C-N><C-w>l
  tnoremap <Esc> <C-\><C-n>
]])

-- TODO fix this
-- resize with arrows
vim.cmd([[
  nnoremap <silent> <C-Up>    :resize -2<CR>
  nnoremap <silent> <C-Down>  :resize +2<CR>
  nnoremap <silent> <C-Left>  :vertical resize +2<CR>
  nnoremap <silent> <C-Right> :vertical resize -2<CR>

]])

-- better indenting
vim.api.nvim_set_keymap('v', '<', '<gv', {noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '>', '>gv', {noremap = true, silent = true})

-- I hate escape
vim.api.nvim_set_keymap('i', 'jk', '<ESC>', {noremap = true, silent = true})
vim.api.nvim_set_keymap('c', 'jk', '<ESC>', {noremap = true, silent = true})
vim.api.nvim_set_keymap('i', 'kj', '<ESC>', {noremap = true, silent = true})
vim.api.nvim_set_keymap('i', 'jj', '<ESC>', {noremap = true, silent = true})

-- Tab switch buffer
vim.api.nvim_set_keymap('n', '<TAB>', ':bnext<CR>', {noremap = true, silent = true})
vim.api.nvim_set_keymap('n', '<S-TAB>', ':bprevious<CR>', {noremap = true, silent = true})

-- Move selected line / block of text in visual mode
vim.api.nvim_set_keymap('x', 'J', ':move \'>+1<CR>gv-gv', {noremap = true, silent = true})
vim.api.nvim_set_keymap('x', 'K', ':move \'<-2<CR>gv-gv', {noremap = true, silent = true})

-- Better nav for omnicomplete
vim.cmd('inoremap <expr> <c-j> (\"\\<C-n>\")')
vim.cmd('inoremap <expr> <c-k> (\"\\<C-p>\")')
-- vim.cmd('inoremap <expr> <TAB> (\"\\<C-n>\")')
-- vim.cmd('inoremap <expr> <S-TAB> (\"\\<C-p>\")')

-- vim.api.nvim_set_keymap('i', '<C-TAB>', 'compe#complete()', {noremap = true, silent = true, expr = true})

-- vim.cmd([[
-- map p <Plug>(miniyank-autoput)
-- map P <Plug>(miniyank-autoPut)
-- map <leader>n <Plug>(miniyank-cycle)
-- map <leader>N <Plug>(miniyank-cycleback)
-- ]])

