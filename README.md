# TareaProgramada2
Tarea Programada 2
Calculadora vectorial en ASM y C++

Se requiere una calculadora vectorial que realice distintas operaciones. Se puede tener dos vectores y se opera con ellos. Los vectores contienen numeros con punto flotante. Se puede escoger usar registros de 128 bytes (XMM), o de 256  bytes (YMM) o  de  512  bytes (ZMM). Lo que se quiere es poder realizar una misma operacion con varios numeros al mismo tiempo.

Se utilizan las operaciones para vectores de asm, para suma "vaddps", para resta "vsubps", para division "vdivps", para multiplicacion "vmulps", ...

Las operaciones se realizan en lenguaje ensamblador, mientras las demas partes del programa son en c++ para facilitar su implementacion y visualizacion.

El c++ existen las variables vector1, vector2, resultado, que corresponden al primer vector, segundo vector, y el resultado de operar los dos vectores.

Existe un procedimiento en ensamblador por cada una de las operaciones a realizar, para un total de 6 procedimientos.

- Detalles importantes de la implementación.
- Datos de prueba utilizados.
- Listados, si los hubiere.
- Análisis de resultados (indicando grado de funcionamiento) 
- Breve Guía del Usuario.

Integrantes:
- Erick Murillo Solís
- Javier Molina Herrera
- Roger Lopez Brenes
- Isabela Rodriguez Rocha
- Carlos Solorzano Cerdas

