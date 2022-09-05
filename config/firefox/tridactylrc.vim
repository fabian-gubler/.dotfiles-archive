" Single point of truth
sanitize tridactyllocal tridactylsync

" ---  Global Settings -------------------------------------------------------

set tabopenpos related
set hintchars arstneio
set smoothscroll true
set hintdelay 100
colourscheme nord
fixamo_quiet

" Unbind
unbind h
unbind d
unbind D
unbind b
unbind u
unbind s
unbind S
unbind <<
unbind >>

" Navigation
bind <C-d> scrollline 30
bind <C-u> scrollline -30

" Mode ignore
bind <C-y> mode ignore

--- Text Input --------------------------------------------------------------

bind --mode=ex     <C-k> text.kill_line
bind --mode=insert <C-k> text.kill_line
bind --mode=input  <C-k> text.kill_line
bind --mode=ex     <C-u> text.backward_kill_line
bind --mode=insert <C-u> text.backward_kill_line
bind --mode=input  <C-u> text.backward_kill_line

" ---  Url Specific Bindings" -------------------------------------------------

" Auto Ignore
blacklistadd calendar.google.com
blacklistadd docs.google.com
blacklistadd mail.protonmail.com
blacklistadd calendar.protonmail.com

" Only hint search results on Google
bindurl www.google.com s hint -Jc #search div:not(.action-menu) > a
bindurl www.google.com S hint -Jbc #search div:not(.action-menu) > a

" YouTube
unbindurl youtube.com j
unbindurl youtube.com l
unbindurl youtube.com k
unbindurl youtube.com f
unbindurl youtube.com p
unbindurl youtube.com c

" Coursera
unbindurl coursera.org k
unbindurl coursera.org f
