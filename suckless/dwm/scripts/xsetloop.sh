dwm_date () {
  echo $(date "+%H:%M")
}

while true
do
  xsetroot -name "$(dwm_date)"
  sleep 5
done
