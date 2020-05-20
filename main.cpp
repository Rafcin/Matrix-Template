#include <iostream>
#include "MatrixOps.h"
#include "MatrixFileIO.h"

int main() {
    MatrixOps<int> A1({{1,5,3},{9,5,6},{1,5,6}});
    MatrixOps<int> A2({{1,5,3},{9,5,6},{1,5,6}});
    MatrixOps<int> A3(3,3);
    MatrixOps<int> B({{1,5},{9,5}});
    MatrixOps<int> C({{7,5},{2,5}});
    MatrixOps<int> D(2,2);
    
    std::cout << "Addition of 3x3 Matricies A1 and A2 to A3"<<std::endl;
    std::cout << "A1: "<<std::endl;
    A1.printMatrix();
    std::cout << "A2: "<<std::endl;
    A2.printMatrix();
    A3 = A1+A2;
    std::cout << "A3: "<<std::endl;
    A3.printMatrix();

    std::cout << "====================================================="<<std::endl;

    std::cout << "Subtraction of 3x3 Matricies A1 and A2 to A3"<<std::endl;
    std::cout << "A1: "<<std::endl;
    A1.printMatrix();
    std::cout << "A2: "<<std::endl;
    A2.printMatrix();
    A3 = A1-A2;
    std::cout << "A3: "<<std::endl;
    A3.printMatrix();

    std::cout << "====================================================="<<std::endl;

    std::cout << "Multiplication of 3x3 Matricies A1 and A2 to A3"<<std::endl;
    std::cout << "A1: "<<std::endl;
    A1.printMatrix();
    std::cout << "A2: "<<std::endl;
    A2.printMatrix();
    A3 = A1*A2;
    std::cout << "A3: "<<std::endl;
    A3.printMatrix();

    std::cout << "====================================================="<<std::endl;

    std::cout << "Determinant of Matrix A1"<<std::endl;
    std::cout << "A1: "<<std::endl;
    A1.printMatrix();
    std::cout << A1.determinant();

    return 0;
}
