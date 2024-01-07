#!/bin/bash
mkdir -p build
cd build
cmake ..
cmake --build .
cd ..

./build/CBT_Application
 