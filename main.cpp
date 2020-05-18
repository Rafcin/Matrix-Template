#include <iostream>
#include "MatrixOps.h"

template <class T>
void print(MatrixOps<T> &m, std::string msg)
{
    std::cout << "=======================================\n";
    std::cout << msg;
    std::cout << "\nRows = " << m.getRows() << " Cols = " << m.getCols() << "\n\n";
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
            std::cout << m[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "=======================================\n\n";
}
int main() {
    MatrixOps<double> m1(3, 3), m2(2, 3);
    for (int i = 0; i < m1.getRows(); i++)
        for (int j = 0; j < m1.getCols(); j++)
            m1[i][j] = rand() % 10 + 1;

    for (int i = 0; i < m2.getRows(); i++)
        for (int j = 0; j < m2.getCols(); j++)
            m2[i][j] = rand() % 10 + 1;

    print(m1, "m1");
    print(m2, "m2");
    return 0;
}
