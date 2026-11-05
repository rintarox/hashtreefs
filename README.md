# htfs - HashTreeFileSystem
Fuse filesystem based on UT_hash

UT_hash repo : https://github.com/troydhanson/uthash/tree/master


libfuse3 must be installed and available.
Check for .so files:
```
sudo ldconfig -p | grep fuse3
```

Build and run:
```
gcc hashtreefs.c -o htfs -lfuse3
mkdir mnt
./htfs -d -f mnt
```

-d is default debug flag from libfuse
