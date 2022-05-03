#!/bin/bash

# Description:
# script that sends a notification
# when battery is below 10%

# Dependencies: 
# - dunst
# - acpi


while true
do
    battery_level=`acpi -b | grep -P -o '[0-9]+(?=%)'`
    if [ $battery_level -le 40 ]; then
       dunstify "Battery low" "${battery_level}%"    
    fi

    sleep 300 # 300 seconds or 5 minutes
done

