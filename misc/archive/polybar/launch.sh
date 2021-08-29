#!/usr/bin/env bash

# Terminate already running bar instances
killall -q polybar

# Launch Bar
echo "---" | tee -a /tmp/polybar1.log /tmp/polybar2.log
polybar example 2>&1 | tee -a /tmp/polybar1.log & disown

# Launch Second bar
# polybar (name of second bar)

echo "Bars launched..."
