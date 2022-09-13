" Single point of truth
sanitize tridactyllocal tridactylsync

" ---  Global Settings -------------------------------------------------------

set tabopenpos related
set hintchars arstneio
set smoothscroll true
set hintdelay 100
fixamo_quiet

" Unbind
unbind j
unbind k
unbind h
unbind d
unbind D
unbind b
unbind u
unbind s
unbind S
unbind <
unbind >
unbind a
unbind A

" Navigation
bind <C-d> scrollline 15
bind <C-u> scrollline -15

--- Text Input --------------------------------------------------------------

bind --mode=ex     <C-k> text.kill_line
bind --mode=insert <C-k> text.kill_line
bind --mode=input  <C-k> text.kill_line
bind --mode=ex     <C-u> text.backward_kill_line
bind --mode=insert <C-u> text.backward_kill_line
bind --mode=input  <C-u> text.backward_kill_line

" ---  Url Specific Bindings" -------------------------------------------------

" Auto Ignore
blacklistadd docs.google.com

" Protonmail
unbindurl proton.me t
unbindurl proton.me /

" YouTube
unbindurl youtube.com l
unbindurl youtube.com f
unbindurl youtube.com c
unbindurl youtube.com t

" Coursera
unbindurl coursera.org k
unbindurl coursera.org f
