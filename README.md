NextDivel
==========

[![Join the chat at https://gitter.im/AdrianArroyoCalle/next-divel](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/AdrianArroyoCalle/next-divel?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

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

