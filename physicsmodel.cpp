#include "physicsmodel.h"
#include <iostream>

PhysicsModel::PhysicsModel() : name(""), formula("") {}

PhysicsModel::PhysicsModel(const std::string& name, const std::string& formula)
    : name(name), formula(formula) {}

std::string PhysicsModel::getName() const {
    return name;
}

std::string PhysicsModel::getFormula() const {
    return formula;
}

void PhysicsModel::setName(const std::string& name) {
    this->name = name;
}

void PhysicsModel::setFormula(const std::string& formula) {
    this->formula = formula;
}

void PhysicsModel::simulate() {
    // Esta función se implementará con la lógica específica para cada modelo físico
    // Por ejemplo, para movimiento parabólico, movimiento oscilatorio, etc.
    std::cout << "Simulando modelo físico: " << name << " con fórmula: " << formula << std::endl;
}