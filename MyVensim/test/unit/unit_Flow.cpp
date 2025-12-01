/**
 * @file unit_Flow.cpp
 * @brief Testes unitários da classe Flow.
 */

#include "unit_Flow.h"
#include "../../src/flow.h"
#include "../../src/system.h"
#include <cassert>

// Classe concreta mínima para testar Flow (já que Flow é abstrata)
class TestFlow : public Flow {
public:
    double equation() override { return 0.0; }
};

void unit_Flow_constructor(void) {
    TestFlow f;
    assert(f.getSource() == nullptr);
    assert(f.getTarget() == nullptr);
}

void unit_Flow_setSource(void) {
    TestFlow f;
    System s(10);
    f.setSource(&s);
    assert(f.getSource() == &s);
}

void unit_Flow_setTarget(void) {
    TestFlow f;
    System s(20);
    f.setTarget(&s);
    assert(f.getTarget() == &s);
}

void unit_Flow_getSource(void) {
    TestFlow f;
    System s(10);
    f.setSource(&s);
    assert(f.getSource()->getValue() == 10);
}

void unit_Flow_getTarget(void) {
    TestFlow f;
    System s(40);
    f.setTarget(&s);
    assert(f.getTarget()->getValue() == 40);
}

void run_unit_tests_Flow(void) {
    unit_Flow_constructor();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_getSource();
    unit_Flow_getTarget();
}
