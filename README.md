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
y un solo atributo objetivo (también llamado clase).
(Sergio Ruiz. (2018). El algoritmo K-NN y su importancia en el modelado de datos. 2018, de ANALITICAWEB Sitio web: https://www.analiticaweb.es/algoritmo-knn-modelado-datos)
  Referencias:
  https://www.youtube.com/watch?v=UqYde-LULfs
  https://medium.com/@adi.bronshtein/a-quick-introduction-to-k-nearest-neighbors-algorithm-62214cea29c7
