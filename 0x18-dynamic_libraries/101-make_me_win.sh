#!/bin/bash
wget -P /tmp https://github.com/Iniobong11/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libshare.so 
export LD_PRELOAD=/tmp/libshare.so
