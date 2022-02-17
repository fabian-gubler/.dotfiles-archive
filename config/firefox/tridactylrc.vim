" Single point of truth
sanitize tridactyllocal tridactylsync

" ---  Global Bindings" -------------------------------------------------------

set tabopenpos related
set hintchars arstneio
set editorcmd st -e lvim
set smoothscroll true
set hintdelay 100
set editorcmd st -e lvim -c 'set filetype=javascript'
colourscheme nord
fixamo_quiet

" Unbind
unbind h
unbind d
unbind D
unbind b
unbind <<
unbind >>


" Navigation
bind <C-d> scrollline 30
bind <C-u> scrollline -30
bind n scrollline 10
bind e scrollline -10
bind i scrollpx 50
bind m scrollpx -50

" Mode ignore
bind <C-y> mode ignore

" Work everywhere

" Hinting
bind s hint
bind S hint -b

" Misc
bind b fillcmdline bmarks

--- Text Input --------------------------------------------------------------

bind --mode=ex     <C-k> text.kill_line
bind --mode=insert <C-k> text.kill_line
bind --mode=input  <C-k> text.kill_line
bind --mode=ex     <C-u> text.backward_kill_line
bind --mode=insert <C-u> text.backward_kill_line
bind --mode=input  <C-u> text.backward_kill_line
bind --mode=insert <A-BS> text.backward_kill_word
bind --mode=input  <A-BS> text.backward_kill_word

" ---  Url Specific Bindings" -------------------------------------------------

" Auto Ignore
blacklistadd calendar.google.com
blacklistadd docs.google.com
blacklistadd mail.protonmail.com
blacklistadd calendar.protonmail.com

" Only hint search results on Google & YouTube
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

" Google Drive
unbindurl drive.google.com j
unbindurl drive.google.com k
unbindurl drive.google.com m

" Google Docs
unbindurl docs.google.com u
