#!/bin/sh
BATT=$(cat /sys/class/power_supply/BAT0/capacity)
SUBSTR='Discharging'

while true
 do

	# battery state
	OUTPUT=$(acpi -b)

	# check whether discharging
	case $OUTPUT in

		*"$SUBSTR"*)
		# print battery level
		xsetroot -name "$BATT% "
		sleep 1
		continue
		;;
	esac

	# print nothing if charging
	xsetroot -name " "
    sleep 1
 done

