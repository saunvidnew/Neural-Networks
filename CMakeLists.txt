# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(NEURALNETWORKS)

set(CMAKE_CXX_STANDARD 17)

add_executable(NEURAL_NETWORKS src/main.cpp src/Layer.cpp src/Neuron.cpp src/Matrix.cpp src/Neural_network.cpp src/Multiply_matrix.cpp)
