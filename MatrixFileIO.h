//
// Created by raf on 5/20/20.
//

#ifndef MATRIXPROJECT_MATRIXFILEIO_H
#define MATRIXPROJECT_MATRIXFILEIO_H

#include <vector>
#include <string>
#include <fstream>

template <class T>
class MatrixFileIO {
    public:
        std::vector<std::vector<T>> readMatrixFile(std::string fileName);
};

template <class T>
std::vector<std::vector<T>> MatrixFileIO<T>::readMatrixFile(std::string fileName){
    std::string line;
    std::ifstream infile(fileName);
    std::vector<std::vector<T>> data;
    while(std::getline(infile, line)){
        std::vector<T> r;
        for(char &d : line){
            if(d != ','){
                double x = (double)d;
                T y = (T)x;
                r.push_back(x);
            }
        }
        data.push_back(r);
        return data;
    }
}

#endif //MATRIXPROJECT_MATRIXFILEIO_H
