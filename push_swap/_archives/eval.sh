#!/usr/bin/env bash
filename=trace_.txt
rm -f $filename
make eval && clear
#echo "#l1 * val - l2 * index + l3 * size" >> $filename

# args : STACK SIZE  P1 P2 P3 P4
check()
{
              STACK=$1
              ARGS=`./genstack $STACK 0 500`
              COUNT=`echo "$2 $3 $4" | ./push_eval $ARGS | wc -l`
              echo "$1; $2; $3 ;$4 ; $5;  $COUNT;" >> $filename
}

for x in {2..10}
do
    for y in {2..10}
    do
      for z in {-5..-5}
      do

          check 100 $x $y $z

      done
    done
done