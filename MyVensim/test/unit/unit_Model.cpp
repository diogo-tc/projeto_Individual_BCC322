/**
 * @file unit_Model.cpp
 * @brief Implementação dos testes unitários da classe Model.
 */

#include "unit_Model.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include <cassert>

// Flow concreto para testes
class TestFlow2 : public Flow {
public:
    double equation() override {
        if (!getSource()) return 0.0;
        return 1.0;  // fluxo sempre move 1 unidade
    }
};

void unit_Model_constructor(void) {
    Model m; // apenas validar que instancia
}

void unit_Model_addSystem(void) {
    Model m;
    System s1(10);
    System s2(20);

    m.add(&s1);
    m.add(&s2);
}

void unit_Model_addFlow(void) {
    Model m;
    TestFlow2 f;
    m.add(&f);
}

void unit_Model_run(void) {
    Model m;
    System s1(10);
    System s2(0);

    TestFlow2 f;
    f.setSource(&s1);
    f.setTarget(&s2);

    m.add(&s1);
    m.add(&s2);
    m.add(&f);

    m.run(0, 5);

    assert(s1.getValue() == 5);
    assert(s2.getValue() == 5);
}

void run_unit_tests_Model(void) {
    unit_Model_constructor();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_run();
}
