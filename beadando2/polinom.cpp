#include <iostream>
#include <vector>
#include "polinom.h"

int main() {
    std::vector<int> e{1,2,3};
    polinom p{e};
    std::vector<int> a{3,4,5};
    polinom p2{a};
    polinom p3{e};
    p3 = p + p2;
    std::cout << "done" << std::endl;
    std::cout << p3.egyutthatok[0] << std::endl;
    std::cout << p3.egyutthatok[1] << std::endl;
    std::cout << p3.egyutthatok[2] << std::endl;
}
