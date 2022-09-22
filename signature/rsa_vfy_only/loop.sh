#!/bin/bash

i=1
while [ $i -le 10 ]
do
	./verify
	echo $?
	let i=i+1
done
