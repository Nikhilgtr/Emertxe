#!/bin/bash
#SCRIPT : feedback30.sh
#PURPOSE : to create infinte feedback loop using pipes or redirection

tail -f feed.txt | tee feed.txt >> feed.txt
# tee command sends output to given destination as well as stdin

