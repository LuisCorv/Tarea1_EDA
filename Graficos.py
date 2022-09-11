
import matplotlib.pyplot as plt
import numpy as np

#es 100000 para tamaños pequeños y es 1000000 para tamaños grandes
#El eje X es el del tamaño del arreglo y el Y el del tiempo

#Tiempos de arreglos para conjuntos pequeños
Insercion_p=[0,0,0,0,0,0,0,0,0,0]
Seleccion_p=[63,272,618,1086,1661,2386,3277,4263,5339,6593]
QuickSort_p=[1,2,4,5,6,8,9,10,12,14]
MergeSort_p=[1,2,3,5,6,7,9,10,11,13]
#Tiempod de arreglos para conjuntos grandes
Insercion_g=[0,1,1,2,2,2,3,3,4,4]
Seleccion_g=[6577,26979,60866,106958,170125,244702,334483,431192,550524,683058]
QuickSort_g=[13,30,46,61,77,93,110,127,145,163]
MergeSort_g=[13,28,43,59,74,91,107,123,139,156]
RadixSort=[0,0,0,0,0,0,1,1,1,1]


#Grafico de alg. generales y pequeños
x = np.linspace(0, 100000, 10) 
plt.plot(x, Insercion_p, label='InsertionSort')
plt.plot(x, Seleccion_p , label='SelectionSort')
plt.plot(x, QuickSort_p, label='QuickSort')
plt.plot(x, MergeSort_p, label='MergeSort')
    #Agregamos las etiquetas y añadimos una leyenda.
plt.xlabel('Tamaño del arreglo (n)')
plt.ylabel('Tiempo de Ejecución (ms)')
plt.title("Algoritmos generales de arreglos 'pequeños'")
plt.legend()
plt.show()


#Grafico de alg. generales y grandes
x = np.linspace(0, 1000000, 10) 
plt.plot(x, Insercion_g, label='InsertionSort')
plt.plot(x, Seleccion_g, label='SelectionSort')
plt.plot(x, QuickSort_g , label='QuickSort')
plt.plot(x, MergeSort_g , label='MergeSort')
    #Agregamos las etiquetas y añadimos una leyenda.
plt.xlabel('Tamaño del arreglo (n)')
plt.ylabel('Tiempo de Ejecución (ms)')
plt.title("Algoritmos generales de arreglos 'grandes'")
plt.legend()
plt.show()


#Grafico de alg. especificos y grandes
x = np.linspace(0, 1000000, 10) 
plt.plot(x, Insercion_g, label='InsertSort')
plt.plot(x, RadixSort, label='RadixSort')
    #Agregamos las etiquetas y añadimos una leyenda.
plt.xlabel('Tamaño del arreglo (n)')
plt.ylabel('Tiempo de Ejecución (ms)')
plt.title("Algoritmos Especificos")
plt.legend()
plt.show()



