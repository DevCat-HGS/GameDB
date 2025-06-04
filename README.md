# Dragon Ball Game: Secret of the Dragon Ball

## Descripción
Este proyecto implementa un juego basado en Dragon Ball, específicamente en el capítulo 'Secret of the Dragon Ball'. El juego está desarrollado en C++ utilizando el framework Qt, y consta de tres niveles con diferentes mecánicas físicas y objetivos.

## Características
- Juego de plataformas 2D con físicas realistas
- Tres niveles con diferentes objetivos y mecánicas
- Personaje principal (Goku) con movimientos y ataques
- Diferentes tipos de enemigos con comportamientos únicos
- Motor de física personalizado con varios modelos físicos

## Niveles del Juego
1. **Montañas de Goku**: Recolección de recursos y caza
2. **Camino al Encuentro**: Puzzles y cooperación con Bulma
3. **Aldea del Terror**: Combate y rescate de aldeanos

## Requisitos
- Qt 5.12 o superior
- Compilador compatible con C++17

## Compilación y Ejecución
1. Abrir el archivo `DragonBallGame.pro` en Qt Creator
2. Configurar el kit de compilación
3. Compilar el proyecto (Ctrl+B)
4. Ejecutar el juego (Ctrl+R)

## Controles
- **Flechas izquierda/derecha**: Mover a Goku
- **Flecha arriba / Espacio**: Saltar
- **Z**: Atacar
- **X**: Recoger objetos

## Estructura del Proyecto
El proyecto sigue una arquitectura orientada a objetos con las siguientes clases principales:

- **Game**: Controla el flujo del juego
- **Player (Goku)**: Representa al personaje principal
- **Enemy**: Representa a los enemigos del juego
- **PhysicsEngine**: Motor de física del juego
- **PhysicsModel**: Modelos físicos específicos
- **Level**: Representa cada nivel del juego
- **Objective**: Objetivos a completar en cada nivel

## Implementación de Físicas
El juego implementa varios modelos físicos:
- Movimiento parabólico (saltos)
- Movimiento oscilatorio (enemigos)
- Colisiones dinámicas
- Fricción y gravedad

## Autor
Desarrollado como proyecto de demostración para GameDB.