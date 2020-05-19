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
 * http://www.cplusplus.com/reference/stdexcept/invalid_argument/
 *
 * @tparam T
 */
//matrix name space - mns
template <class T>
class MatrixOps{
    private:
        std::vector<std::vector<T>> data;
        size_t rows;
        size_t cols;
    public:
        MatrixOps<T>(size_t rows, size_t cols);
        MatrixOps<T>(std::vector<std::vector<T>> const &data);
        MatrixOps<T>();

        void printMatrix();

        size_t getRows() const;
        size_t getCols() const;

        T get(size_t x, size_t y) const;

        T& operator()(size_t row, size_t col);
        std::vector<T>& operator[](size_t index) const;
        std::vector<T>& operator[](size_t index);

        bool operator==(const MatrixOps<T>& m);
        bool operator!=(const MatrixOps<T>& m);

        MatrixOps<T> operator+=(const MatrixOps<T>& m);
        MatrixOps<T> add(const MatrixOps<T>& m) const;

        MatrixOps<T> operator-=(const MatrixOps<T>& m);
        MatrixOps<T> sub(const MatrixOps<T>& m) const;

        MatrixOps<T> operator*=(const MatrixOps<T>& m);
        MatrixOps<T> operator*=(const T &m);
        MatrixOps<T> multi(const MatrixOps<T>& m) const;
        MatrixOps<T> multi(const T& m) const;

        MatrixOps<T> operator/=(const T &m);
        MatrixOps<T> div(const T& m) const;

};

template <class T>
MatrixOps<T> operator+(const MatrixOps<T> &one, const MatrixOps<T> &two);

template <class T>
MatrixOps<T> operator-(const MatrixOps<T> &one, const MatrixOps<T> &two);

template <class T>
MatrixOps<T> operator*(const MatrixOps<T> &one, const MatrixOps<T> &two);

template <class T>
MatrixOps<T> operator*(const T &two, const MatrixOps<T> one);

template <class T>
MatrixOps<T> operator/(const MatrixOps<T>& one, const T &two);

template <class T>
MatrixOps<T> operator+(const MatrixOps<T> &one, const MatrixOps<T> &two);

#endif //MATRIXPROJECT_MATRIXOPS_H

template <class T>
MatrixOps<T>::MatrixOps(size_t rows, size_t cols){
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<std::vector<T> >(cols, std::vector<T>(rows));
}

template <class T>
MatrixOps<T>::MatrixOps(std::vector<std::vector<T>> const &data){
    if (data.size()==0){
        throw std::invalid_argument("Matrix data can not be equal to 0 or NULL");
    }else{
        this->rows =data[0].size();
        this->cols =data.size();
        this->data = data;
    }
}

template <class T>
void MatrixOps<T>::printMatrix() {
    std::cout<<"Rows: "<<getRows()<<" Cols: "<<getCols()<<std::endl;
    for(size_t i=0; i<cols; i++){
        for(size_t j=0; j<rows; j++){
            std::cout<< data[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

template <class T>
MatrixOps<T>::MatrixOps(){
    //set empty matrix
    rows = 0;
    cols = 0;
}

template <class T>
size_t MatrixOps<T>::getRows() const{
    return rows;
}

template <class T>
size_t MatrixOps<T>::getCols() const{
    return cols;
}

template <class T>
T& MatrixOps<T>::operator()(size_t x, size_t y){
    if(x && y < 0 && x > rows && y > cols ){
        throw std::invalid_argument("Out of bounds. Index not found in Matrix");
    }else{
        return data[x][y];
    }
}

template <class T>
std::vector<T>& MatrixOps<T>::operator[](size_t index){
    return data[index];
}

template <class T>
std::vector<T>& MatrixOps<T>::operator[](size_t index) const{
    return data[index];
}

/*
 ADD/SUB
 Two matrices can be added or subtracted if they have the same size. Suppose A and B are
 two matrices of the size m × n, in which aij denotes the element of A in the ith row and
 the jth column, and so on. The sum and difference of A and B are given by:
 */

template <class T>
MatrixOps<T> MatrixOps<T>::add(const MatrixOps<T> &m) const {
    if(rows == m.rows && cols == m.cols){
        MatrixOps returnMatrix(rows,cols);
        for(size_t i=0; i<cols; i++){
            for(size_t j=0; j<rows; j++){
                returnMatrix.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return returnMatrix;
    }else{
        throw std::invalid_argument("Matrices must be the same size to add");
    }
}

template <class T>
MatrixOps<T> MatrixOps<T>::operator+=(const MatrixOps<T>& m){
    this->data = add(m).data;
    return *this;
}

template <class T>
MatrixOps<T> operator+(const MatrixOps<T> &one, const MatrixOps<T> &two){
    return one.add(two);
}

template <class T>
MatrixOps<T> MatrixOps<T>::sub(const MatrixOps<T> &m) const {
    if(rows == m.rows && cols == m.cols){
        MatrixOps returnMatrix(rows,cols);
        for(size_t i=0; i<cols; i++){
            for(size_t j=0; j<rows; j++){
                returnMatrix.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return returnMatrix;
    }else{
        throw std::invalid_argument("Matrices must be the same size to subtract");
    }
}

template <class T>
MatrixOps<T> MatrixOps<T>::operator-=(const MatrixOps<T>& m){
    this->data = sub(m).data;
    return *this;
}

template <class T>
MatrixOps<T> operator-(const MatrixOps<T> &one, const MatrixOps<T> &two){
    return one.sub(two);
}

template <class T>
MatrixOps<T> MatrixOps<T>::multi(const MatrixOps<T> &m) const {
    if(rows == m.rows && cols == m.cols){
        MatrixOps returnMatrix(rows,cols);
        for(size_t i=0; i<cols; i++){
            for(size_t j=0; j<rows; j++){
                returnMatrix.data[i][j] = data[i][j] * m.data[i][j];
            }
        }
        return returnMatrix;
    }else{
        throw std::invalid_argument("Matrices must be the same size to multiply");
    }
}

template <class T>
MatrixOps<T> MatrixOps<T>::multi(const T& m) const {
    MatrixOps returnMatrix(data);
    for(size_t i = 0; i <cols; i++){
        for(size_t j = 0; j <rows; j++){
            returnMatrix.data[i][j] *= m;
        }
    }
    return returnMatrix;
}

template <class T>
MatrixOps<T> MatrixOps<T>::operator*=(const MatrixOps<T>& m){
    this->data = multi(m);
    return *this;
}

template <class T>
MatrixOps<T> MatrixOps<T>::operator*=(const T &m){
    this->data = multi(m);
    return *this;
}

template <class T>
MatrixOps<T> operator*(const MatrixOps<T> &one, const MatrixOps<T> &two){
    return one.multi(two);
}

template <class T>
MatrixOps<T> operator*(const T &one, const MatrixOps<T> &two){
    return one.multi(two);
}

template <class T>
MatrixOps<T> MatrixOps<T>::div(const T& m) const {
    MatrixOps returnMatrix(data);
    for(size_t i = 0; i <cols; i++){
        for(size_t j = 0; j <rows; j++){
            returnMatrix.data[i][j] /= m;
        }
    }
    return returnMatrix;
}

template <class T>
MatrixOps<T> MatrixOps<T>::operator/=(const T &m){
    this->data = div(m);
    return *this;
}

template <class T>
MatrixOps<T> operator/(const MatrixOps<T>& one, const T &two){
    return one.div(two);
}