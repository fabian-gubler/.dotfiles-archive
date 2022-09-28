#!/bin/bash

# if [ $# -eq 0 ]
#   then
#     echo "No arguments supplied"
# 	exit
# fi

DIRS="lectures out --sync --delete"
ARGS="--sync --delete --prefix"
HOMEDIR="/home/fabian/nextcloud/mcs/"

select subject in asse hci cyber 
do 
	cd $HOMEDIR/docs/$subject/
	mdankideck $DIRS $ARGS \"$subject::\"
	exit
done
