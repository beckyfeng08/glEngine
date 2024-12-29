#include <iostream>
#include "test.h"

int main() {
    int x = 5, y = 3;
    std::cout << "Add: " << testing::add(x, y) << std::endl;
    std::cout << "Subtract: " << testing::subtract(x, y) << std::endl;
    return 0;
}