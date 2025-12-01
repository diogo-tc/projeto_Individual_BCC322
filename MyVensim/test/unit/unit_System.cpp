/**
 * @file unit_System.cpp
 * @brief Implementação dos testes unitários da classe System.
 */

#include "unit_System.h"
#include "../../src/system.h"
#include <cassert>

void unit_System_constructor(void) {
    System s1;
    assert(s1.getValue() == 0);

    System s2(10);
    assert(s2.getValue() == 10);
}

void unit_System_destructor(void) {
    // Nada para testar — sem alocação dinâmica
}

void unit_System_getValue(void) {
    System s(27.5);
    assert(s.getValue() == 27.5);
}

void unit_System_setValue(void) {
    System s;
    s.setValue(123.45);
    assert(s.getValue() == 123.45);
}

void unit_System_addValue(void) {
    System s(10);
    s.addValue(5);
    assert(s.getValue() == 15);
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
    unit_System_addValue();
}
