# Code for plotting graphs using GNUPlot through VSCode
> ### Instructions
> 1. Make data txt files and save at the directory which this code is saved
> 2. In this code, change the txt file names, topics, axis names as you want
***
```cpp
#include <iostream>
using namespace std;
int main() {
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  fprintf(gnuplotPipe, "set title '<Title>'\n");
  fprintf(gnuplotPipe, "set xlabel '<X axis name>'\n");
  fprintf(gnuplotPipe, "set ylabel '<Y axis name>'\n");
  fprintf(gnuplotPipe, "plot '<data1.txt>' with linespoints title '<Data1 title>', '<data2.txt>' with linespoints title '<Data2 title>'\n");
  fflush(gnuplotPipe);
  return 0;
}
```
