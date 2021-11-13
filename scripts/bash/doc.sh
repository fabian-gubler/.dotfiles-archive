#!/bin/bash
CMD=pandoc -tplain $1
nvim $CMD
