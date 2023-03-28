#!/bin/bash
myfile='clientLog'
myfile2='project3.pcap'
touch $myfile
touch $myfile2
if [ -f $myfile ]; then
   rm clientLog
   echo "$myfile deleted"
fi

if [ -f $myfile2 ]; then
    rm -rf project3.pcap
    echo "$myfile2 deleted"
fi