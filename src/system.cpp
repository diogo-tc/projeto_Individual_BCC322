#include "system.h"

//Construtor 
System::System(double v) : value(v) {}

// Construtor de cópia 
System::System(const System& other) : value(other.value) {}

// Destrutor 
System::~System() {}


//Setters e getters 
void System::setValue(double v) {
    value = v;
}

double System::getValue() const {
    return value;
}

void System::addValue(double dv) {
    value += dv;
}

// Operador de atribuição 
const System& System::operator=(const System& other) {
    if (this != &other) {          
        setValue(other.getValue());
    }
    return *this;                  
}
