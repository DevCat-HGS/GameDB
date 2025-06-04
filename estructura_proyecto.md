# Estructura del Proyecto Dragon Ball Game

## Descripción General
Este proyecto implementa un juego basado en Dragon Ball, específicamente en el capítulo 'Secret of the Dragon Ball'. El juego consta de tres niveles con diferentes mecánicas físicas y objetivos.

## Estructura de Clases
Siguiendo el diagrama UML proporcionado:

- **Game**: Clase principal que controla el flujo del juego
  - Atributos: currentLevel, player, enemies, physicsEngine
  - Métodos: startGame(), nextLevel(), update()

- **Player (Goku)**: Representa al personaje principal
  - Atributos: name, position, velocity, health
  - Métodos: move(), attack(), collectItem()

- **Enemy**: Representa a los enemigos del juego
  - Atributos: type, position, behavior
  - Métodos: act(), attackPlayer()

- **PhysicsEngine**: Motor de física del juego
  - Atributos: models (lista de PhysicsModel)
  - Métodos: applyPhysics(entity)

- **PhysicsModel**: Modelos físicos específicos
  - Atributos: name, formula
  - Métodos: simulate()

- **Level**: Representa cada nivel del juego
  - Atributos: levelNumber, description, objectives, physics
  - Métodos: loadLevel(), checkCompletion()

- **Objective**: Objetivos a completar en cada nivel
  - Atributos: description, completed
  - Métodos: check()

## Estructura de Carpetas
- **/images**: Contiene todos los sprites del juego
  - **/backgrounds**: Fondos para cada nivel
  - **/characters**: Sprites de personajes (Goku, Bulma)
  - **/enemies**: Sprites de enemigos
  - **/items**: Sprites de objetos coleccionables

## Niveles del Juego
1. **Montañas de Goku**: Recolección de recursos y caza
2. **Camino al Encuentro**: Puzzles y cooperación con Bulma
3. **Aldea del Terror**: Combate y rescate de aldeanos

## Implementación de Físicas
- Movimiento parabólico (saltos)
- Movimiento oscilatorio (enemigos)
- Colisiones dinámicas
- Trayectorias de objetos lanzados
- Propagación radial (explosiones)

## Interfaz de Usuario
- Pantalla principal con botón de inicio
- HUD durante el juego mostrando vida, objetos recolectados
- Menú de pausa

Este documento sirve como guía para la implementación del proyecto.