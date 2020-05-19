#include <iostream>
#include "MatrixOps.h"

int main() {
    MatrixOps<int> A(4,5);
    MatrixOps<int> B(4,5);
    MatrixOps<int> C(5,6);
    MatrixOps<int> W({{1,2,3},{4,5,6}});
    MatrixOps<int> Z({{1,5,3},{9,5,6}});

    MatrixOps<int> D = W + Z;  // = A.add(B)
    W.printMatrix();
    Z.printMatrix();
    D.printMatrix();

    return 0;
}
