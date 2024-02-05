#!/bin/bash

echo "Circle.cpp"

# g++ circleDDA.cpp -o circleDDA -lglut -lGLU -lGL
# ./circleDDA

# g++ circleBresh.cpp -o circleBresh -lglut -lGLU -lGL
# ./circleBresh

g++ circleMidpt.cpp -o circleMidpt -lglut -lGLU -lGL
./circleMidpt