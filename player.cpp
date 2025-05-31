#include "player.h"
#include <iostream>
#include <algorithm> // Para std::max

Player::Player() : name(""), position(Vector2D()), velocity(Vector2D()), health(100) {}

Player::Player(const std::string& name, const Vector2D& position, const Vector2D& velocity, int health)
    : name(name), position(position), velocity(velocity), health(health) {}

std::string Player::getName() const {
    return name;
}

Vector2D Player::getPosition() const {
    return position;
}

Vector2D Player::getVelocity() const {
    return velocity;
}

int Player::getHealth() const {
    return health;
}

void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::setPosition(const Vector2D& position) {
    this->position = position;
}

void Player::setVelocity(const Vector2D& velocity) {
    this->velocity = velocity;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::move() {
    // Esta función actualizará la posición del jugador según su velocidad
    // En una implementación real, se considerarían las entradas del usuario y la física del juego
    position = position + velocity;
    
    std::cout << name << " se mueve a la posición (" << position.getX() << ", " << position.getY() << ")" << std::endl;
}

void Player::attack() {
    // Esta función implementará el ataque del jugador
    std::cout << name << " realiza un ataque" << std::endl;
    
    // En una implementación real, se verificaría si hay enemigos en el rango de ataque
    // y se les aplicaría daño
}

void Player::collectItem() {
    // Esta función implementará la recolección de ítems
    std::cout << name << " recoge un ítem" << std::endl;
    
    // En una implementación real, se verificaría qué tipo de ítem se recogió
    // y se aplicarían sus efectos (aumentar salud, puntos, etc.)
}

void Player::takeDamage(int amount) {
    // Reduce la salud del jugador
    health = std::max(0, health - amount);
    std::cout << name << " recibe " << amount << " de daño. Salud restante: " << health << std::endl;
    
    if (health <= 0) {
        std::cout << name << " ha sido derrotado" << std::endl;
    }
}

void Player::heal(int amount) {
    // Aumenta la salud del jugador (con un máximo de 100)
    health = std::min(100, health + amount);
    std::cout << name << " recupera " << amount << " de salud. Salud actual: " << health << std::endl;
}

bool Player::isAlive() const {
    return health > 0;
}