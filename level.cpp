#include "level.h"
#include <QDebug>

Level::Level(int number) : levelNumber(number)
{
    // Configurar nivel según el número
    switch (levelNumber) {
    case 1:
        description = "Montañas de Goku: Recolección de recursos y caza";
        physics = "gravity";
        break;
    case 2:
        description = "Camino al Encuentro: Puzzles y cooperación con Bulma";
        physics = "parabolic";
        break;
    case 3:
        description = "Aldea del Terror: Combate y rescate de aldeanos";
        physics = "oscillatory";
        break;
    default:
        description = "Nivel desconocido";
        physics = "gravity";
    }
}

Level::~Level()
{
    // Liberar memoria de los objetivos
    for (Objective *objective : objectives) {
        delete objective;
    }
    objectives.clear();
}

void Level::loadLevel()
{
    // Limpiar objetivos anteriores
    for (Objective *objective : objectives) {
        delete objective;
    }
    objectives.clear();
    
    // Crear objetivos según el nivel
    switch (levelNumber) {
    case 1:
        objectives.append(new Objective("Recolectar 3 frutas", false));
        objectives.append(new Objective("Cazar un jabalí", false));
        objectives.append(new Objective("Encontrar la Dragon Ball", false));
        break;
    case 2:
        objectives.append(new Objective("Resolver el puzzle del puente", false));
        objectives.append(new Objective("Ayudar a Bulma a cruzar el río", false));
        objectives.append(new Objective("Encontrar la cápsula de Bulma", false));
        break;
    case 3:
        objectives.append(new Objective("Derrotar a 5 soldados", false));
        objectives.append(new Objective("Rescatar a 3 aldeanos", false));
        objectives.append(new Objective("Derrotar al jefe", false));
        break;
    }
    
    qDebug() << "Nivel" << levelNumber << "cargado:" << description;
    qDebug() << "Física aplicada:" << physics;
    qDebug() << "Objetivos:";
    for (Objective *objective : objectives) {
        qDebug() << " -" << objective->getDescription();
    }
}

bool Level::checkCompletion()
{
    // Verificar si todos los objetivos están completados
    for (Objective *objective : objectives) {
        if (!objective->isCompleted()) {
            return false;
        }
    }
    
    qDebug() << "¡Nivel" << levelNumber << "completado!";
    return true;
}