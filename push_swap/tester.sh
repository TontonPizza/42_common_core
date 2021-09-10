#!/usr/bin/env bash
filename=trace.txt
rm -f $filename
make fclean  > /dev/null && make > /dev/null
#echo "#l1 * val - l2 * index + l3 * size" >> $filename
check()
{
              STACK=$1
              LIM=
              ARGS=`./genstack $STACK $2 $3`
              COUNT=`./push_swap $ARGS | wc -l`
              RESULT=`./push_swap $ARGS | ./checker $ARGS`
              echo -n "$STACK; $RESULT; $COUNT;" >> $filename
              if [ "$RESULT" = "KO" ];
                then
                echo  "$ARGS;" >> $filename
              else
                echo " " >> $filename
              fi
}

echo "STACK SIZE ; RESULT; MOVE COUNT ; (ARGS IF KO)" >> $filename
for x in {1..15}
  do
  for y in {1..5}
    do
      check $x 0 $x
    done
              echo "----" >> $filename
  done
              echo "----" >> $filename

for x in {1..10}
  do
        check 100 0 100
done
              echo "----" >> $filename

for x in {1..5}
  do
    check 500 0 500
done

make fclean && clear && cat $filename;
