/**
 * @file model.cpp
 * @brief Implementation of the Model class.
 *
 * This file contains the implementation of all Model methods.
 * All public documentation is provided in model.h.
 */

#include "model.h"

Model::Model() {}

Model::Model(const Model& model) {
    systems = model.systems;
    flows   = model.flows;
}

Model::~Model() {}

const Model& Model::operator=(const Model& model) {
    if (this != &model) {
        systems = model.systems;
        flows   = model.flows;
    }
    return *this;
}

System* Model::add(System* s) {
    systems.push_back(s);
    return s;
}

Flow* Model::add(Flow* f) {
    flows.push_back(f);
    return f;
}

bool Model::run(int t0, int t1) {
    for (int t = t0; t < t1; ++t) {
        std::vector<double> delta(systems.size(), 0.0);

        for (Flow* f : flows) {
            double amount = f->equation();
            System* s    = f->getSource();
            System* tg   = f->getTarget();

            for (size_t i = 0; i < systems.size(); ++i) {
                if (systems[i] == s)  delta[i] -= amount;
                if (systems[i] == tg) delta[i] += amount;
            }
        }

        for (size_t i = 0; i < systems.size(); ++i) {
            systems[i]->addValue(delta[i]);
        }
    }

    return true;
}
