#include <iostream>
#include <vector>
#include "polinom.h"

int main() {
    polinom p{std::vector<int> {1,2,3}};
    polinom p2{std::vector<int> {4,5,6}};
    polinom p3 = p - p2;
    std::cout << "done" << std::endl;
    std::cout << p3.egyutthatok[0] << std::endl;
    std::cout << p3.egyutthatok[1] << std::endl;
    std::cout << p3.egyutthatok[2] << std::endl;
}
