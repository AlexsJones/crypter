##Instructions
The idea with this is that you compile an application for the target platfrom
The idea is then to encrypt the binary (XOR is the most basic obfusication operation by dropping out 4 bits per byte) and then you get it on the target system (Somehow ;)) then decrypt it with crypter

e.g.
```
./crypter -e ../../secret_payload -o nothingmuch.jpg
```

```
./crypter -d nothingmuch.jpg -e payload
```


##Build
```
cmake .
make
```
To compile for windows run
```
./scripts/compile_windows
```
and drop crypter_win.exe onto your windows system 
###Dependencies

```
cmake.
build-essentials
c++ compiler

#For windows compilation only
binutils-mingw-w64
g++-mingw-w64
mingw-w64

```

####Note on encryption

So XORing the file is not really encryption.Its closer to obfusication so that the binary file cannot be parsed correctly by scanners. 
I will work on implementing optional actual encryption with reverse DES or something similar that will actually seal the payload, but this is a WIP.

