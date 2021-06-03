" --------------------------------------------------------------------------------"
" ---  Global Bindings"
" --------------------------------------------------------------------------------"
" Navigation
bind j scrollline 4
bind J scrollline 15
bind k scrollline -4
bind K scrollline -15
bind f fullscreen

" Tabs
bind n newtab
bind q composite newtab | tabclosealltoleft

" Hinting
bind s hint
bind S hint -b

" Unbind
unbind <C-b>
unbind d

" Tools
bind <A-t> tabopen about:downloads
bind m hint -qW mpvsafe
bind dd open https://drive.google.com/drive/starred
bind dc open https://calendar.google.com

" Container
bind c composite tabopen -c GUBAG | fillcmdline open

" --------------------------------------------------------------------------------"
" ---  Url Specific Bindings"
" --------------------------------------------------------------------------------"

" Only hint search results on Google 
bindurl www.google.com s hint -Jc #search div:not(.action-menu) > a
bindurl www.google.com S hint -Jbc #search div:not(.action-menu) > a
bindurl www.youtube.com s hint -J
bindurl www.youtube.com S hint -Jb

" YouTube
unbindurl youtube.com k
unbindurl youtube.com f

" Google Calendar
unbindurl calendar.google j
unbindurl calendar.google k
unbindurl calendar.google w

" Google Drive
unbindurl drive.google.com j
unbindurl drive.google.com k

# --------------------------------------------------------------------------------
# --- Alias
# --------------------------------------------------------------------------------

" Mozilla Pages
command preferences tabopen about:preferences
command conf tabopen about:config
command addon tabopen about:addons
command newtab tabopen about:blank
command sideberry tabopen moz-extension://3061008f-8326-4efe-a177-996dd394b96a/settings/settings.html

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

" Colourscheme
colourscheme nord






