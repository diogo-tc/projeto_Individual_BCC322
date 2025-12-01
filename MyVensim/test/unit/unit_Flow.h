/**
 * @file unit_Flow.h
 * @brief Testes unitários da classe Flow.
 */

#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/// Testa o construtor de Flow.
void unit_Flow_constructor(void);

/// Testa o método setSource().
void unit_Flow_setSource(void);

/// Testa o método setTarget().
void unit_Flow_setTarget(void);

/// Testa o método getSource().
void unit_Flow_getSource(void);

/// Testa o método getTarget().
void unit_Flow_getTarget(void);

/// Executa todos os testes unitários de Flow.
void run_unit_tests_Flow(void);

#endif
