```cpp
#include <iostream>

using namespace std;

int main() {

  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

  fprintf(gnuplotPipe, "set terminal png size 2000,1000\n");

  fprintf(gnuplotPipe, "set output 'time taken plot.png'\n");

  fprintf(gnuplotPipe, "set yrange[0:8000:1000]");

  fprintf(gnuplotPipe, "set mytics 2\n");

  fprintf(gnuplotPipe, "set style data histogram\n");

  fprintf(gnuplotPipe, "set style histrogram cluster gap 1\n");

  fprintf(gnuplotPipe, "set style fill solid\n");

  fprintf(gnuplotPipe, "set boxwidth 0.9\n");

  fprintf(gnuplotPipe, "set xtrics format \"\"\n");

  fprintf(gnuplotPipe, "set grid ytics\n");

  fprintf(gnuplotPipe, "set title 'Stack with Array Vs. LinkedList'\n");

  fprintf(gnuplotPipe, "set title font \",30\"\n");

  fprintf(gnuplotPipe, "set ytics font \",20\"\n");

  fprintf(gnuplotPipe, "set xtics font \",20\"\n");

  fprintf(gnuplotPipe, "set key font \",20\"\n");

  fprintf(gnuplotPipe,"plot 'data.txt' using 2:xtic(1) title 'Stack with array' linecolor \"red\",'data.txt' using 3 title 'Stack with LinkedList' linecolor \"blue\"");

  fflush(gnuplotPipe);

  return 0;

}
```
