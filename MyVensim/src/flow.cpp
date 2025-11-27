/**
 * @file flow.cpp
 * @brief Implementation of the Flow class methods.
 *
 * This file contains the definitions of the functions declared in flow.h,
 * responsible for manipulating the source and target systems of a flow.
 */

#include "flow.h"

Flow::Flow() : source(nullptr), target(nullptr) {}

Flow::Flow(const Flow& other) {
    source = other.source;
    target = other.target;
}

Flow::~Flow() {}

void Flow::setSource(System* s) {
    source = s;
}

void Flow::setTarget(System* t) {
    target = t;
}

System* Flow::getSource() const {
    return source;
}

System* Flow::getTarget() const {
    return target;
}