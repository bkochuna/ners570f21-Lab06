#!/bin/bash

set -euo pipefail

mkdir -p build && cd build

# mac nproc support
type nproc &> /dev/null || alias nproc="sysctl -n hw.logicalcpu"

# Configure
cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . --config Debug -- -j $(nproc)
# Test
ctest -j $(nproc) --output-on-failure

PYTHONPATH="$PYTHONPATH:$(pwd)/src" pytest ../