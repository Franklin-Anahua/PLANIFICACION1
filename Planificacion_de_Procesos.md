**PRÁCTICA: “PLANIFICACIÓN DE PROCESOS (I)”**

**4.2. Resolución manual del algoritmo FCFS**

Considere el siguiente conjunto de procesos, tomado del ejemplo de planificación presentado por Stallings

| Procesos | Tiempo de Llegada | Tiempo de Servicio |
| :---- | ----- | ----- |
| A | 0 | 3 |
| B | 2 | 6 |
| C | 4 | 4 |
| D | 6 | 5 |
| E | 8 | 2 |

**Actividades:**  
1\. Determine el orden de ejecución de los procesos según FCFS.  
A \-\> B \-\> C \-\> D \-\> E  
2\. Elabore manualmente el diagrama de Gantt.

| 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |
| A | x | x | x |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| B |  |  |  | x | x | x | x | x | x |  |  |  |  |  |  |  |  |  |  |  |
| C |  |  |  |  |  |  |  |  |  | x | x | x | x |  |  |  |  |  |  |  |
| D |  |  |  |  |  |  |  |  |  |  |  |  |  | x | x | x | x | x |  |  |
| E |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | x | x |

3\. Calcule los tiempos de comienzo, finalización, espera y estancia.

| Procesos | Tiempo de Comienzo | Tiempo de Finalización | Tiempo de Espera | Tiempo de estancia |
| :---- | :---- | :---- | :---- | :---- |
| A | 0 | 3 | 0 | 3 |
| B | 3 | 9 | 1 | 7 |
| C | 9 | 13 | 5 | 9 |
| D | 13 | 18 | 7 | 12 |
| E | 18 | 20 | 10 | 12 |

4\. Determine el tiempo de espera promedio y el tiempo de estancia promedio.  
tiempo de espera promedio: (0+1+5+7+10)/5 \= 4.6  
tiempo de estancia promedio: (3+7+9+12+12)/5 \= 8.6

