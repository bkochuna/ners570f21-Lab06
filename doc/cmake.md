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

This compiles the entire SpMV library and tests. To run the tests you can call

```console
make test
```

### Configure options
Shuai is still working on this


### Building specific targets
The configure step generates various targets that you can build with make. You can see a list of the targests with

```console
make help
```

### Installer packages
Self extracting installer packages are located in the /cmake/ directory. Be sure to select the correct one based on the operating system and system architecture.
