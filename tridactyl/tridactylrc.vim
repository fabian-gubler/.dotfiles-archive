" --------------------------------------------------------------------------------"
" ---  Appearance"
" --------------------------------------------------------------------------------"
colourscheme nord

" --------------------------------------------------------------------------------"
" ---  Bindurl"
" --------------------------------------------------------------------------------"
" Only hint search results on Google 
bindurl www.google.com s hint -Jc #search div:not(.action-menu) > a
bindurl www.google.com S hint -Jbc #search div:not(.action-menu) > a

" --------------------------------------------------------------------------------"
" ---  Misc Settings"
" --------------------------------------------------------------------------------"
" Defaults to 300ms but I'm a 'move fast and close the wrong tabs' kinda chap
set hintdelay 100

" Make Tridactyl work on more sites at the expense of some security. For
" details, read the comment at the top of this file.
fixamo_quiet

" --------------------------------------------------------------------------------"
" ---  Unbind Url"
" --------------------------------------------------------------------------------"
unbindurl youtube.com/watch k
