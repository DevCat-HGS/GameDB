# Flujo Detallado del Juego

## Nivel 1
- **Inicio:** Se crea la escena con fondo, piso, Goku, fruta y tigre.
- **Timers:**
  - Timer de cuenta regresiva (30s).
  - Timer para mover al tigre hacia Goku.
  - Timer para actualizar la escena.
- **Eventos:**
  - Si el tigre colisiona con Goku, el juego termina.
  - Si Goku recoge la fruta, se detiene el timer y se pasa al nivel 2.

## Nivel 2
- **Inicio:** Se crea la escena con fondo, piso, Goku, fruta y Bulma.
- **Timers:**
  - Timer para detectar colisión entre Goku y la fruta.
- **Eventos:**
  - Si Goku recoge la fruta, se muestra mensaje de rescate de Bulma y se pasa al nivel 3.

## Nivel 3
- **Inicio:** Se crea la escena con fondo, piso, Goku, fruta y balas.
- **Timers:**
  - Timer para generar balas (vertical y horizontal).
  - Timer para mover balas y detectar colisiones.
  - Timer para detectar colisión entre Goku y la fruta.
- **Eventos:**
  - Si una bala golpea a Goku, el juego termina.
  - Si Goku recoge la fruta, gana el juego.

## Controles y Eventos Globales
- `A`: Mover a la izquierda
- `D`: Mover a la derecha
- `W`: Saltar
- `X`: Atacar
- Todos los eventos de teclado se gestionan en `keyPressEvent` de `MainWindow`.

## Transiciones
- Las transiciones entre niveles se realizan con `QTimer::singleShot` para evitar bloqueos y limpiar la escena anterior.
- Se eliminan y recrean los objetos de la escena en cada transición. 