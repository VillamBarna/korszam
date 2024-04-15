#include <iostream>
#include <vector>
#include "polinom.h"


int main() {
    polinom p;
    p.egyutthatok = {1, 2, 3};
    std::cout << p.egyutthatok[0] << std::endl;
}
