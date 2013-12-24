NextDivel
==========

NextDivel Experimental OS

NextDivel is an OS written from scratch under the GNU GPL v2.

Build instructions
==================

Run the following commands

```sh
git clone http://github.com/AdrianArroyoCalle/next-divel
cd next-divel
mkdir build
cd build
cmake ..
make
make DESTDIR=next install
chmod +x iso.sh
./iso.sh
```

