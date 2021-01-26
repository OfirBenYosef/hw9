#!/bin/bash

while read line
do
	echo "$line"| cat >> pkts.txt
done
while read rule
do
	packets=""
		
	# remove empty lines, spaces and comments
	echo "$rule"| cat > rule.txt 
	sed -i 's/#.*//g;/^$/d;s/\s//g' rule.txt



	# save all rule fileds in array
	rule=$(awk -F ',' '{print $1,$2,$3,$4}' rule.txt)
	rules=($rule)

	# check if the packet fits the rule
	if [[ "${#rules[@]}">"0" ]]; then

		for i in "${rules[@]}"
		do
	        cat pkts.txt | ./firewall.exe "$i" 2>/dev/null | cat >> packets.txt
		done
		#counts the number of rules fields the packet fits
		sort packets.txt | uniq -c > sortpack.txt
		#findes packets which fits all of the rule fields 
		grep -E "^ *${#rules[@]}"  sortpack.txt| cat > Mp.txt

		sed -i "s/^ *${#rules[@]}//g" Mp.txt	
		cat Mp.txt>>all_packets.txt
		cat /dev/null > packets.txt
			
	fi
done < "$1"



sort all_packets.txt | uniq >> Mpl.txt
# delete spaces and nuber of rules
sed -i "s/\s//g" Mpl.txt 
cat Mpl.txt
rm *.txt