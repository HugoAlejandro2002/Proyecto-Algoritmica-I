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
  <li>Se liberen también las vecinas de una celda 0 que esté alrededor de la celda que se seleccionó. Esto se llevará a cabo de manera recursiva.</li>
  
</ol>

El juego, como la versión clásica, concluirá una vez que todas las celdas que no contengan una bomba hayan sido liberadas.<br/>

### Controles

Para jugar, debe ingresar 3 dígitos separados por espacios: P, M y N. P será el botón a presionar, donde 0 será 'revelar', 1 'marcar' y 1 sobre una celda marcada 'desmarcar'. M y N son las coordenadas del cuadro con el que se interactuará. M representa la fila seleccionada y N la columna seleccionada.<br/>

### Reglas

Algunas celdas contienen bombas. Aquellas que no, contienen el número de bombas que se encuentran en las celdas a su alrededor. Si revela una bomba, pierde. Si revela todas las celdas sin bombas, gana. Las bombas pueden ser marcadas y las celdas pueden ser reveladas en grupo si se han marcado el número de bombas a su alrededor o si no tiene bombas alrededor.

### Instalación

<div align="center">
  
  Primero, ingresar al siguiente [link](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/tree/main/versionFinal). Tras hacer click en el link, se encontrará en un directorio del repositorio de GitHub creado por el grupo. Haga click en el archivo 'buscaminas.zip'.

![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install1.png)
  
  A continuación hacer click en el botón 'Download'.
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install2.png)
  
  Una vez descargado el archivo, ir a la carpeta en que está guardado y hacer click derecho sobre él.
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install3.png)
  
  Entonces, hacer click en la opción 'Extract here' o 'Extraer aquí'.
  
   ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install4.png)
  
  Una vez extraído el archivo, mover la carpeta generada al directorio que se utilice como workspace de Visual Studio Code.
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install5.png)
  
  Para acceder al juego tendrá que seguir las siguientes instrucciones cada vez que lo haga:

Abrir Visual Studio y escribir en la terminal: cd buscaminas
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install6.png)
  
  Por último, escribir en la terminal: .\buscaminas
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install7.png)
  
  Si usted siguió de manera correcta las instrucciones, abrá accedido de manera correcta al juego.
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install8.png)
  
  ### Archivo .exe no funciona
  
  Primero, abrir 'buscaminas.cpp'.
  
   ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install9.png)
  
  Entonces, ir a 'Terminal' y hacer click en 'Run Build Task'.
  
   ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install10.png)
  
  Por último, hacer click en la opción marcada en la siguiente imagen:
  
  ![alt text](https://github.com/HugoAlejandro2002/Proyecto-Algoritmica-I/blob/main/imagenes/install11.png)
  
  De esta manera se abrá sobreescrito el archivo .exe y el programa ya debería funcionar.
  
</div>
