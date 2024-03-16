#include <iostream>
using namespace std;
int main() {
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  fprintf(gnuplotPipe, "set title 'Heap Sort'\n");
  fprintf(gnuplotPipe, "set xlabel 'Inputs'\n");
  fprintf(gnuplotPipe, "set ylabel 'Excecution Time (ns)'\n");
  fprintf(gnuplotPipe, "plot 'data1.txt' with linespoints title 'HeapSort'\n");
  fflush(gnuplotPipe);
  return 0;
}