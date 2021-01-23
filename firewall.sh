#!/bin/bash

while read line
do
	packets=""
	echo "$line"| cat >line.txt
	# remove empty lines, spaces and comments
	sed -i 's/#.*//g;/^$/d;s/\s//g' line.txt

	# save all rule fileds in array
	rule=$(awk -F ',' '{print $1,$2,$3,$4}' line.txt)
	rules=($rule)

	# check if the packet fits the rule
	if [[ "${#rules[@]}">"0" ]]; then

		for i in "${rules[@]}"
		do
        	cat $1 | ./firewall.exe "$i" 2>/dev/null | cat >> packets.txt
		done

		sort packets.txt | uniq -c > sortpack.txt
		# findes packets which fits all of the rule fields 
		grep -E "^ *${#rules[@]}"  sortpack.txt| cat > Mp.txt
		
		sed -i "s/^ *${#rules[@]}//g;s/\s//g" Mp.txt 
		cat Mp.txt>>all_packets.txt
		cat /dev/null > packets.txt
		
	fi

done

sort all_packets.txt | uniq > Mp.txt
cat Mp.txt
rm *.txt