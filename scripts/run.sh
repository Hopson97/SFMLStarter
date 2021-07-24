#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/bin/SFMLStarter 
else
    ./build/debug/bin/SFMLStarter 
fi