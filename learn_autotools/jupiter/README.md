### description
this repo is based on the book Autotools_A Practitioner_'s Guide to GNU Autoconf, Automake, and Libtool


### run
```
autoreconf
./configure
make distcheck
```

### useful information
- .a files are static libraries typically generated by the archive tool (ar tool, An archive is a single file holding a collection of other files in a structure that makes it possible to retrieve the original individual files). 
- library extension .la stands for libtool archive
- A shared library(.so) is a library that is linked but not embedded in the final executable, so will be loaded when the executable is launched and need to be present in the system where the executable is deployed
- A dynamic link library on windows(.dll) is like a shared library(.so) on linux but there are some differences between the two implementations that are related to the OS (Windows vs Linux)
### references
github: https://github.com/haoyutan/codelib/tree/master/Autotools