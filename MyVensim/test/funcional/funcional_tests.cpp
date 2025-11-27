/**
 * @file funcional_tests.cpp
 * @brief Functional tests for the model, systems, and flows.
 */

#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include <iostream>
#include <cmath>
#include <cassert>

/**************************************
 *   FLOW FOR EXPONENTIAL / SIMPLE RATE
 **************************************/
class FlowSimpleRate : public Flow {
private:
    System* influenceSystem;
    double rate;

public:
    FlowSimpleRate(double rate, System* influence) : Flow() {
        this->rate = rate;
        this->influenceSystem = influence;
    }

    FlowSimpleRate(const FlowSimpleRate& other) : Flow(other) {
        this->rate = other.rate;
        this->influenceSystem = other.influenceSystem;
    }

    FlowSimpleRate& operator=(const FlowSimpleRate& other) {
        if (this == &other) return *this;
        Flow::operator=(other);
        rate = other.rate;
        influenceSystem = other.influenceSystem;
        return *this;
    }

    double equation() override {
        return rate * influenceSystem->getValue();
    }
};

/**************************************
 *   FLOW FOR LOGISTIC MODEL
 **************************************/
class LogisticalFlow : public Flow {
private:
    System* p2;

public:
    LogisticalFlow(System* p2) : Flow() {
        this->p2 = p2;
    }

    LogisticalFlow(const LogisticalFlow& other) : Flow(other) {
        this->p2 = other.p2;
    }

    LogisticalFlow& operator=(const LogisticalFlow& other) {
        if (this == &other) return *this;
        Flow::operator=(other);
        p2 = other.p2;
        return *this;
    }

    double equation() override {
        double v = p2->getValue();
        return 0.01 * v * (1 - v / 70.0);
    }
};

/**************************************
 *   EXPONENTIAL FUNCTIONAL TEST
 **************************************/
void exponentialFuncionalTest() {
    Model m;

    System pop1(100.0);
    System pop2(0.0);

    FlowSimpleRate f(0.01, &pop1);
    f.setSource(&pop1);
    f.setTarget(&pop2);

    m.add(&pop1);
    m.add(&pop2);
    m.add(&f);

    m.run(0, 100);

    assert(std::abs(pop1.getValue() - 36.6032) < 0.0001);
    assert(std::abs(pop2.getValue() - 63.3968) < 0.0001);

    std::cout << "====== Exponential Test PASSED! ======\n";
}

/**************************************
 *   LOGISTICAL FUNCTIONAL TEST
 **************************************/
void logisticalFuncionalTest() {
    Model m;

    System p1(100.0);
    System p2(10.0);

    LogisticalFlow f(&p2);
    f.setSource(&p1);
    f.setTarget(&p2);

    m.add(&p1);
    m.add(&p2);
    m.add(&f);

    m.run(0, 100);

    assert(std::abs(p1.getValue() - 88.2167) < 0.0001);
    assert(std::abs(p2.getValue() - 21.7833) < 0.0001);

    std::cout << "====== Logistical Test PASSED! ======\n";
}

/**************************************
 *   COMPLEX FUNCTIONAL TEST
 **************************************/
void complexFuncionalTest() {
    Model m;

    System q1(100), q2(0), q3(100), q4(0), q5(0);

    FlowSimpleRate v(0.01, &q4);
    FlowSimpleRate g(0.01, &q1);
    FlowSimpleRate f(0.01, &q1);
    FlowSimpleRate r(0.01, &q2);
    FlowSimpleRate u(0.01, &q3);
    FlowSimpleRate t(0.01, &q2);

    v.setSource(&q4); v.setTarget(&q1);
    g.setSource(&q1); g.setTarget(&q3);
    f.setSource(&q1); f.setTarget(&q2);
    r.setSource(&q2); r.setTarget(&q5);
    u.setSource(&q3); u.setTarget(&q4);
    t.setSource(&q2); t.setTarget(&q3);

    m.add(&q1); m.add(&q2); m.add(&q3); m.add(&q4); m.add(&q5);
    m.add(&v); m.add(&g); m.add(&f); m.add(&r); m.add(&u); m.add(&t);

    m.run(0, 100);

    assert(std::abs(q1.getValue() - 31.8513) < 0.0001);
    assert(std::abs(q2.getValue() - 18.4003) < 0.0001);
    assert(std::abs(q3.getValue() - 77.1143) < 0.0001);
    assert(std::abs(q4.getValue() - 56.1728) < 0.0001);
    assert(std::abs(q5.getValue() - 16.4612) < 0.0001);

    std::cout << "======   Complex Test PASSED! ======\n";
}
