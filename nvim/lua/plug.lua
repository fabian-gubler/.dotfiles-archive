	-- Install packer
local install_path = vim.fn.stdpath 'data' .. '/site/pack/packer/start/packer.nvim'

if vim.fn.empty(vim.fn.glob(install_path)) > 0 then
  vim.fn.execute('!git clone https://github.com/wbthomason/packer.nvim ' .. install_path)
end

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'

  -- Plugins
    -- Lualine
    -- Telescope
    -- Completion
    -- Lsp
    -- Treesitter

  use 'shaunsingh/nord.nvim'
  use '907th/vim-auto-save'
  use 'easymotion/vim-easymotion'
  use 'lukas-reineke/indent-blankline.nvim'

-- Colorizer
	use {
		'norcalli/nvim-colorizer.lua',
		config = function()
		require('colorizer').setup()
	end
}

-- Statusline
	use {
		'nvim-lualine/lualine.nvim',
		config = function() require('core.lualine') end,
		requires = {'kyazdani42/nvim-web-devicons', opt = true}
}

-- Smooth Scroll
	use {
		'karb94/neoscroll.nvim',
		config = function()
		require('neoscroll').setup({
			mappings = {'<C-u>', '<C-d>', '<C-b>', '<C-f>',
            '<C-y>', '<C-e>'},
		})
    end
}

-- Commenting
	use {
		'numToStr/Comment.nvim',
		config = function()
        require('Comment').setup()
    end
}

-- Autopairs
	use {
	'windwp/nvim-autopairs',
	config = function()
	require('nvim-autopairs').setup()
	end
}

-- Terminal
	use {
		'akinsho/toggleterm.nvim',
		config = function()
        require('toggleterm').setup{
            open_mapping = [[<c-t>]],
			direction = 'float',
			float_opts = {
			  -- border = 'single' | 'double' | 'shadow' | 'curved' | ... other options supported by win open
			  border = "curved",
			  -- width = <value>,
			  -- height = <value>,
			  winblend = 0,
			  highlights = {
				border = "Normal",
				background = "Normal",
			  },
			}
		}
    end
}

end)
