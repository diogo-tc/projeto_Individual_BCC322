#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow {
protected:
    System* source;
    System* target;

public:
    Flow();                       
    Flow(const Flow& other);      
    virtual ~Flow();              

    void setSource(System* s);
    void setTarget(System* t);

    System* getSource() const;
    System* getTarget() const;

    virtual double equation() = 0; // método abstrato
};

#endif
