# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark_500.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarthric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:13:19 by rarthric          #+#    #+#              #
#    Updated: 2022/03/11 16:13:21 by rarthric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MAX=0
ITERATIONS=0
LIMIT=5500
FILE=problem_500
SUM=0

for i in {1..50}
do
		export ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | ./checker $ARG | grep -q KO
		then
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo $i ":" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX
