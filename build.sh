#!/bin/bash

mkdir -p bin
pushd bin

cmake ..
make

popd

