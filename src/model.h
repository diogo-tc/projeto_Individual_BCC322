#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "system.h"
#include "flow.h"

class Model {
private:
    std::vector<System*> systems;   // lista de sistemas
    std::vector<Flow*> flows;       // lista de fluxos

public:
    Model();                          
    Model(const Model& model);        
    ~Model();                       
    const Model& operator=(const Model& model);   

    void add(System* s);
    void add(Flow* f);

    void run(int t0, int t1);
};

#endif
