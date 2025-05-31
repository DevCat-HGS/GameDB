# GameDB - Dragon Ball: Secret of the Dragon Ball

Un videojuego basado en el primer capítulo de Dragon Ball, "Secret of the Dragon Ball", desarrollado con Qt Creator y C++.

## Descripción

Este juego está inspirado en el inicio de la icónica serie Dragon Ball, donde Goku, un niño con una fuerza descomunal y una cola de mono, vive en la montaña tras la muerte de su abuelo adoptivo. Su encuentro con Bulma, una joven brillante que busca las míticas Esferas del Dragón, desencadena una aventura épica.

## Niveles del Juego

### Nivel 1: Montañas de Goku
- **Dinámica**: El jugador controla a Goku en su hogar en las montañas. El objetivo es recolectar recursos y cazar para sobrevivir.
- **Físicas**: Movimiento parabólico al saltar, movimiento oscilatorio para enemigos como abejas, fricción en suelo rocoso.
- **Retos**: Recolectar frutas colgantes y derrotar un jabalí.
- **Objetivo**: Preparar provisiones antes de salir de viaje.

### Nivel 2: Camino al Encuentro
- **Dinámica**: Goku se encuentra con Bulma. El jugador debe resolver acertijos para ayudarla a recuperar su cápsula perdida.
- **Físicas**: Trayectorias parabólicas para objetos lanzados, colisiones entre objetos y estructuras, plataformas móviles con movimiento sinusoidal.
- **Retos**: Resolver puzzles para cruzar el río y recuperar una cápsula oculta.
- **Objetivo**: Formar equipo con Bulma y continuar la aventura juntos.

### Nivel 3: Aldea del Terror
- **Dinámica**: Goku y Bulma llegan a una aldea aterrorizada por un villano que busca una Esfera del Dragón.
- **Físicas**: Combate con colisiones dinámicas, explosiones con propagación radial, caída de objetos desde estructuras.
- **Retos**: Derrotar al mini-jefe del nivel y rescatar 3 aldeanos escondidos.
- **Objetivo**: Obtener la primera Esfera del Dragón.

## Estructura del Proyecto

- **Game**: Clase principal que coordina todos los elementos del juego.
- **Player**: Representa al personaje principal (Goku) controlado por el jugador.
- **Enemy**: Representa a los enemigos del juego con diferentes comportamientos.
- **PhysicsEngine**: Gestiona la física del juego aplicando diferentes modelos físicos.
- **PhysicsModel**: Define fórmulas y comportamientos físicos específicos.
- **Level**: Representa los niveles del juego con sus objetivos y física específica.
- **Objective**: Define los objetivos que el jugador debe completar en cada nivel.
- **Vector2D**: Clase utilitaria para representar posiciones y velocidades en 2D.

## Requisitos

- Qt Creator 5.x o superior
- Compilador C++ compatible con C++17

## Compilación y Ejecución

1. Abrir el archivo `GameDB.pro` en Qt Creator.
2. Configurar el kit de compilación adecuado.
3. Compilar el proyecto (Ctrl+B).
4. Ejecutar el juego (Ctrl+R).

## Licencia

Este proyecto está bajo la Licencia MIT. Ver el archivo [LICENSE](LICENSE) para más detalles.