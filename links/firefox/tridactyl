" --------------------------------------------------------------------------------"
" ---  Global Bindings"
" --------------------------------------------------------------------------------"
set tabopenpos related
set hintchars arstneio
set editorcmd st -e lvim

bind d fillcmdline_notrail

" Navigation
bind n scrollline 10
bind <C-d> scrollline 30
bind e scrollline -10
bind <C-u> scrollline -30
bind i scrollpx 50
bind m scrollpx -50

" Mode ignore
bind <C-y> mode ignore

set editorcmd st -e lvim -c 'set filetype=javascript'

" Tabs
bind --mode=browser <A-u> tabopen about:blank
bind --mode=browser <A-v> editor
bind --mode=browser <F2> fullscreen

" Hinting
bind s hint
bind S hint -b

" Unbind
unbind h
unbind <C-b>

" Tools
bind gd open https://drive.google.com/drive/my-drive
bind gc open https://calendar.google.com

" Container
bind c tabopen -c GUBAG

" --------------------------------------------------------------------------------
" --- Text Input
" --------------------------------------------------------------------------------

" Deletion
bind --mode=ex     <C-k> text.kill_line
bind --mode=insert <C-k> text.kill_line
bind --mode=input  <C-k> text.kill_line
bind --mode=ex     <C-u> text.backward_kill_line
bind --mode=insert <C-u> text.backward_kill_line
bind --mode=input  <C-u> text.backward_kill_line

" --------------------------------------------------------------------------------"
" ---  Url Specific Bindings"
" --------------------------------------------------------------------------------"

" Only hint search results on Google 
bindurl www.google.com s hint -Jc #search div:not(.action-menu) > a
bindurl www.google.com S hint -Jbc #search div:not(.action-menu) > a
bindurl www.youtube.com s hint -J
bindurl www.youtube.com S hint -Jb

" YouTube
unbindurl youtube.com j
unbindurl youtube.com l
unbindurl youtube.com k
unbindurl youtube.com f
unbindurl youtube.com p
unbindurl youtube.com c

" Google Calendar
unbindurl calendar.google j
unbindurl calendar.google k
unbindurl calendar.google w

" Google Drive
unbindurl drive.google.com j
unbindurl drive.google.com k
unbindurl drive.google.com m

" Google Docs
unbindurl docs.google.com u

" Blacklist
blacklistadd calendar.google.com

" --------------------------------------------------------------------------------
" --- Alias
" --------------------------------------------------------------------------------

" Maintenance
command fullclean sanitise tridactyllocal tridactylsync

" Mozilla Pages
command preferences tabopen about:preferences
command config tabopen about:config
command addons tabopen about:addons
command newtab tabopen about:blank
command debugging tabopen about:debugging

" Extension Preferences
command sideberry tabopen moz-extension://3061008f-8326-4efe-a177-996dd394b96a/settings/settings.html

" Search Engine
command google open search
command Google tabopen search
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
