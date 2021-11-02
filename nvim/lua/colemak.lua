local cmd = vim.cmd
local keymap = vim.api.nvim_set_keymap
local opt = { noremap = true }

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

-- Upper / Lowercase in Visual Mode
keymap('v', 'b', 'u', opt)
keymap('v', 'B', 'U', opt)

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

-- folding
keymap('', 'b', 'z', opt)

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

-- No Idea how this works
cmd([[
  " Make insert/add work also in visual line mode
  xnoremap <silent> <expr> s (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
  xnoremap <silent> <expr> S (mode() =~# "[V]" ? "\<C-V>0o$I" : "I")
  xnoremap <silent> <expr> t (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
  xnoremap <silent> <expr> T (mode() =~# "[V]" ? "\<C-V>0o$A" : "A")
]])
