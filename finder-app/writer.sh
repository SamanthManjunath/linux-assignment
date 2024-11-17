#!/bin/sh

FILE=""
STRING=""
DIR=""

if [ $# -lt 2 ]
then
        echo "Number of arguments ($#) are less than 2"
        return 1
else
        FILE=$1
	STRING=$2
	DIR=$(dirname "$FILE")
	echo "DIR=$DIR"
	echo "STRING=$STRING"
	if [ ! -d "$DIR" ]; then
		echo "making directory $DIR"
		mkdir -p $DIR
		chmod +x $DIR
	fi
	touch $FILE
	echo $STRING > $FILE
fi

