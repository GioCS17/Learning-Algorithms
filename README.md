# Learning-Algorithms
Dataset:
http://archive.ics.uci.edu/ml/datasets/heart+disease

Issues:
- La informacion obtenida del Dataset debe ser previamente Depurada

Criterios para depuracion del data en dataset:
- Conservar la data de forma que exista una distribucion de registros del mismo tipo de forma simetrica.
-  

Metodos usados para aprendizaje y prediccion:
- KNN Algorithm
La idea es realmente sencilla: el algoritmo clasifica cada dato nuevo en el grupo que corresponda, según tenga k vecinos más cerca
de un grupo o de otro. Es decir, calcula la distancia del elemento nuevo a cada uno de los existentes, y ordena dichas distancias de 
menor a mayor para ir seleccionando el grupo al que pertenecer. Este grupo será, por tanto, el de mayor frecuencia con menores distancias.

El K-NN es un algoritmo de aprendizaje supervisado, es decir, que a partir de un juego de datos inicial su objetivo será el de clasificar 
correctamente todas las instancias nuevas. El juego de datos típico de este tipo de algoritmos está formado por varios atributos descriptivos 
y un solo atributo objetivo (también llamado clase). \
(Sergio Ruiz. (2018). El algoritmo K-NN y su importancia en el modelado de datos. 2018, de ANALITICAWEB Sitio web: https://www.analiticaweb.es/algoritmo-knn-modelado-datos) \
  Referencias: \
  https://www.youtube.com/watch?v=UqYde-LULfs    \
  https://medium.com/@adi.bronshtein/a-quick-introduction-to-k-nearest-neighbors-algorithm-62214cea29c7   \

- Perceptron Algorithm
El perceptrón es un algoritmo bio inspirado desarrollado por Frank Rosenblatt y es capás de clasificar elementos que sean linealmente separables, generando un hiperplano que separe estos en n  dimensiones. Esto quiere decir, que si dibujamos datos que previamente separamos en clases, digamos una clase C1 y C2 donde C1 son buenos clientes y C2 son malos clientes, el algoritmo únicamente podrá clasificarlos si estos pueden ser separados por un plano. Para ver más sobre el concepto de separabilidad lineal recomiendo leer este artículo: Clasificación Lineal contra No lineal con Python. ¿Por qué un plano? Si cada cliente tuviera tres características, digamos calificación del buró de crédito, edad y compras pasadas en nuestra tienda, entonces los clientes tendrían tres dimensiones. Se pueden agregar n dimensiones, y el si se puede dibujar un hiperplano que atraviese estas n dimensiones, entonces el perceptrón será capáz de clasificar los datos. \
(Jesús Manuel Mager . (2017). El algoritmo del Perceptrón: La primera neurona artifical.. 2018, de Nube Programacion Sitio web: http://eenube.com/index.php/mas-articulos/28-aprendizaje-maquina/102-el-algoritmo-del-perceptron-la-primera-neurona-artifical)
\
 Referencias:\
 https://www.youtube.com/watch?v=8dXYLwPiqME   \
 http://www.lcc.uma.es/~munozp/documentos/modelos_computacionales/temas/Tema4MC-05.pdf  \
