#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "system.h"
#include "flow.h"

/**
 * @class Model
 * @brief Represents a model that contains systems and flows.
 *
 * The Model class manages collections of System and Flow objects.
 * It is responsible for storing them, updating their states, and
 * executing the simulation logic over a time interval.
 */
class Model {
private:
    /**
     * @brief List of systems belonging to the model.
     */
    std::vector<System*> systems;

    /**
     * @brief List of flows belonging to the model.
     */
    std::vector<Flow*> flows;

public:
    /**
     * @brief Default constructor.
     */
    Model();

    /**
     * @brief Copy constructor.
     * @param model The Model object to be copied.
     */
    Model(const Model& model);

    /**
     * @brief Destructor.
     */
    ~Model();

    /**
     * @brief Assignment operator.
     * @param model The Model object to be assigned.
     * @return A constant reference to the updated Model object.
     */
    const Model& operator=(const Model& model);

    /**
     * @brief Adds a new System to the model.
     *
     * The pointer is appended to the internal system list without
     * taking ownership or performing validation.
     *
     * @param s Pointer to the System object to be added.
     * @return The same System pointer passed as argument.
     */
    System* add(System* s);

    /**
     * @brief Adds a new Flow to the model.
     *
     * The pointer is appended to the internal flow list without
     * taking ownership or performing validation.
     *
     * @param f Pointer to the Flow object to be added.
     * @return The same Flow pointer passed as argument.
     */
    Flow* add(Flow* f);

    /**
     * @brief Executes the model simulation.
     *
     * The simulation runs from time @p t0 (inclusive)
     * to @p t1 (exclusive), applying Euler’s method to update the systems.
     *
     * @param t0 Initial simulation time.
     * @param t1 Final simulation time (not included).
     * @return `true` if the simulation executed successfully.
     */
    bool run(int t0, int t1);
};

#endif
