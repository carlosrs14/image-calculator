# Image Calculator - Procesamiento Manual de Imágenes

Una aplicación interactiva en C++ que implementa operaciones aritméticas y lógicas sobre imágenes de forma manual (sin usar funciones matemáticas de OpenCV), utilizando Qt6 para la interfaz de usuario.

## Características Principales

- **Procesamiento Manual**: Todas las operaciones están implementadas con bucles `for` anidados y acceso directo a píxeles, evitando las abstracciones matemáticas de alto nivel de OpenCV para fines educativos y de control total.
- **Interfaz Gráfica**: Construida con Qt6, permitiendo cargar imágenes A y B de forma independiente y seleccionar operaciones desde un menú.
- **Operaciones por Canales**: Soporte para imágenes en color (BGR) procesando cada canal individualmente.

## Estructura del Proyecto

- `include/`: Definiciones de las funciones de procesamiento.
- `src/`: Lógica de la aplicación e implementación manual de algoritmos.
- `images/`: Recursos de prueba.

## Requisitos

- **OpenCV 4.x**: Utilizado únicamente para carga (`imread`), guardado (`imwrite`) y visualización (`imshow`) de imágenes.
- **Qt6**: Para la interfaz gráfica de usuario.
- **CMake 3.10+**
- **Compilador C++17**

## Operaciones Implementadas

### Aritméticas (Manuales)
- **Suma**: Adición de píxeles con truncamiento (clamping) a 255.
- **Resta**: Sustracción de píxeles con límite inferior en 0.
- **Multiplicación**: Basada en normalización (escala de 0 a 1).
- **División**: Escalado de valores basado en la relación entre píxeles.

### Lógicas y Procesamiento (Manuales)
- **AND / OR / XOR**: Operaciones bit a bit entre imágenes.
- **Negativo**: Inversión completa de colores.
- **Escala de Grises**: Conversión ponderada (Luma).
- **Umbralización (Threshold)**: Segmentación binaria.
- **Brillo y Contraste**: Ajustes lineales manuales.

## Compilación y Ejecución

```bash
mkdir build && cd build
cmake ..
make
./app
```

## Uso de la App

1. Cargar la **Imagen A** (obligatoria).
2. Cargar la **Imagen B** (requerida para operaciones binarias como suma o AND).
3. Seleccionar la operación en el menú desplegable.
4. Presionar "Calculate & Show" para ver el resultado.
