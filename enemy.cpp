#include "enemy.h"
#include <iostream>

Enemy::Enemy() : type(""), position(Vector2D()), behavior("") {}

Enemy::Enemy(const std::string& type, const Vector2D& position, const std::string& behavior)
    : type(type), position(position), behavior(behavior) {}

std::string Enemy::getType() const {
    return type;
}

Vector2D Enemy::getPosition() const {
    return position;
}

std::string Enemy::getBehavior() const {
    return behavior;
}

void Enemy::setType(const std::string& type) {
    this->type = type;
}

void Enemy::setPosition(const Vector2D& position) {
    this->position = position;
}

void Enemy::setBehavior(const std::string& behavior) {
    this->behavior = behavior;
}

void Enemy::act() {
    // Esta función implementará el comportamiento específico del enemigo
    std::cout << "Enemigo de tipo " << type << " actuando según comportamiento: " << behavior << std::endl;
    
    // Implementación de diferentes comportamientos según el tipo de enemigo
    if (behavior == "patrol") {
        // Movimiento de patrulla (ida y vuelta en un área)
        std::cout << "Patrullando área" << std::endl;
    } else if (behavior == "chase") {
        // Perseguir al jugador
        std::cout << "Persiguiendo al jugador" << std::endl;
    } else if (behavior == "oscillate") {
        // Movimiento oscilatorio (como las abejas mencionadas en la descripción)
        std::cout << "Realizando movimiento oscilatorio" << std::endl;
    } else {
        // Comportamiento por defecto
        std::cout << "Comportamiento estático" << std::endl;
    }
}

void Enemy::attackPlayer() {
    // Esta función implementará el ataque al jugador
    std::cout << "Enemigo de tipo " << type << " atacando al jugador" << std::endl;
    
    // Implementación de diferentes tipos de ataque según el tipo de enemigo
    if (type == "jabalí") {
        std::cout << "Embistiendo al jugador" << std::endl;
    } else if (type == "abeja") {
        std::cout << "Picando al jugador" << std::endl;
    } else if (type == "villano") {
        std::cout << "Lanzando ataque especial" << std::endl;
    } else {
        std::cout << "Ataque genérico" << std::endl;
    }
}