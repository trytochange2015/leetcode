#!/bin/bash

# add file to github

if [ $# -lt 2 ]; then
	echo "Usage:$0 filename filename ...";
else
	for file in "$@";
	do
		git add $file;
	done
	git commit -m "add $*";
	git push origin master;
fi
