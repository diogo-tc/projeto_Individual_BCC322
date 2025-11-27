#ifndef SYSTEM_H
#define SYSTEM_H

/**
 * @class System
 * @brief Represents a system that stores a numerical value.
 *
 * The System class is responsible for maintaining a value that can be modified
 * directly or incremented. It is used as a fundamental element in
 * dynamic systems modeling.
 */
class System {
private:
    /**
     * @brief Value stored by the system.
     */
    double value;

public:
    /**
     * @brief Canonical constructor.
     * @param v Initial value of the system (default = 0.0).
     */
    System(double v = 0.0);

    /**
     * @brief Canonical copy constructor.
     * @param other Other System object to be copied.
     */
    System(const System& other);

    /**
     * @brief Canonical destructor.
     */
    ~System();

    /**
     * @brief Sets the system's value.
     * @param v New value.
     */
    void setValue(double v);

    /**
     * @brief Gets the system's current value.
     * @return The system's value.
     */
    double getValue() const;

    /**
     * @brief Increments the system's value.
     * @param dv Amount to be added to the current value.
     */
    void addValue(double dv);

    /**
     * @brief Canonical assignment operator.
     * @param other System object to be copied.
     * @return Reference to the current object after assignment.
     */
    const System& operator=(const System& other);
};

#endif