#!/bin/bash


echo "After building all executables, this will perform the tests"

pushd bin

echo "========================================================"
echo "INFO: Run 01"
pushd q01
./q01.exe [1,3,5,7,9] [2,4,6,8,10]
popd 

echo "========================================================"
echo "INFO: Run 02"
pushd q02
./q02.exe [4,1,5,3,9,7] 10
popd 


echo "========================================================"
popd
