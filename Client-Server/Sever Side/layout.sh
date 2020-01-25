#!/bin/bash
# tmuc by defualt open a server that store sessions
# -L ashu will connect to server using shu socket
# -L ashu attach will reattach session
tmux start-server
#sleep 5
#tmux -L ashu attach
tmux new -s CHAT -d -n  ROOM 
#sleep 5
tmux split-window -h
#sleep 5
tmux resize-pane -L 20
#sleep 5
tmux split-window -v
#sleep 5
tmux resize-pane -D 20
#sleep 5
tmux select-pane -t 1
sleep 1 
tmux send-key "./server" C-m
sleep 1
tmux select-pane -t 2
sleep 1
tmux send-key "./Client localhost  5001" C-m
sleep 2
tmux a -t CHAT
#sleep 2
