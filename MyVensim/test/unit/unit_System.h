/**
 * @file unit_System.h
 * @brief Testes unitários da classe System.
 */

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/// Testa o construtor de System.
void unit_System_constructor(void);

/// Testa o destrutor de System.
void unit_System_destructor(void);

/// Testa o método getValue().
void unit_System_getValue(void);

/// Testa o método setValue().
void unit_System_setValue(void);

/// Testa o método addValue().
void unit_System_addValue(void);

/// Executa todos os testes unitários de System.
void run_unit_tests_System(void);

#endif
