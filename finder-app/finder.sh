#!/bin/sh

#set -x
#set -u

STRING=""
DIR=""
NUM_LINES=0
NUM_FILES=0

echo "Entered finder.sh"

if [ $# -lt 2 ]
then
     	echo "Number of arguments ($#) are less than 2"
	return 1
else
	DIR=$1
	STRING=$2
	#chmod 777 $DIR
	echo $STRING $DIR

	#echo "Raw DIR: '$DIR'" | cat -A

	if [ ! -d "$DIR" ]; then
		echo "Invalid directory. Doesnt exist"
		exit 1
	fi
fi

NUM_FILES=$( grep -rl "$STRING" $DIR | wc -l )
NUM_LINES=$( grep -r "$STRING" "$DIR" | wc -l )


echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_LINES"

