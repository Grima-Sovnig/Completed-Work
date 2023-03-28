#!/bin/bash
myfile='serverLog'
touch $myfile
if [ -f $myfile ]; then
   rm serverLog
   echo "$myfile deleted"
fi