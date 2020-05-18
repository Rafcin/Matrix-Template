//
// Created by raf on 5/17/20.
//

#ifndef MATRIXPROJECT_MATRIXOPS_H
#define MATRIXPROJECT_MATRIXOPS_H

#include <vector>
#include <iostream>
/**
 * @TODO
 * 1. fix system crash when reaching print
 */
/**
 * Notes:
 * http://www.cplusplus.com/reference/vector/vector/resize/
 * https://www.tutorialspoint.com/cplusplus/cpp_inline_functions.htm
 *
 * @tparam T
 */
template <typename T>
class MatrixOps {
private:
    std::vector<std::vector<T>> matrix;
    size_t rows, cols;
    //handle removing ptrs and or deleting vectors
    void clear();
public:
    MatrixOps();
    MatrixOps(size_t rows, size_t cols);
    MatrixOps(const MatrixOps<T> &m);

    void print();

    //Removed defulat CLION getter and setter returns / sets.
    size_t getRows();
    void setRows(size_t rows);

    size_t getCols();
    void setCols(size_t cols);

    MatrixOps<T>& operator=(const MatrixOps<T> &m);
    MatrixOps<T>& operator+=(const MatrixOps<T> &n);


    std::vector<T>& operator[](size_t index);

    virtual ~MatrixOps();
};

template <typename T>
size_t MatrixOps<T>::getRows(){return rows;}

template <typename T>
size_t MatrixOps<T>::getCols(){return cols;}

template <typename T>
void MatrixOps<T>::setRows(size_t rows){
    if(rows > 0){
        this->rows = rows;
        matrix.resize(rows);
    }else{this->rows =0;}
}

template <typename T>
void MatrixOps<T>::setCols(size_t cols){
    if(cols > 0){
        this->cols = cols;
        matrix.resize(cols);
    }else{this->cols =0;}
}

template<typename T>
inline void MatrixOps<T>::clear()
{
    rows = cols = 0;
    typename std::vector<std::vector<T>>::iterator mDelIt;
    for (mDelIt = matrix.begin(); mDelIt != matrix.end(); mDelIt ++)
        mDelIt->clear();
    matrix.clear();
}

template <typename T>
//def no params
MatrixOps<T>::MatrixOps(){rows = cols = 0;}

template <typename T>
MatrixOps<T>::MatrixOps(const MatrixOps<T> &m){*this = m;}

template <typename T>
// using size_t because it can handle more. MAX_SIZE
MatrixOps<T>::MatrixOps(size_t rows, size_t cols){
    //No negative row or col size
    if(rows > 0 && cols > 0){
        this->rows = rows;
        this->cols = cols;
        matrix.resize(rows);
        typename std::vector<std::vector<T>>::iterator matTrav;
        for(matTrav = matrix.begin(); matTrav != matrix.end(); matTrav++){
            matTrav->resize(cols);
        }
        this->rows = this->cols = 0;
    }
}

template<typename T>
MatrixOps<T>::~MatrixOps() {
    clear();
}

template <typename T>
std::vector<T>& MatrixOps<T>::operator[](size_t index){return matrix[index];}

template <typename T>
MatrixOps<T>& MatrixOps<T>::operator=(const MatrixOps<T> &m){
    setRows(m.getRows());
    setCols(m.getCols());
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
}

template <typename T>
MatrixOps<T>& MatrixOps<T>::operator+=(const MatrixOps<T> &n){
    if(rows == n.getRows() && cols == n.getCols){
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                matrix[i][j] += n.matrix[i][j];
            }
        }
    }
    return *this;
}


#endif //MATRIXPROJECT_MATRIXOPS_H
