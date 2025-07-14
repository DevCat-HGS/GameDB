# Recursos Gráficos del Juego

## Ubicación
Todos los recursos gráficos están en la carpeta `Img/` y se referencian en el archivo `resources.qrc`.

## Listado de Recursos

- `Img/Mapas/1/Fondo.jpg` — Fondo de los niveles
- `Img/Mapas/1/Piso.jpg` — Piso de los niveles
- `Img/Goku/Goku.png` — Sprite principal de Goku
- `Img/Goku/Goku_Saltar.png` — Sprite de Goku saltando
- `Img/Goku/Goku_Ataca.png` — Sprite de Goku atacando
- `Img/Elementos/Fruta.png` — Sprite de la fruta
- `Img/Enemigos/Tigre.png` — Sprite del tigre
- `Img/Enemigos/Tigre_Ataca.png` — Sprite del tigre atacando
- `Img/Bulma/Bulma.png` — Sprite de Bulma
- `Img/Bulma/Bulma_Salvar.png` — Sprite de Bulma a rescatar
- `Img/Elementos/Bala.png` — Sprite de las balas

## Cómo se usan en el código
- Todos los recursos se cargan usando rutas del tipo `:/Img/...` gracias al sistema de recursos de Qt.
- Ejemplo de carga:
  ```cpp
  QPixmap fondoPixmap(":/Img/Mapas/1/Fondo.jpg");
  QGraphicsPixmapItem* fondo = scene->addPixmap(fondoPixmap);
  ```
- El archivo `resources.qrc` debe estar actualizado y listado en el `.pro` para que Qt lo incluya en el binario.

## Notas
- Si se agregan nuevos recursos, deben añadirse tanto a la carpeta como al archivo `resources.qrc`. 