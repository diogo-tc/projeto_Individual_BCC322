#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

// includes para compilar com os headers/cpps da src 
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    return 0;
}

#endif
