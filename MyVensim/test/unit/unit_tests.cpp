/**
 * @file unit_tests.cpp
 * @brief Unit tests for the system components.
 */


#include <iostream>
#include <cassert>
#include "../../src/system.h"

void basicSystemTest() {

    // Test initialization
    System s(50);
    assert(s.getValue() == 50);

    // Test adding value
    s.addValue(10);
    assert(s.getValue() == 60);

    // Test setting value
    s.setValue(0);
    assert(s.getValue() == 0);
    
    std::cout << "====== Test passed ======\n";
}