# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark_100.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarthric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:13:08 by rarthric          #+#    #+#              #
#    Updated: 2022/03/11 16:13:10 by rarthric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MAX=0
ITERATIONS=0
LIMIT=700
FILE=problem_100
SUM=0

for i in {1..100}
do
		export ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
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
