```cpp
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

vector<int> merge(vector<int> A, int l1,int r1,int l2,int r2){
    vector<int> temp;
    while(l1<=r1 && l2<=r2){
        if(A[l1]<A[l2]){
            temp.push_back(A[l1]);
            l1++;
        }else{
            temp.push_back(A[l2]);
            l2++;
        }
    }

    while(l1<=r1){
        temp.push_back(A[l1]);
        l1++;
    }

    while(l2<=r2){
        temp.push_back(A[l2]);
        l2++;
    }

    return temp;
}

vector<int> mergeSort(vector<int> arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        vector<int > L,R;
        L=mergeSort(arr,left,mid);
        R=mergeSort(arr,mid+1,right);
        vector<int> LR=L;
        LR.insert(LR.end(),R.begin(),R.end());
        vector<int> res= merge(LR,0,mid-left,mid+1-left,right-left);
        return res;
    }
    vector<int> temp={arr[left]};
    return temp;
}

int main(){
    vector<int> A=readInputs();
    vector<int> Res=mergeSort(A,0,(int)A.size()-1);
    print(Res);
}
```
