# libKitsunemimiObj

![Gitlab pipeline status](https://img.shields.io/gitlab/pipeline/kitsudaiki/libKitsunemimiObj?label=build%20and%20test&style=flat-square)
![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/kitsudaiki/libKitsunemimiObj?label=version&style=flat-square)
![GitHub](https://img.shields.io/github/license/kitsudaiki/libKitsunemimiObj?style=flat-square)
![C++Version](https://img.shields.io/badge/c%2B%2B-17-blue?style=flat-square)
![Platform](https://img.shields.io/badge/platform-Linux--x64-lightgrey?style=flat-square)

## Description

This library provides a simple and minimal wavefront obj-parser and creator to generate the content of such files.

Supported functions:

- vertex `v`
- normals `vn`
- textures `vt`
- points `p`
- lines `l`
- faces `f`


## Build

### Requirements

name | repository | version | task
--- | --- | --- | ---
g++ | g++ | >= 8.0 | Compiler for the C++ code.
make | make | >= 4.0 | process the make-file, which is created by qmake to build the programm with g++
qmake | qt5-qmake | >= 5.0 | This package provides the tool qmake, which is similar to cmake and create the make-file for compilation.

Installation on Ubuntu/Debian:

```bash
sudo apt-get install g++ make qt5-qmake
```

IMPORTANT: All my projects are only tested on Linux. 

### Kitsunemimi-repositories

Repository-Name | Version-Tag | Download-Path
--- | --- | ---
libKitsunemimiCommon | v0.22.0 |  https://github.com/kitsudaiki/libKitsunemimiCommon.git

HINT: These Kitsunemimi-Libraries will be downloaded and build automatically with the build-script below.

### build library

In all of my repositories you will find a `build.sh`. You only have to run this script. It doesn't required sudo, because you have to install required tool via apt, for example, by yourself. But if other projects from me are required, it download them from github and build them in the correct version too. This script is also use by the ci-pipeline, so its tested with every commit.


Run the following commands:

```
git clone https://github.com/kitsudaiki/libKitsunemimiObj.git
cd libKitsunemimiObj
./build.sh
cd ../result
```

It create automatic a `build` and `result` directory in the directory, where you have cloned the project. At first it build all into the `build`-directory and after all build-steps are finished, it copy the include directory from the cloned repository and the build library into the `result`-directory. So you have all in one single place.

Tested on Debian and Ubuntu. If you use Centos, Arch, etc and the build-script fails on your machine, then please write me a mail and I will try to fix the script.

## Usage by example

Content of example obj-file:

```
v 2.000000 -1.000000 -1.000000
v 1.000000 -1.000000 1.000000
v -1.000000    -1.000000 1.000000
v -1.000000 -1.000000 -1.000000
v     1.000000 1.000000 -0.999999
v 0.999999 1.000000 1.000001
v -1.000000 1.000000 1.000000
v -1.000000    1.000000 -1.000000

vt -1.000000 1.000000
vt -1.000000    1.000000

vn 0.000000 -1.000000 0.000000
vn  0.000000 1.000000 0.000000
vn 1.000000 0.000000 0.000000
vn -0.000000 -0.000000 1.000000
vn -1.0000 -0.000000 -0.000000
vn 0.000000 0.000000 -1.000000

p 2
p 1

l 1 2 3 4
l 1 5 6 7

f 1//1 2//1 3//1 4//1
f 5//2 8//2   7//2 6//2
f 1//3 5//3 6//3 2//3
f 2//4 6//4 7//4 3//4
f 3//5 7//5 8//5 4//5
f 5//6   1//6 4//6 8//6
```

Example usage in code:

```cpp
#include <libKitsunemimiObj/obj_item.h>

// parse string
Kitsunemimi::Obj::ObjItem parsedItem;
bool ret = false;


ret = Kitsunemimi::Obj::parseString(parsedItem, input-string);
// if ret is true, when it was successful
// all parsed information are stored in the parsedItem-object


// create a string again
const std::string output_string = "";
ret = Kitsunemimi::Obj::convertToString(output_string, parsedItem);
// if ret is true, when it was successful
// output_string contains the now the string, which is generated from the parsedItem-object

```


## Contributing

Please give me as many inputs as possible: Bugs, bad code style, bad documentation and so on.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
