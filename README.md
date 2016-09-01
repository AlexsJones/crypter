##Instructions
The idea with this is that you compile an application for the target platform (Currently crypter also needs to be compiled so that's limiting you to OSX/Linux)

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

###Dependencies

Doesnt really use anything other than stdlibc and c++ functions.
```
cmake.
build-essentials
c++ compiler
```

####Note on encryption

So XORing the file is not really encryption.Its closer to obfusication so that the binary file cannot be parsed correctly by scanners. 
I will work on implementing optional actual encryption with reverse DES or something similar that will actually seal the payload, but this is a WIP.

