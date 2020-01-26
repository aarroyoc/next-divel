#!/usr/bin/env bash
mkdir build
cd build
cmake ..
make
make DESTDIR=next install
chmod +x iso.sh
./iso.sh