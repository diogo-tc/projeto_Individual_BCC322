/**
 * @file unit_Model.h
 * @brief Testes unitários da classe Model.
 */

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/// Testa o construtor de Model.
void unit_Model_constructor(void);

/// Testa o método add(System*).
void unit_Model_addSystem(void);

/// Testa o método add(Flow*).
void unit_Model_addFlow(void);

/// Testa o método run().
void unit_Model_run(void);

/// Executa todos os testes unitários de Model.
void run_unit_tests_Model(void);

#endif
