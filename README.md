# GameDB

Juego arcade/plataformas inspirado en Dragon Ball, desarrollado en C++ y Qt. Controla a Goku, recoge frutas, esquiva enemigos y balas, y rescata a Bulma a través de varios niveles.

---

## Tabla de Contenidos

- [Resumen General](#resumen-general)
- [Estructura de Carpetas y Archivos](#estructura-de-carpetas-y-archivos)
- [Descripción de Clases y Archivos](#descripción-de-clases-y-archivos)
- [Flujo Principal del Programa](#flujo-principal-del-programa)
- [Recursos Gráficos](#recursos-gráficos)
- [Guía de Compilación y Ejecución](#guía-de-compilación-y-ejecución)
- [Dependencias](#dependencias)
- [Controles](#controles)
- [Problemas y Soluciones](#problemas-y-soluciones)
- [Mejoras Futuras](#mejoras-futuras)
- [Documentación Adicional](#documentación-adicional)

---

## Resumen General

GameDB es un juego de plataformas donde el jugador controla a Goku. El objetivo es superar tres niveles:
- **Nivel 1:** Recoge una fruta y evita al tigre.
- **Nivel 2:** Recoge la fruta y rescata a Bulma.
- **Nivel 3:** Esquiva balas, recoge la fruta y gana el juego.

El juego utiliza Qt para la interfaz gráfica y la gestión de escenas, sprites y eventos.

---

## Estructura de Carpetas y Archivos

```
GameDB/
├── main.cpp                # Punto de entrada
├── mainwindow.cpp/h        # Lógica y UI principal
├── mainwindow.ui           # Diseño visual (Qt Designer)
├── Game.cpp/h              # Lógica general del juego
├── Level.cpp/h             # Representación de niveles
├── Player.cpp/h            # Lógica del jugador (Goku)
├── Enemy.cpp/h             # Lógica de enemigos
├── PlayerItem.cpp/h        # Sprite y lógica visual del jugador
├── TigerItem.cpp/h         # Sprite y lógica visual del tigre
├── FruitItem.h             # Sprite y lógica visual de la fruta
├── PhysicsEngine.cpp/h     # Motor de físicas
├── PhysicsModel.cpp/h      # Modelo físico base
├── Objective.cpp/h         # Objetivos de nivel
├── Vector2D.h              # Utilidad para vectores 2D
├── resources.qrc           # Archivo de recursos Qt
├── Img/                    # Imágenes y sprites
├── GameDB.pro              # Proyecto Qt
└── build/                  # Carpeta de compilación
```

---

## Descripción de Clases y Archivos

Ver [`docs/CLASES.md`](docs/CLASES.md) para una descripción detallada de cada clase y archivo.

---

## Flujo Principal del Programa

1. **Inicio:**
   - Se ejecuta `main.cpp`, que crea un `QApplication` y muestra `MainWindow`.
2. **Menú Principal:**
   - Botones "Play" y "Exit". Al presionar "Play", inicia el juego.
3. **Niveles:**
   - **Nivel 1:** Fondo, piso, Goku, fruta y tigre. Temporizador de 30s. Si el tigre atrapa a Goku, pierdes. Si recoges la fruta, pasas al nivel 2.
   - **Nivel 2:** Fondo, piso, Goku, fruta y Bulma. Al recoger la fruta, rescatas a Bulma y pasas al nivel 3.
   - **Nivel 3:** Fondo, piso, Goku, fruta y balas. Si una bala golpea a Goku, pierdes. Si recoges la fruta, ganas.
4. **Controles:**
   - `A`: Izquierda
   - `D`: Derecha
   - `W`: Saltar
   - `X`: Atacar
5. **Colisiones y lógica:**
   - Timers y eventos para actualizar la escena, mover enemigos y balas, y detectar colisiones.

---

## Recursos Gráficos

- Sprites y fondos en `Img/` y referenciados en `resources.qrc`.
- Ejemplos:
  - `Img/Mapas/1/Fondo.jpg` — Fondo
  - `Img/Goku/Goku.png` — Goku
  - `Img/Enemigos/Tigre.png` — Tigre
  - `Img/Bulma/Bulma.png` — Bulma
  - `Img/Elementos/Fruta.png` — Fruta
  - `Img/Elementos/Bala.png` — Balas

---

## Guía de Compilación y Ejecución

1. **Requisitos:**
   - Qt 5 o 6 (Widgets)
   - Compilador C++ compatible (MinGW, MSVC)
2. **Compilación:**
   - Abre `GameDB.pro` en Qt Creator y compila.
   - O desde terminal:
     ```sh
     qmake GameDB.pro
     make
     ./GameDB
     ```

---

## Dependencias

- Qt (Widgets, Core, GUI)
- C++ estándar (STL)

---

## Controles

- `A`: Mover a la izquierda
- `D`: Mover a la derecha
- `W`: Saltar
- `X`: Atacar

---

## Problemas y Soluciones

Ver [`docs/PROBLEMAS.md`](docs/PROBLEMAS.md) para un listado de problemas enfrentados durante el desarrollo y cómo se resolvieron.

---

## Mejoras Futuras

- Añadir más niveles y enemigos.
- Mejorar física y animaciones.
- Guardar progreso del jugador.
- Soporte para joystick o controles móviles.
- Efectos de sonido y música.

---

## Documentación Adicional

- [`docs/CLASES.md`](docs/CLASES.md): Descripción detallada de clases y archivos.
- [`docs/PROBLEMAS.md`](docs/PROBLEMAS.md): Problemas enfrentados y soluciones.
- [`docs/FLUJO_DETALLADO.md`](docs/FLUJO_DETALLADO.md): Explicación detallada del flujo de cada nivel y eventos.
- [`docs/RECURSOS.md`](docs/RECURSOS.md): Detalle de recursos gráficos y su uso. 