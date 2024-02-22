#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>
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

void merge(vector<int> &A, int l,int m,int r){
    vector<int> L,R;
    for(int i=l;i<m+1;i++){
        L.push_back(A[i]);
    }
    for(int i=m+1;i<r+1;i++){
        R.push_back(A[i]);
    }
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    int i=0,j=0;
    for(int k=l;k<=r;k++){
        if(L[i]<R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    vector<int> A=readInputs();
    mergeSort(A,0,(int)A.size()-1);
    print(A);
}
