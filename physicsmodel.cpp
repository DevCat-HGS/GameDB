#include "physicsmodel.h"
#include <QDebug>

PhysicsModel::PhysicsModel(const QString &modelName, const QString &modelFormula)
    : name(modelName), formula(modelFormula)
{
}

void PhysicsModel::simulate()
{
    // Implementación básica de simulación según el tipo de modelo
    if (name == "gravity") {
        qDebug() << "Simulando gravedad con fórmula:" << formula;
        // Implementación real dependería de los parámetros específicos
    } else if (name == "parabolic") {
        qDebug() << "Simulando movimiento parabólico con fórmula:" << formula;
        // Cálculos para trayectorias parabólicas
    } else if (name == "oscillatory") {
        qDebug() << "Simulando movimiento oscilatorio con fórmula:" << formula;
        // Cálculos para movimientos oscilatorios
    } else if (name == "friction") {
        qDebug() << "Simulando fricción con fórmula:" << formula;
        // Cálculos para fricción
    }
}