#!/bin/bash
if [[ $2 == "c" ]]; then
  g++ -g $1 && cat i | ./a.out
else 
  cat i | ./a.out
fi
