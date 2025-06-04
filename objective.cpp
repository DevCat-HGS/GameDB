#include "objective.h"
#include <QDebug>

Objective::Objective(const QString &desc, bool isComplete)
    : description(desc), completed(isComplete)
{
}

bool Objective::check()
{
    // Este método sería llamado para verificar si el objetivo se ha completado
    // En una implementación real, verificaría condiciones específicas del juego
    // Por ahora, simplemente devuelve el estado actual
    
    if (completed) {
        qDebug() << "Objetivo ya completado:" << description;
    } else {
        qDebug() << "Objetivo pendiente:" << description;
    }
    
    return completed;
}