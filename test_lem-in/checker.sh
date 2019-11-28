#!/bin/bash
my=0
ih=0
n=0
cycle=100000
i=0
result=0
gen=0
DIFF=0
while [ $cycle -ne $i ]
do
	#gen=$(./generator --flow-one> checker_map; cat checker_map | grep "#Here is the number of lines required" | tail -n 1 | cut -d " " -f8 | bc)
	#gen=$(./generator --flow-ten> checker_map; cat checker_map | grep "#Here is the number of lines required" | tail -n 1 | cut -d " " -f8 | bc)
	#gen=$(./generator --flow-thousand> checker_map; cat checker_map | grep "#Here is the number of lines required" | tail -n 1 | cut -d " " -f8 | bc)
	#gen=$(./generator --big> checker_map; cat checker_map | grep "#Here is the number of lines required" | tail -n 1 | cut -d " " -f8 | bc)
	gen=$(./generator --big-superposition > checker_map; cat checker_map | grep "#Here is the number of lines required" | tail -n 1 | cut -d " " -f8 | bc)
	START=$(gdate +%s%N)
	./lem-in < checker_map > checker_map_lem_in
	END=$(gdate +%s%N)
	my_lem_in=$(cat checker_map_lem_in | grep "^L[0-9]" | wc -l | bc)
	DIFF=$(( $DIFF - $START + $END ))
	result=$(($result + $my_lem_in - $gen))
	i=$(($i + 1))
	ti=$(bc <<< "scale=2; $((($END-$START)/1000000))")
	echo "#$i lem-in $my_lem_in, generator $gen, time $ti"
	if [ $(($i % 10)) -eq 0 ]
	then
		echo "Diff=$(bc <<< "scale=3; $result / $i")"
		t=$(bc <<< "scale=2; $(($DIFF/1000000/$i))")
		echo "Time=$t"
	fi
done
