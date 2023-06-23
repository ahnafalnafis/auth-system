#!/usr/bin/env bash

BIN=./bin

if [ ! -d "$BIN" ]; then
  echo "Couldn't find $BIN"
  echo "Creating $BIN directory..."
  mkdir $BIN
  echo "Created $BIN directory."
fi

echo "Compiling..."
g++ src/*.cpp -o $BIN/app
echo "Compilation done with exit code: $?"
