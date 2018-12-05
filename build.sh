#!/usr/bin/env bash

mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cget/cget/cget.cmake -DCMAKE_INSTALL_PREFIX=cget ..
cmake --build .

lcov --directory . --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1
ctest .
echo ${PWD}
genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/