#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include <iostream>
#include <cmath>   
#include <cassert> 

class FlowTaxaSimples : public Flow {
private:
    System* sistemaInfluencia; 
    double taxa;
public:
    FlowTaxaSimples(std::string name, double taxa, System* influencia) : Flow(name) 
    {
        this->taxa = taxa;
        this->sistemaInfluencia = influencia;
    }

    FlowTaxaSimples(const FlowTaxaSimples& other) : Flow(other.name) {
        this->taxa = other.taxa;
        this->sistemaInfluencia = other.sistemaInfluencia;
    }
    FlowTaxaSimples& operator=(const FlowTaxaSimples& other) {
        if (this == &other) return *this;
        Flow::operator=(other); 
        this->taxa = other.taxa;
        this->sistemaInfluencia = other.sistemaInfluencia;
        return *this;
    }

    double execute() override {
        return taxa * sistemaInfluencia->getValue();
    }
};

class LogisticalFlow : public Flow {
private:
    System* p2; 
public:
    LogisticalFlow(std::string name, System* p2) : Flow(name) {
        this->p2 = p2;
    }

    LogisticalFlow(const LogisticalFlow& other) : Flow(other.name) {
        this->p2 = other.p2;
    }
    LogisticalFlow& operator=(const LogisticalFlow& other) {
        if (this == &other) return *this;
        Flow::operator=(other);
        this->p2 = other.p2;
        return *this;
    }

    double execute() override {
        double val = p2->getValue();
        return 0.01 * val * (1 - val / 70.0);
    }
};


void exponentialFuncionalTest() {
    Model m("Exponencial");
    System pop1("pop1", 100.0);
    System pop2("pop2", 0.0);
    
    // Configuração do fluxo
    FlowTaxaSimples f_exp("exponencial", 0.01, &pop1);
    f_exp.connectSource(&pop1);
    f_exp.connectDestination(&pop2);

    // Adicionando ao modelo
    m.add(&pop1);
    m.add(&pop2);
    m.add(&f_exp);

    // Execução
    m.execute(0, 100, 1);

    
    std::cout << "Executando Teste Exponencial..." << std::endl;
    assert(std::abs(pop1.getValue() - 36.6032) < 0.0001);
    assert(std::abs(pop2.getValue() - 63.3968) < 0.0001);
    std::cout << "Teste Exponencial PASSOU!" << std::endl;
}

void logisticalFuncionalTest() {
    Model m("Logistico");
    System p1("p1", 100.0);
    System p2("p2", 10.0); 

    // Configuração do fluxo
    LogisticalFlow f_log("logistica", &p2);
    f_log.connectSource(&p1);
    f_log.connectDestination(&p2);

    // Adicionando ao modelo
    m.add(&p1);
    m.add(&p2);
    m.add(&f_log);

    // Execução
    m.execute(0, 100, 1);

    std::cout << "Executando Teste Logistico..." << std::endl;
    assert(std::abs(p1.getValue() - 88.2167) < 0.0001);
    assert(std::abs(p2.getValue() - 21.7833) < 0.0001);
    std::cout << "Teste Logistico PASSOU!" << std::endl;
}

void complexFuncionalTest() {
    Model m("Complexo");
    System q1("Q1", 100);
    System q2("Q2", 0);
    System q3("Q3", 100);
    System q4("Q4", 0);
    System q5("Q5", 0);

    // Criando os fluxos
    FlowTaxaSimples v("v", 0.01, &q4);
    FlowTaxaSimples g("g", 0.01, &q1);
    FlowTaxaSimples f("f", 0.01, &q1);
    FlowTaxaSimples r("r", 0.01, &q2);
    FlowTaxaSimples u("u", 0.01, &q3);
    FlowTaxaSimples t("t", 0.01, &q2);

    // Conectando e adicionando tudo
    v.connectSource(&q4); v.connectDestination(&q1);
    g.connectSource(&q1); g.connectDestination(&q3);
    f.connectSource(&q1); f.connectDestination(&q2);
    r.connectSource(&q2); r.connectDestination(&q5);
    u.connectSource(&q3); u.connectDestination(&q4);
    t.connectSource(&q2); t.connectDestination(&q3);

    m.add(&q1); m.add(&q2); m.add(&q3); m.add(&q4); m.add(&q5);
    m.add(&v); m.add(&g); m.add(&f); m.add(&r); m.add(&u); m.add(&t);

    // Execução
    m.execute(0, 100, 1);

    
    std::cout << "Executando Teste Complexo..." << std::endl;
    assert(std::abs(q1.getValue() - 31.8513) < 0.0001);
    assert(std::abs(q2.getValue() - 18.4003) < 0.0001);
    assert(std::abs(q3.getValue() - 77.1143) < 0.0001);
    assert(std::abs(q4.getValue() - 56.1728) < 0.0001);
    assert(std::abs(q5.getValue() - 16.4612) < 0.0001);
    std::cout << "Teste Complexo PASSOU!" << std::endl;
}