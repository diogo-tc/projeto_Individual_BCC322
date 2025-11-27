#include <iostream>
#include "model.h"
#include "flow.h"
#include "system.h"

class DemoFlow : public Flow {
public:
    double equation() override {
        if (!getSource()) return 0.0;
        return 0.1 * getSource()->getValue();
    }
};

int main() {
    Model m;
    System s1(100), s2(0);
    DemoFlow f;
    f.setSource(&s1);
    f.setTarget(&s2);
    m.add(&s1);
    m.add(&s2);
    m.add(&f);
    m.run(0, 10);
    std::cout << "s1=" << s1.getValue() << " s2=" << s2.getValue() << std::endl;
    return 0;
}
