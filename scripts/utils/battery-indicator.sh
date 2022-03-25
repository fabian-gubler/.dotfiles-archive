#!/bin/sh
STATUS=$(acpi -b)
BATT=$(cat /sys/class/power_supply/BAT0/capacity)
TEXT="Discharging"

while true
 do
	# # if [ "$BATT" -gt 30 ]
	# if [ "$STATUS" == *"$TEXT"* ]
	# then
	# 	# xsetroot -name " "
	# 	echo "discharging"
	# else
	# 	# xsetroot -name "$BATT% "
	# 	echo "charging"
	# fi
	case $TEXT in

	  *"$STATUS"*)
		echo -n "String is there."
		;;
	esac
    sleep [10]
 done

