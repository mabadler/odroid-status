#!/bin/bash
rm "count.txt"
touch "count.txt"
COMMAND="find ./img/*.$1 | wc -l"
echo $COMMAND
NF=`eval $COMMAND`
echo $NF > "count.txt"
