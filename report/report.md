# Algoritmo del par más cercano

- Alejadro David Carillo Padrón
- Aduanich Rodríguez Rodríguez
- Daniel Darias Sánchez  

20/3/2017  

## Problema a resolver
El problema del par más cercano consiste en, dado n puntos sobre un espacio euclídeo, encontrar aquellos dos cuya distancia entre sí sea menor que cualquiera de las otras distancias entre cualesquiera puntos. Para nuestro caso, hemos trabajado con el caso bidimensional al tratarse del más intuitivo de resolver. De esta forma, considerando la siguiente nube de puntos:

![](pics/ejemplo.png)

se debe de encontrar los dos puntos destacados en color rojo. Esto es:

$$ p1, p2 \in Problema : \sqrt{| p1_{x} - p2_{x} |^2 + p1_{y} - p2_{y} |^2 } = min $$

## Técnicas empleadas
Se han empleado dos aproximaciones diferentes para resolver este problema, a saber
**fuerza bruta** y **divide y vencerás**. La utilización de ambas técnicas en este trabajo tiene su justificación en poder establecer comparativas entre las mismas y no obtener únicamente medidas "_descontextualizadas_" del algoritmo tipo divide y vencerás.

- #### Fuerza Bruta
  Tal y como su nombre indica, se trata de uan forma de abordar el problema basada puramente en la potencia de cálculo, empleando algorítmos de presumible escasa calidad y órdenes de complejidad altos.

- #### Divide y Vencerás
  Consiste en tratar de subdividr el problema en subproblemas de menor tamaño hasta llegar a un caso trivial, que puede ser resuelto directamente. Una vez conseguido esto, el proceso se invierte y se van combinando las soluciones a estos subproblemas hasta obtener la solución final.

## Explicación de los algoritmos
- #### Fuerza Bruta
  Tratar de comparar _todas_ las distancias entre _todos_ los puntos del problema de la siguiente forma:

  1. Consideramos todos los puntos del problema como elementos contenidos en un conjunto $V$
  2. Considerar $dmin$ como la distancia máxima posible en el plano
  2. Para cada elemento $e \in V$, comparar su distancia $d$ con el resto de elementos de $V$. Si esta distancia es menor a $dmin$, $dmin = d$
  3. Devolver $dmin$

- #### Divide y Vencerás  
  Tratar de dividir el plano verticalmente en dos subplanos recursivamente hasta llegar al caso base en el que un subplano solo contenga 3 o menos puntos. Este caso es resuelto mediante el algoritmo de fuerza bruta para obtener la distancia menos.  Tras retornar de la recursividad comparando las mejores soluciones, obtendremos dos
  distancias, la mejor del subplano izquierdo y la del subplano derecho. Debemos encontrar ahora

  1. Considerar dos vectores que contienen todos los puntos del problema ordenados de forma ascendente en función de su componente $V_{x}, V_{y}$. Estos serán la entrada del método recursivo
  2. Dividir en dos partes recursivamente $V_{x}$ hasta llegar a un caso de tamaño 3
  3.


## Pseudo código
- #### Fuerza Bruta

      minDist ← infinity
      for i = 1 to length(P) - 1
        for j = i + 1 to length(P)          
          if dist(P[i], P[j]) < minDist:
            minDist ← dist(P[i], P[j])
            closestPair ← (p, q)
      return closestPair

- #### Divide y Vencerás  

## Complejidad

## Comprobación experimental

### Representación gráfica

## Conclusiones

## Apéndice
El `makefile` es capaz de generar dos programas diferentes en función del argumento que se le indique

- `make all` : genera un programa que calcula el par más cercano con ambos algoritmos una sola vez
- `make tests` : genera un programa para la realización de tests sobre ambos algoritmos

## Bibliografía
- http://www.cs.mcgill.ca/~cs251/ClosestPair/ClosestPairDQ.html
- https://es.wikipedia.org/wiki/Problema_del_par_de_puntos_m%C3%A1s_cercanos
