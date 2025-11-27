/**
 * @file system.cpp
 * @brief Implementation of the System class.
 *
 * This file contains the definitions of the methods responsible for
 * managing the internal value of a system.
 */

#include "system.h"

// Constructor 
System::System(double v) : value(v) {}

// Copy constructor 
System::System(const System& other) : value(other.value) {}

// Destructor 
System::~System() {}


// Setters and getters 
void System::setValue(double v) {
    value = v;
}

double System::getValue() const {
    return value;
}

void System::addValue(double dv) {
    value += dv;
}

// Assignment operator 
const System& System::operator=(const System& other) {
    if (this != &other) {           
        setValue(other.getValue());
    }
    return *this;                   
}