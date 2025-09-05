#!/usr/bin/bash

ls -l
read

for i in *; do
    echo $i
    cat $i
done
