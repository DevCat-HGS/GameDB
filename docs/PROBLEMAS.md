# Problemas Enfrentados y Soluciones

## 1. Manejo de recursos gráficos (Qt Resource System)
**Problema:** Las imágenes no se mostraban en la escena.
**Solución:** Se aseguraron las rutas en `resources.qrc` y se usó el prefijo `:/` al cargar imágenes con `QPixmap`.

## 2. Colisiones no detectadas correctamente
**Problema:** Goku a veces atravesaba la fruta o el tigre sin que se detectara la colisión.
**Solución:** Se revisó el uso de `collidesWithItem` y se ajustaron las posiciones y bounding boxes de los sprites.

## 3. Timers y actualización de escena
**Problema:** Los timers no actualizaban la escena o se solapaban.
**Solución:** Se usaron `QTimer` correctamente, asegurando que cada timer se conectara/desconectara y se destruyera al cambiar de nivel.

## 4. Gestión de memoria y punteros
**Problema:** Fugas de memoria al crear y destruir escenas y sprites.
**Solución:** Se eliminaron manualmente los objetos de la escena y se usó `delete` para limpiar memoria.

## 5. Eventos de teclado no capturados
**Problema:** Goku no respondía a las teclas.
**Solución:** Se sobreescribió `keyPressEvent` en `MainWindow` y se verificó el foco de la ventana.

## 6. Problemas de compatibilidad Qt (versiones)
**Problema:** El proyecto no compilaba en algunas versiones de Qt.
**Solución:** Se revisó el archivo `.pro` y se usaron módulos compatibles (`widgets`, `core`, `gui`).

## 7. Rutas relativas y absolutas
**Problema:** El juego no encontraba imágenes al mover la carpeta del proyecto.
**Solución:** Se centralizó el uso de rutas relativas y el sistema de recursos de Qt.

## 8. Dificultad para ajustar físicas y movimiento
**Problema:** El movimiento de Goku y los enemigos era poco natural.
**Solución:** Se ajustaron los valores de desplazamiento y timers para suavizar el movimiento.

---

Si surgen nuevos problemas, documentarlos aquí para futuras referencias. 