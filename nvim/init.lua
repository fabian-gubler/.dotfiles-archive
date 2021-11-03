local cmd = vim.cmd
cmd 'colorscheme nord'

require('config.colemak')
require('config.opt')
require('config.map')

-- Install packer
local install_path = vim.fn.stdpath 'data' .. '/site/pack/packer/start/packer.nvim'

if vim.fn.empty(vim.fn.glob(install_path)) > 0 then
  vim.fn.execute('!git clone https://github.com/wbthomason/packer.nvim ' .. install_path)
end

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'

  -- Plugins
	-- Autopairs
  use 'shaunsingh/nord.nvim'
  use '907th/vim-auto-save'
  use 'easymotion/vim-easymotion'
  use 'mbbill/undotree'
  use 'lukas-reineke/indent-blankline.nvim'

  -- Plugins with Config
  use {
    'norcalli/nvim-colorizer.lua',
    config = function()
        require('colorizer').setup()
    end
}

  use {
    'karb94/neoscroll.nvim',
    config = function()
        require('neoscroll').setup()
    end
}

  use {
    'numToStr/Comment.nvim',
    config = function()
        require('Comment').setup()
    end
}

  use {
    'akinsho/toggleterm.nvim',
    config = function()
        require('toggleterm').setup{
            open_mapping = [[<c-t>]],
	}
    end
}

end)
