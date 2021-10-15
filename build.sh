#!/bin/bash

set -euo pipefail

mkdir -p build && cd build

# mac nproc support
type nproc &> /dev/null || alias nproc="sysctl -n hw.logicalcpu"

# Configure
# cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
cmake -DCODE_COVERAGE=ON \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_COMPILER=g++ \
      -DCMAKE_C_COMPILER=gcc \
      -DCMAKE_FORTRAN_COMPILER=gfortran \
      ..

# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . --config Debug -- -j $(nproc)
# Test
ctest -j $(nproc) --output-on-failure

pip install -r ../requirements.txt
PYTHONPATH="$PYTHONPATH:$(pwd)/src" pytest ../
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info -o coverage.info '*/usr/*' '*/test/*' "${HOME}"'/.cache/*'
lcov --list coverage.info # debug info