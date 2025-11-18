#include <iostream>
#include <cassert>
#include "../../src/system.h"

void basicSystemTest() {

    System s(50);
    assert(s.getValue() == 50);
    s.addValue(10);
    assert(s.getValue() == 60);
    s.setValue(0);
    assert(s.getValue() == 0);
    std::cout << "Test passed\n";
}
