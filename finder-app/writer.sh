#!/bin/sh

if [ "$#" -ne 2 ]; then
	echo "Error: missing arguments"
	exit 1
fi

writefile="$1"
writestr="$2"

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

exit 0
