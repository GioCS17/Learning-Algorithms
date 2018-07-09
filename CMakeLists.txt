cmake_minimum_required(VERSION 3.9)
project(ProjectPOO2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectPOO2 main.cpp NN/Knn/KnnAlgorithm.cpp NN/Knn/KnnAlgorithm.h NN/Element.cpp NN/Element.h NN/ActivationFunctions/totalActivationFunctions.cpp NN/ActivationFunctions/totalActivationFunctions.h NN/Perceptron/PerceptronAlgorithm.cpp NN/Perceptron/PerceptronAlgorithm.h NN/BackProgation/Neuron.cpp NN/BackProgation/Neuron.h NN/BackProgation/Net.cpp NN/BackProgation/Net.h NN/BackProgation/BackPropagation.cpp NN/BackProgation/BackPropagation.h NN/BackPropagation2/bpnet.cpp NN/BackPropagation2/bpnet.h NN/BackPropagation2/Backpropagation2.cpp NN/BackPropagation2/Backpropagation2.h)