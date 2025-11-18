#ifndef SYSTEM_H
#define SYSTEM_H

class System {
private:
    double value;

public:
    // Construtor canônico
    System(double v = 0.0);

    // Construtor de cópia canônico
    System(const System& other);

    // Destrutor canônico
    ~System();

    // Getters e setters
    void setValue(double v);
    double getValue() const;

    void addValue(double dv);

    // Operador de atribuição canônico
    const System& operator=(const System& other);
};

#endif
