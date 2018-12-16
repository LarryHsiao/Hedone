#!/usr/bin/env bash

mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cget/cget/cget.cmake -DCMAKE_INSTALL_PREFIX=cget ..
cmake --build .
ctest .

lcov --directory . --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1
genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/