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
  1. Consideramos todos los puntos del problema como elementos contenidos en un conjunto $V$
  2. Considerar $dmin$ como la distancia máxima posible en el plano
  2. Para cada elemento $e \in V$, comparar su distancia $d$ con el resto de elementos de $V$. Si esta distancia es menor a $dmin$, $dmin = d$
  3. Devolver $dmin$

- #### Divide y Vencerás
## Pseudo código

## Complejidad

## Comprobación experimental

### Representación gráfica

## Conclusiones

## Apéndice
El `makefile` es capaz de generar dos programas diferentes en función del argumento que se le indique

- `make all` : genera un programa que calcula el par más cercano con ambos algoritmos una sola vez
- `make tests` : genera un programa para la realización de tests sobre ambos algoritmos
