#!/bin/bash
#gcc -o $1.elf $1 
#objcopy -j.text -O ihex $1.elf $1.hex
#objcopy -O ihex $1.elf $1.hex
gcc -c -o $1.bin $1 -O0 -Wl,--oformat=binary
objdump -d $1.bin
objcopy -O binary $1.bin $1.hex
