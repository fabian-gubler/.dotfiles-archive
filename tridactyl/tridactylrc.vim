" --------------------------------------------------------------------------------"
" ---  Appearance"
" --------------------------------------------------------------------------------"
colourscheme nord

" --------------------------------------------------------------------------------"
" ---  Bindings"
" --------------------------------------------------------------------------------"
" Navigation
bind j scrollline 4
bind J scrollline 15
bind k scrollline -4
bind K scrollline -15
bind f fullscreen

" Hinting
bind s hint
bind S hint -b

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

" Smoothscroll
set smoothscroll true

" --------------------------------------------------------------------------------"
" ---  Unbind Key"
" --------------------------------------------------------------------------------"
unbind <C-b>




" --------------------------------------------------------------------------------"
" ---  Unbind Url"
" --------------------------------------------------------------------------------"
" YouTube
unbindurl youtube.com/watch k

" Google Calendar
unbindurl calendar.google/ j
unbindurl calendar.google/ k
unbindurl calendar.google/ w


# --------------------------------------------------------------------------------
# --- Alias
# --------------------------------------------------------------------------------
command pref tabopen about:preferences
command conf tabopen about:config
command addon tabopen about:addons
