# cmake wiki

## Documentation for CMake Build System

The main CMake file is CMakeLists. The cmake macros and scripts, including the installer,  are located in the /cmake/ directory.

### Workflow

CMake is a build system generator with two steps, first a configure step followed by a build step. First you call cmake to configure the project, which generates a Makefile. Then you can use the generated Makefile to build the code using make.

For example

```console
mkdir /path/to/build/dir
cd /path/to/build/dir
cmake /path/to/source/dir
make
```

The final command can also be run in parallel

```console
make -j N
```

This compiles the entire SpMV library and tests. 

### Configure options

Debug/release options are included in the Cmake by default. But to distinguish the executables for different options, a postfix "d" will be added to the executable if the debug option is selected. To setup the debug build, please use the following command:

```console
mdkir /path/to/build/debug
cd /path/to/build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

Similarly, to setup release build, please specify as follow:

```console
mdkir /path/to/build/release
cd /path/to/build/release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

### Compiler flags
The setting of compiler flags for each configurations can be specificed as follow:

```console
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
```

For the debug build, the optimization is disabled. For the release build, the higher level of optimization is used.


### Building specific targets
The configure step generates various targets that you can build with make. You can see a list of the targests with

```console
make help
```

Below is a list of what each target accomplishes
```console
make help     # Lists possible targets to be built
make spmv     # Builds SpMV libraries
make test     # Runs test
make clean    # Cleans directory of build files
```

### Linking to SpMV library
Linking cpp code to the SpMV library is accomplished with

```console
g++ -L. -I /path/to/src/dir filename.cpp -lSpMV
```

where filename.cpp is the file you are trying to link to.


### Installer packages
Self extracting installer packages are located in the /cmake/ directory. Be sure to select the correct one based on the operating system and system architecture.
