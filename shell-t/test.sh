#!/bin/bash
if [ "$#" -lt "1" ];then
	echo get me your name
	exit 1
fi
echo $1, hello shell world !!!
