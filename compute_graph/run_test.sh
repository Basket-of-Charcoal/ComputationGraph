#!/usr/bin/env bash

echo "---------- build unit test started ----------"

cur_path=`pwd`
# echo $cur_path

blade build :unit_test_all

echo "---------- build succeed ----------"