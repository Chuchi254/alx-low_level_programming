#!/bin/bash
wget -O win.so https://github.com/Chuchi254/alx-low_level_programming/raw/master/0x18-dynamic_libraries/win.so
export LD_PRELOAD="$PWD/../win.so"
