# Image Calculator

Una biblioteca simple en C++ utilizando OpenCV para realizar operaciones aritméticas y lógicas básicas sobre imágenes.

## Estructura del Proyecto

- `include/`: Archivos de cabecera (.hpp).
  - `aritmethic-operations.hpp`: Declaraciones para resta de imágenes.
  - `logic-operations.hpp`: Declaraciones para operación AND y negativo de imagen.
- `src/`: Implementaciones de la biblioteca (.cpp).
  - `aritmethic-operations.cpp`: Implementación de la resta por canales.
  - `logic-operations.cpp`: Implementación de operaciones lógicas.
  - `main.cpp`: Punto de entrada principal (actualmente configurado con SDL2).
- `images/`: Imágenes de ejemplo para pruebas.

## Requisitos

- OpenCV 4.x
- SDL2 (para la visualización en `main.cpp`)
- Compilador compatible con C++11 o superior

## Operaciones Disponibles

### Aritméticas
- **Substraction**: Resta los valores de los píxeles de dos imágenes canal por canal.

### Lógicas
- **AND**: Realiza un bitwise AND entre dos imágenes.
- **Negative**: Calcula el negativo de una imagen (invirtiendo los valores de los píxeles respecto a MAX_PIX).

## Uso

Para compilar el proyecto (ejemplo básico con g++):

```bash
g++ -Iinclude src/*.cpp -o image-calculator `pkg-config --cflags --libs opencv4 sdl2`
```
