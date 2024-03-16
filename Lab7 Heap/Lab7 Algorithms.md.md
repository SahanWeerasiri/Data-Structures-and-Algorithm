> # Algorithms
> In C++
> * Heap

***
#  Heap
```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void show(vector<int> &A){
    for(int a:A){
        cout<<a<<" ";
    }
    cout<<endl;
}
void heapify(vector<int> &A,int i,int n){//heap down
    int left=2*i+1;
    int right=2*i+2;
    int maxi;
    if(left<n && A[left]>A[i]){
        maxi=left;
    }else{
        maxi=i;
    }
    if(right<n && A[right]>A[maxi]){
        maxi=right;
    }
    if(maxi != i){
        int temp=A[i];
        A[i]=A[maxi];
        A[maxi]=temp;
        heapify(A,maxi,n);
    }
}
void buildHeap(vector<int> &A){
    int start=(int)A.size()/2-1;
    for(int j=0;j<(int)A.size();j++){
        if(j*2+1>=(int)A.size()){
            start=j;
            break;
        }
    }
    for(int i=start;i>=0;i--){
        heapify(A,i,(int)A.size());
    }
}


void heapSort(vector<int> &A){
    buildHeap(A);
    int n=(int)A.size()-1;
    for (int i=(int)A.size()-1; i>=0;i--){
        int temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        n--;
        heapify(A,0,n);
    }
}
void insert(vector<int> &A,int val){
    A.push_back(val);
    buildHeap(A);
}
int heapMax(vector<int> &A){
    return A[0];
}
void heapIncreaseKey(vector<int> &A,int key,int val){
    if(A[key]>=val){
        return;
    }
    A[key]=val;
    buildHeap(A);
}

int main(){
    vector<int> A={10,9,5,11,32,46,1,24,31,8};
    buildHeap(A);
    show(A);

    insert(A,99);
    show(A);

    heapSort(A);
    show(A);

    cout<<heapMax(A)<<endl;
    
    heapIncreaseKey(A,5,12);
    show(A);



}

````
