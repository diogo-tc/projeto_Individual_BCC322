#include "model.h"

Model::Model() {}
Model::Model(const Model& model) {
    systems = model.systems;
    flows   = model.flows;
}

Model::~Model() {}

// Operador de atribuição 
const Model& Model::operator=(const Model& model) {
    if (this != &model) {          
        systems = model.systems;   
        flows   = model.flows;     
    }
    return *this;                  
}

// Adicionar System 
void Model::add(System* s) {
    systems.push_back(s);
}

//  Adicionar Flow
void Model::add(Flow* f) {
    flows.push_back(f);
}

// Execução da simulação 
void Model::run(int t0, int t1) {
    for (int t = t0; t < t1; ++t) {

        // vetor de deltas – um delta para cada System
        std::vector<double> delta(systems.size(), 0.0);

        // calcula cada fluxo
        for (Flow* f : flows) {
            double amount = f->equation();
            System* s  = f->getSource();
            System* tg = f->getTarget();

            // encontra posição do source e target no vetor de systems
            for (size_t i = 0; i < systems.size(); ++i) {
                if (systems[i] == s) {
                    delta[i] -= amount;
                }
                if (systems[i] == tg) {
                    delta[i] += amount;
                }
            }
        }

        // aplica os deltas simultaneamente
        for (size_t i = 0; i < systems.size(); ++i) {
            systems[i]->addValue(delta[i]);
        }
    }
}
