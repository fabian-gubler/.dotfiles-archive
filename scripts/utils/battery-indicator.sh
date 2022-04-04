#!/bin/bash

while true
 do

	# battery level
	BATT=$(cat /sys/class/power_supply/BAT0/capacity)

	# battery state
	STATUS=$(cat /sys/class/power_supply/BAT0/status)

	# check whether discharging
	if [[ $STATUS = "Discharging" ]]
	then
		# print battery level
		xsetroot -name "$BATT% "
		sleep 1
		continue
	fi

	# print nothing if charging
	xsetroot -name " "
    sleep 1
 done

