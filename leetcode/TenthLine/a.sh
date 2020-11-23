# Read from the file file.txt and output the tenth line to stdout.
a=0
while read line 
do
    ((a+=1))
    if [[ $a -eq 10 ]]; then
        echo "$line"
    fi
done < "file.txt"
