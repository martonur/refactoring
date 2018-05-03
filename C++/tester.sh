#!/bin/sh

rm -f a.out
rm -f current_output.txt

g++ -Wall -g -O GameRunner.cpp Game.cpp

if [[ -s a.out ]]
then
    ./a.out > current_output.txt
    diff -u original_output.txt current_output.txt > difference.txt
    if [[ -s difference.txt ]]
    then
        cat difference.txt
    else
        echo "The program is working correctly"
    fi
fi