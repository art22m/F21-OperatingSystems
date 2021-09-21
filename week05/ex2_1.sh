#!/bin/bash
for i in {1..100}
do
	last_num=$( tail -n 1 file.txt)
	echo `expr $last_num + 1` >> file.txt
done