<div align="center">
  
  ## Proyecto Algorítmica 1: Buscaminas
  ### Integrantes: 
  Brenda Alvarado Choque<br/>
  Hugo Apaza Huarcho<br/>
  Vivian Marino Sánchez
    
</div>

### Definición del Proyecto

El proyecto final elegido es un juego de Buscaminas. Este juego utiliza el método FloodFill como base. Implementará FloodFill para que las celdas sin bomba sean reveladas en conjunto si el número de celdas marcadas es equivalente al número de bombas alrededor. Se liberarán las celdas de manera que, habiendo seleccionado una celda:<br/>

<ol>
  
  <li>Se liberen las celdas de alrededor que no estén marcadas.</li>
  <li>Se liberen también las vecinas de una celda $0$ que esté alrededor de la celda que se seleccionó. Esto se llevará a cabo de manera recursiva.</li>
  
</ol>

El juego, como la versión clásica, concluirá una vez que todas las celdas que no contengan una bomba hayan sido liberadas.<br/>

### Controles

Para jugar, debe ingresar 3 dígitos separados por espacios: P, M y N. P será el botón a presionar, donde 0 será 'revelar', 1 'marcar' y 1 sobre una celda marcada 'desmarcar'. M y N son las coordenadas del cuadro con el que se interactuará. M representa la fila seleccionada y N la columna seleccionada.<br/>

### Reglas

Algunas celdas contienen bombas. Aquellas que no, contienen el número de bombas que se encuentran en las celdas a su alrededor. Si revela una bomba, pierde. Si revela todas las celdas sin bombas, gana. Las bombas pueden ser marcadas y las celdas pueden ser reveladas en grupo si se han marcado el número de bombas a su alrededor o si no tiene bombas alrededor.

### Instalación
