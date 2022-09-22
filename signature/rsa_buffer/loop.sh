#!/bin/bash

i=1
while [ $i -le 10 ]
do
	./verify
	let i=i+1
done
