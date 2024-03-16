> # Algorithms
> #### In C++
> * Quick Sort (In Recursive Format)
> * Quick Sort (In Iterative Format)
>
***
# Quick Sort In Recursive Format
```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> readInputs(){
    string in;
    getline(cin,in);
    istringstream iss(in);
    int n;
    vector<int> A;
    while(iss>>n){
        A.push_back(n);
    }
    return A;
}

void print(vector<int> A){
    for(int a: A){
        cout<<a<<" ";
    }
}

void swap(int &a,int &b){
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
void QuickSort(vector<int> &A,int p,int r){
  if(p>=r){
    return;
  }
  int pivoted_index=arrange(A,p,r);
  QuickSort(A,p,pivoted_index-1);
  QuickSort(A,pivoted_index+1,r);
}
int main(){
    vector<int> A=readInputs();
    QuickSort(A,0,(int)A.size()-1);
    print(A);
}

```
***

# Quick Sort In Iterative Format
```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> readInputs(){
    string in;
    getline(cin,in);
    istringstream iss(in);
    int n;
    vector<int> A;
    while(iss>>n){
        A.push_back(n);
    }
    return A;
}

void print(vector<int> A){
    for(int a: A){
        cout<<a<<" ";
    }
}
void swap(int &a,int &b){
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

void push(vector<int>&A,int n){
  A.push_back(n);
}
int pop(vector<int>&A){
  int n=A[(int)A.size()-1];
  A.pop_back();
  return n;
}
void QuickSort(vector<int>&A,int n){
  vector<int> stk;//stack
  push(stk,0);
  push(stk,n-1);
  int last,first,pivot;
  while((int)stk.size()!=0){
    last=pop(stk);
    first=pop(stk);
    pivot=arrange(A,first,last);
    if (pivot - 1 > first){
      push(stk, first);
      push(stk,pivot-1);
    }
    if (pivot + 1 < last){
      push( stk,pivot + 1);
      push( stk,last);
    }
  }
}
int main(){
    vector<int> A=readInputs();
    QuickSort(A,(int)A.size());
    print(A);
}
```
