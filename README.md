# Trabalho de implementação - Teoria dos grafos
## Algoritmos implementados
Foram implementados os seguintes algoritmos:
* Algoritmo de Dijkstra (arestas não-direcionadas)
* Algoritmo de Prim (arestas não direcionadas)
* Algoritmo de Bellman-Ford (arestas direcionadas)
* Algoritmo de Floyd-Warshall (arestas direcionadas)

Para os algoritmos que precisam de uma fonte (vértice inicial para algum cálculo, por exemplo o algoritmo de dijkstra), o vértice inicial é o vértice 0 (zero).
## Entrada
A entrada para os algoritmos seguem o seguinte formato:

```sh
v e
v1 v2 w1
vn1 vn2 wn
```

Onde, na primeira linha **v** é o número de vértices e **e** é o número de arestas. Logo em seguida, terá **e** linhas, representando as arestas entre os vértices. O primeiro valor é o primeiro vértice, o segundo valor é o segundo vértice da aresta e o terceiro valor é o peso da aresta. Para algoritmos com arestas não direcionadas a ordem do primeiro valor e do segundo não importa, já que é adicionada uma aresta do primeiro vértice até o segundo e do segundo vértice até o primeiro. Já nos algoritmos com entradas direcionadas, a aresta é criada apenas com a direção do primeiro vértice para o segundo vértice.

## Compilação e execução
Para compilar execute o seguinte comando:
```sh
g++ nome_do_arquivo.cpp -o nome_do_arquivo
```

Para executar, basta digitar o seguinte comando:
```sh
./nome_do_arquivo
```

Também há a opção de incluir um arquivo de entrada, neste caso deve-se digitar:
```sh
./nome_do_arquivo <caminho_da_entrada
```

