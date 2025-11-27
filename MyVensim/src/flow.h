#ifndef FLOW_H
#define FLOW_H

#include "system.h"

/**
 * @class Flow
 * @brief Abstract class that represents a flow between two systems.
 *
 * The Flow class defines the basic structure for flows used in the model.
 * Each flow has a source system and a target system, as well as an abstract
 * equation() method that must be implemented by subclasses to calculate
 * the transferred value.
 */
class Flow {
protected:
    /**
     * @brief Pointer to the flow's source system.
     */
    System* source;

    /**
     * @brief Pointer to the flow's target system.
     */
    System* target;

public:
    /**
     * @brief Default constructor for the Flow class.
     *
     * Initializes a flow with no connected systems.
     */
    Flow();

    /**
     * @brief Copy constructor.
     * @param other Flow object to be copied.
     */
    Flow(const Flow& other);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Flow();

    /**
     * @brief Sets the source system.
     * @param s Pointer to the source system.
     */
    void setSource(System* s);

    /**
     * @brief Sets the target system.
     * @param t Pointer to the target system.
     */
    void setTarget(System* t);

    /**
     * @brief Gets the source system.
     * @return Pointer to the source system.
     */
    System* getSource() const;

    /**
     * @brief Gets the target system.
     * @return Pointer to the target system.
     */
    System* getTarget() const;

    /**
     * @brief Abstract method that calculates the value transferred by the flow.
     *
     * Must be implemented by derived classes.
     * @return Numerical value of the flow equation.
     */
    virtual double equation() = 0;
};

#endif