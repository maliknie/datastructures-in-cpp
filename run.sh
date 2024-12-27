#!/bin/bash

output_file="${1%.*}"
g++ "$1" -o "$output_file" && ./"$output_file" && rm "$output_file"