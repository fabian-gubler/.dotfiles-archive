#! /bin/bash
session="neuron"
tmux new-session -d -s $session

# Compile Neuron Output
window=1
tmux rename-window -t $session:$window 'compiler'
tmux send-keys -t $session:$window 'cd ~/notes && neuron gen -wS' C-m

# Start Live Server
window=2
tmux new-window -t $session:$window -n 'server'
tmux send-keys -t $session:$window 'cd ~/notes/.neuron/output && live-server --port=4000' C-m
