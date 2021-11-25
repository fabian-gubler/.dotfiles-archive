#! /bin/bash
session="server"
cwd=$(pwd)
tmux new-session -d -s $session

window=1
tmux rename-window -t $session:$window 'live-server'
tmux send-keys -t $session:$window "cd $cwd" C-m C-l
tmux send-keys -t $session:$window 'live-server' C-m

window=2
tmux new-window -t $session:$window -n 'scss'
tmux send-keys -t $session:$window "cd $cwd" C-m C-l
tmux send-keys -t $session:$window 'scss --watch style.scss' C-m
