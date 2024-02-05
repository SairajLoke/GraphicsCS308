#!/bin/bash

echo "drawing"

# g++ test.cpp -o firstOpenGlApp -lglut -lGLU -lGL
# ./firstOpenGlApp

g++ tree.cpp -o tree -lglut -lGLU -lGL
./tree