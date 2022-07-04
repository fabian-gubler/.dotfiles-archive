#!/bin/bash

var="hello"

case $1 in
  period-changed)
	  exec dunstify "test $1" 
esac

