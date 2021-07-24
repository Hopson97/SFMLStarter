#!/bin/bash

target_release() {
    cd release
    cmake -DCMAKE_BUILD_TYPE=Release ../..
    make
    echo "Built target in build/release/"
    cd ../..
}

target_debug() {
    cd debug 
    cmake -DCMAKE_BUILD_TYPE=Debug ../..
    make
    echo "Built target in build/debug/"
    cd ../..
}

# Create folder for distribution
if [ "$1" = "release" ]
then
    if [ -d "$SFMLStarter " ]
    then
        rm -rf -d SFMLStarter 
    fi

    mkdir -p SFMLStarter 
fi

# Creates the folder for the buildaries
mkdir -p SFMLStarter
mkdir -p SFMLStarter/Data
mkdir -p build
mkdir -p build/release
mkdir -p build/debug
cd build

conan install .. -s compiler.libcxx=libstdc++11 --build=missing

# Builds target
if [ "$1" = "release" ]
then
    target_release
    cp build/release/bin/SFMLStarter  SFMLStarter/SFMLStarter 
else
    target_debug
fi

cp -R Data SFMLStarter/Data
