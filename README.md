# Push Swap

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)]()
[![42](https://img.shields.io/badge/42-black?style=for-the-badge&logo=42&logoColor=white)]()

## 📋 Descripción

**Push Swap** es una implementación del algoritmo de ordenamiento que forma parte del currículo de la escuela de programación 42. El objetivo es ordenar una pila de números enteros utilizando un número mínimo de operaciones específicas, siguiendo las reglas estrictas del proyecto.

### 🎯 Objetivo

Ordenar una pila de números enteros utilizando solo las siguientes operaciones:
- `sa` / `sb` / `ss`: Intercambio (swap)
- `pa` / `pb`: Empujar (push)
- `ra` / `rb` / `rr`: Rotación (rotate)
- `rra` / `rrb` / `rrr`: Rotación inversa (reverse rotate)

### 🔧 Algoritmo

Esta implementación utiliza el **algoritmo Radix Sort** optimizado para minimizar el número de operaciones necesarias. El algoritmo funciona asignando índices a los elementos y utilizando operaciones bitwise para ordenar eficientemente.

## 🚀 Características

- ✅ Implementación completa de todas las operaciones requeridas
- ✅ Algoritmo Radix Sort optimizado
- ✅ Gestión robusta de errores y validación de entrada
- ✅ Soporte para listas de cualquier tamaño
- ✅ Librería Libft incluida
- ✅ Makefile con múltiples targets útiles

## 📁 Estructura del Proyecto

```
push_swap/
├── source/                 # Código fuente
│   ├── main.c             # Punto de entrada
│   ├── lists.c            # Funciones de listas
│   ├── instructions.c     # Operaciones básicas
│   ├── radix.c            # Algoritmo principal
│   ├── checknum.c         # Validación de números
│   ├── savelist.c         # Gestión de listas
│   ├── test.c            # Funciones de testing
│   └── push_swap.h       # Headers
├── libft/                 # Librería Libft
│   ├── ft_*.c            # Funciones de la librería
│   └── libft.h           # Headers de libft
├── Makefile              # Configuración de compilación
└── README.md            # Esta documentación
```

## 🛠️ Instalación y Uso

### Prerrequisitos

- GCC compiler
- Make
- Sistema Unix/Linux

### Compilación

```bash
# Compilar el proyecto
make

# Compilar y ejecutar con argumentos de prueba
make exe

# Limpiar archivos objeto
make clean

# Limpiar todo (incluyendo ejecutable)
make fclean

# Recompilar completamente
make re
```

### Uso

```bash
# Ejecutar con una lista de números
./push_swap 3 1 2 5 4

# Ejemplos de uso:
./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 9 8 7 6 5 4 3 2 1
```

### Entrada

- Una lista de números enteros separados por espacios
- Los números deben ser únicos
- Rango válido: INT_MIN a INT_MAX

## 📊 Ejemplos de Ejecución

### Caso Simple (3 elementos)
```bash
$ ./push_swap 2 1 3
sa
ra

$ ./push_swap 1 2 3
# Lista ya ordenada - no se requieren operaciones
```

### Caso Medio (5 elementos)
```bash
$ ./push_swap 3 1 4 2 5
pb
ra
sa
pa
sa
```

## 🧪 Testing

El proyecto incluye funciones de testing integradas:

```bash
# Ejecutar tests internos
make comp
```

### Tests Incluidos
- ✅ Validación de números duplicados
- ✅ Verificación de listas ya ordenadas
- ✅ Tests con diferentes tamaños de listas
- ✅ Comprobación de todas las operaciones

## 📈 Rendimiento

El algoritmo Radix Sort proporciona un rendimiento excelente:
- **Complejidad temporal**: O(n) en el peor caso
- **Operaciones**: Optimizadas para el menor número posible
- **Escalabilidad**: Eficiente para listas grandes

## 🔧 Operaciones Implementadas

### Operaciones Básicas
| Operación | Descripción | Stack |
|-----------|-------------|-------|
| `sa` | Intercambia los dos primeros elementos de A | A |
| `sb` | Intercambia los dos primeros elementos de B | B |
| `ss` | `sa` y `sb` simultáneamente | A & B |
| `pa` | Toma el primer elemento de B y lo pone en A | A |
| `pb` | Toma el primer elemento de A y lo pone en B | B |

### Operaciones de Rotación
| Operación | Descripción | Stack |
|-----------|-------------|-------|
| `ra` | Primera posición se convierte en la última | A |
| `rb` | Primera posición se convierte en la última | B |
| `rr` | `ra` y `rb` simultáneamente | A & B |
| `rra` | Última posición se convierte en la primera | A |
| `rrb` | Última posición se convierte en la primera | B |
| `rrr` | `rra` y `rrb` simultáneamente | A & B |

## 🏗️ Arquitectura

### Estructura de Datos
```c
typedef struct s_list2 {
    int             number;    // Valor del número
    int             index;     // Índice para el algoritmo
    struct s_list2  *next;     // Siguiente elemento
} t_list2;
```

### Flujo del Algoritmo
1. **Validación**: Verificar números y duplicados
2. **Indexación**: Asignar índices según valores ordenados
3. **Ordenamiento**: Aplicar Radix Sort con operaciones push_swap
4. **Verificación**: Confirmar que la lista está ordenada

## 🤝 Contribuir

1. Fork el proyecto
2. Crea tu rama de características (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## 📝 Autor

**Miguel González Clayton**
- Escuela 42: Madrid
- Email: miggonza@student.42.fr

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## 🙏 Agradecimientos

- Escuela 42 por el proyecto original
- Comunidad de 42 por las optimizaciones y mejoras
- Todos los contribuidores que han trabajado en versiones similares

---

**¡Gracias por revisar este proyecto! 🚀**
