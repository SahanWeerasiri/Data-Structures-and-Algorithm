> # Algorithms
> #### In C++
> * Quick Sort (In Recursive Format)
> * Quick Sort (In Iterative Format)
>
***
# Quick Sort In Recursive Format
```cpp
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b)
{
int temp=a;
a=b;
b=temp;
}
int arrange(vector<int> &A,int p,int r){
int pivoted=A[r];
int i=p-1;
for(int j=p;j<r;j++){
if(A[j]<pivoted){
i++;
swap(A[j],A[i]);
}
}
i++;
swap(A[r],A[i]);
return i;
}
void QuickSortR(vector<int> &A,int p,int r){
if(p>=r){
return;
}
int pivoted_index=arrange(A,p,r);
QuickSortR(A,p,pivoted_index-1);
QuickSortR(A,pivoted_index+1,r);
}
int main(){

```
