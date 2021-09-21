#!/bin/bash

for i in {1..100}
do
	until ln file.txt file.txt.lock &>/dev/null; do
	    sleep 1
	done
	last_num=$( tail -n 1 file.txt)
	echo `expr $last_num + 1` >> file.txt
	rm -f file.txt.lock
done