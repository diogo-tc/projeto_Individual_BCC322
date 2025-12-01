/**
 * @file main.cpp
 * @brief Executa todos os testes unitários do projeto.
 */

#include <iostream>
using namespace std;

#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

int main() {

    cout << "=== Running GLOBAL tests ===\n";
    run_unit_tests_globals();

    cout << "=== Running SYSTEM tests ===\n";
    run_unit_tests_System();

    cout << "=== Running FLOW tests ===\n";
    run_unit_tests_Flow();

    cout << "=== Running MODEL tests ===\n";
    run_unit_tests_Model();

    cout << "\n=== ALL UNIT TESTS PASSED ===\n";
    return 0;
}
