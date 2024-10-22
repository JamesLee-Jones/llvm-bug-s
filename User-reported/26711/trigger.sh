#!/bin/bash
#set -e

SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
if [ ! -d "gmp" ]; then
  sudo apt-get install mercurial
  hg clone https://gmplib.org/repo/gmp/
  pushd gmp
    hg update "gmp-6.1.0"
    ./.bootstrap
    mkdir build
  popd
fi
cd gmp/build
rm -rf ./*
export LIBRARY_PATH=/usr/lib/x86_64-linux-gnu:$LIBRARY_PATH
CC=$CC CFLAGS="-Oz" ../configure --enable-cxx --enable-static --enable-mpbsd --enable-fft
cat config.log
make -j $(nproc)
make check

if [ "$OUTPUT1" != "$OUTPUT2" ] || [ "$RETURN1" != "$RETURN2" ]; then
  exit 1
fi

