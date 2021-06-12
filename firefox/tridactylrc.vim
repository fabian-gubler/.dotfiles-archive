" --------------------------------------------------------------------------------"
" ---  Global Bindings"
" --------------------------------------------------------------------------------"
set newtab about:blank
bind d fillcmdline_notrail

" Navigation
bind j scrollline 4
bind <ArrowDown> scrollline 15
bind k scrollline -4
bind <ArrowUp> scrollline -15
bind f fullscreen

" Tabs
bind n newtab
bind --mode=browser <A-2> newtab
bind --mode=browser <A-1> composite newtab | tabclosealltoleft 

" Search
bind b fillcmdline google
bind B fillcmdline Google

" Hinting
bind s hint
bind S hint -b

" Unbind
unbind <C-b>
unbind <C-d>
unbind <C-u>
unbind J
unbind K

" Tools
bind <A-t> tabopen about:downloads
bind m hint -qW mpvsafe
bind gd open https://drive.google.com/drive/starred
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
" --------------------------------------------------------------------------------
" --- Alias
" --------------------------------------------------------------------------------

" Maintenance
command fullclean sanitise tridactyllocal tridactylsync

" Mozilla Pages
command settings tabopen about:preferences
command config tabopen about:config
command addon tabopen about:addons
command newtab tabopen about:blank

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






