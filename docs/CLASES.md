# Documentación de Clases y Archivos

## main.cpp
- **Función principal**: Inicializa la aplicación Qt y muestra la ventana principal (`MainWindow`).

## mainwindow.cpp / mainwindow.h / mainwindow.ui
- **MainWindow**: Ventana principal del juego.
  - Gestiona los niveles, la escena gráfica, los sprites y la lógica de avance.
  - Maneja los eventos de teclado para mover a Goku (`A`, `D`, `W`, `X`).
  - Métodos clave: `setupLevel1`, `setupLevel2`, `setupLevel3`, `keyPressEvent`, `updateLevel1Timer`.
  - Usa `QGraphicsScene` y `QGraphicsView` para renderizar el juego.
  - Botones: Play y Exit.

## Game.cpp / Game.h
- Clase `Game`: Estructura general del juego, mantiene el nivel actual, jugador, enemigos y motor de físicas.
  - Métodos: `startGame`, `nextLevel`, `update`.

## Level.cpp / Level.h
- Clase `Level`: Representa un nivel del juego (estructura, descripción, número).

## Player.cpp / Player.h
- Clase `Player`: Lógica del jugador (atributos, movimiento, acciones).

## Enemy.cpp / Enemy.h
- Clase `Enemy`: Lógica de enemigos genéricos.

## PlayerItem.cpp / PlayerItem.h
- Clase `PlayerItem`: Sprite y lógica visual de Goku en la escena.

## TigerItem.cpp / TigerItem.h
- Clase `TigerItem`: Sprite y lógica visual del tigre enemigo.

## FruitItem.h
- Clase `FruitItem`: Sprite y lógica visual de la fruta.

## PhysicsEngine.cpp / PhysicsEngine.h
- Clase `PhysicsEngine`: Motor de físicas, gestiona colisiones y movimiento.

## PhysicsModel.cpp / PhysicsModel.h
- Clase base para modelos físicos.

## Objective.cpp / Objective.h
- Clase `Objective`: Objetivos de cada nivel.

## Vector2D.h
- Utilidad para operaciones con vectores 2D.

## resources.qrc
- Archivo de recursos Qt: lista todas las imágenes usadas en el juego.

## Img/
- Carpeta con todos los sprites y fondos usados en el juego. 