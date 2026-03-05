#!/bin/sh

# Convenience script that runs the checks and formatters for both the C headers and symbol tables.
# Expects the working directory to be the repo root.

set -e

make -C headers
make -C headers format
make -C headers symbol-check

resymgen check -r -Vvbomu -d screaming_snake_case -f pascal_snake_case -f snake_case symbols/*.yml
resymgen fmt -r symbols/*.yml

