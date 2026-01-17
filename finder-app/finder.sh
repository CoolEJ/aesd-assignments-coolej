#! /bin/sh

#check argument count
if [ $# -ne 2 ]; then
	echo "Error: missing arguments"
	exit 1
fi

filesdir="$1"
searchstr="$2"

#Check directory exists
if [ ! -d "$filesdir" ]; then
	echo "Error: $filesdir is not a directory"
	exit 1
fi

# Count files
filecount=$(find "$filesdir" -type f | wc -l)

# Count matching lines
matchcount=$(grep -R "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# Required ouput
echo "The number of files are $filecount and the number of matching lines are $matchcount"
exit 0
