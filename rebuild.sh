#!/bin/env bash

mkdir -p uild

cmake -S . -B build || exit 1

cmake --build build --clean-first
