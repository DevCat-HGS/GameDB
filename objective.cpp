#include "objective.h"

Objective::Objective() : description(""), completed(false) {}

Objective::Objective(const std::string& description)
    : description(description), completed(false) {}

std::string Objective::getDescription() const {
    return description;
}

bool Objective::isCompleted() const {
    return completed;
}

void Objective::setDescription(const std::string& description) {
    this->description = description;
}

void Objective::setCompleted(bool completed) {
    this->completed = completed;
}

bool Objective::check() {
    // Esta función se implementará con la lógica específica para verificar si el objetivo se ha completado
    // Por ejemplo, verificar si el jugador ha recolectado todos los objetos necesarios
    // o si ha derrotado a todos los enemigos requeridos
    
    // Por ahora, simplemente devolvemos el estado actual
    return completed;
}