#!/usr/bin/env bash

echo "---------- build unit test started ----------"

cur_path=`pwd`
echo "build path: $cur_path"

blade build :unit_test_all -pdebug

echo "---------- build succeed ----------"
echo "---------- run test ----------"

cd ../blade-bin/compute_graph
./unit_test_all

if [ "$?" == 0 ];
then echo "---------- test succeed ----------"
else echo "---------- test failed ----------"
fi

cd $cur_path
