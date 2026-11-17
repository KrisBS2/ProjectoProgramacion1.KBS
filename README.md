# Projecto de Programacion 1

Estudiante: Kristopher Bermudez Salas

Cedula: 208730230


# Explicación Simple de las Clases del Sistema

# 1. Clases de Personal (Herencia y Polimorfismo)
* `Empleado` (Clase Abstracta): Es la base de todo el personal. Define los datos comunes (cédula, nombre, salario base, horas extra) y declara métodos virtuales que las clases hijas deben implementar obligatoriamente.
* `Medico`, `Enfermero` y `Administrativo` (Clases Derivadas): Heredan de `Empleado` y aplican polimorfismo calculando bonificaciones específicas según su rol (por ejemplo, el médico según sus guardias, el enfermero por sus turnos nocturnos y el administrativo por su bono de productividad).

# 2. Estructura Organizacional
* `Departamento`: Representa las áreas operativas del hospital (como Urgencias o Pediatría). Contiene su propio catálogo de puestos de trabajo.
* `Puesto`: Define los cargos oficiales disponibles y su salario base sugerido dentro de un departamento.

# 3. Transacciones y Control
* `ComprobantePago`:** Almacena el historial y desglose detallado de los cálculos salariales (salario bruto, deducciones de ley y salario neto) generados para un empleado en una fecha específica.
* `Listas y Nodos` (`Nodo*` y `Lista*`): Funcionan como un solo concepto. Son estructuras de datos dinámicas construidas manualmente con punteros (`new`/`delete`) para almacenar, buscar y eliminar elementos en memoria sin depender de la STL. Cada `Lista` administra una cadena de `Nodos` que guardan la información.

# 4. Núcleo y Interfaz
* `SistemaHospitalario`:** Es el cerebro del programa. Centraliza toda la lógica de negocio y se encarga de leer y escribir automáticamente en los archivos de texto (`.txt`) para que los datos no se pierdan al cerrar el programa.
* `Validador`:** Módulo de seguridad encargado de blindar la consola para que, si el usuario ingresa una letra en lugar de un número, el programa no colapse.

* Al iniciar el programa, verás el menú principal en la consola de la siguiente manera:

==================================================
  SISTEMA DE GESTION DE PLANILLA HOSPITALARIA  
==================================================
1. Gestion de Departamentos y Puestos
2. Gestion de Personal (Empleados)
3. Gestion de Planilla y Pagos
0. Guardar y Salir
==================================================
Seleccione una opcion:
