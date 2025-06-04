#include "physicsengine.h"
#include "player.h"
#include "enemy.h"
#include <QDebug>

PhysicsEngine::PhysicsEngine()
{
    // Crear modelos físicos predefinidos
    PhysicsModel *gravity = new PhysicsModel("gravity", "F = m*g");
    PhysicsModel *parabolic = new PhysicsModel("parabolic", "y = y0 + v0*t + 0.5*a*t^2");
    PhysicsModel *oscillatory = new PhysicsModel("oscillatory", "x = A*sin(w*t)");
    PhysicsModel *friction = new PhysicsModel("friction", "F = -u*N*v");
    
    // Añadir modelos a la lista
    models.append(gravity);
    models.append(parabolic);
    models.append(oscillatory);
    models.append(friction);
}

PhysicsEngine::~PhysicsEngine()
{
    // Liberar memoria de los modelos
    for (PhysicsModel *model : models) {
        delete model;
    }
    models.clear();
}

void PhysicsEngine::applyPhysics(QGraphicsItem *entity)
{
    // Aplicar física según el tipo de entidad
    Player *player = dynamic_cast<Player*>(entity);
    if (player) {
        // Aplicar gravedad al jugador
        QPointF velocity = player->getVelocity();
        
        // Aplicar fricción en el suelo
        if (player->y() >= player->scene()->height() - player->pixmap().height()) {
            // Está en el suelo, aplicar fricción
            if (velocity.x() > 0) {
                velocity.setX(qMax(0.0, velocity.x() - 0.2));
            } else if (velocity.x() < 0) {
                velocity.setX(qMin(0.0, velocity.x() + 0.2));
            }
        }
        
        player->setVelocity(velocity);
        player->move();
        return;
    }
    
    Enemy *enemy = dynamic_cast<Enemy*>(entity);
    if (enemy) {
        // Los enemigos ya tienen su propia física en su método move()
        enemy->act();
        return;
    }
}

void PhysicsEngine::addModel(PhysicsModel *model)
{
    models.append(model);
}