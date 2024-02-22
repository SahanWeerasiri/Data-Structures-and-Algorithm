> # Algorithms
> #### In C++
> - Bubble Sort
> - Optimized Bubble Sort
> - Insertion Sort
> - Selection Sort

***

# Bubble Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> readInputs(){
    string number_part;
    vector<int> inputs;
    while(getline(cin,number_part,' ')){//check for seperated strings
        inputs.push_back(stoi(number_part));//convert to int and put in the vector
    }
    return inputs;
}
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void bubbleSort(int n,vector<int> &array){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(array[j]>array[j+1]){//check wheather the next value is greater than current value
                swap(array[j+1],array[j]);// swap values
            }
        }
    }
}
void print(int n,vector<int> &array){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    //read inputs
    vector<int> num_array=readInputs();
    
    //bubble sort
    bubbleSort(num_array.size(),num_array);
    
    //print sorted vector
    print(num_array.size(),num_array);
}
```

***
# OptimizedBubble Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> readInputs(){
    string number_part;
    vector<int> inputs;
    while(getline(cin,number_part,' ')){//check for seperated strings
        inputs.push_back(stoi(number_part));//convert to int and put in the vector
    }
    return inputs;
}
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void optimizedBubbleSort(int n,vector<int> &array){
    bool is_swapped;
    for(int i=0;i<n;i++){
        is_swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){//check wheather the next value is greater than current value
                swap(array[j+1],array[j]);// swap values
                is_swapped=true;
            }
        }
        if(!is_swapped){//no swaps, that means the numbers are sorted
            break;
        }
    }
}
void print(int n,vector<int> &array){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    //read inputs
    vector<int> num_array=readInputs();
    
    //optimized bubble sort
    optimizedBubbleSort(num_array.size(),num_array);
    
    //print sorted vector
    print(num_array.size(),num_array);
}
```

***

# Insertion Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> readInputs(){
    string number_part;
    vector<int> inputs;
    while(getline(cin,number_part,' ')){//check for seperated strings
        inputs.push_back(stoi(number_part));//convert to int and put in the vector
    }
    return inputs;
}
void insertionSort(int n,vector<int> &array){
    bool is_inserted;
    for(int i=0;i<n;i++){
        is_inserted=false;
        int temp=array[i];//keep the current value out of the vector
        for(int j=i-1;j>=0;j--){
            if(array[j]>temp){//shift the higher values to the right
                array[j+1]=array[j];
            }else{//insert the key value
                array[j+1]=temp;
                is_inserted=true;
                break;
            }
        }
        if(!is_inserted){//insert the value to the front of the vector
            array[0]=temp;
        }
    }
}
void print(int n,vector<int> &array){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    //read inputs
    vector<int> num_array=readInputs();
    
    //insertion sort
    insertionSort(num_array.size(),num_array);
    
    //print sorted vector
    print(num_array.size(),num_array);
}
```

***

# Selection Sort
```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> readInputs(){
    string number_part;
    vector<int> inputs;
    while(getline(cin,number_part,' ')){//check for seperated strings
        inputs.push_back(stoi(number_part));//convert to int and put in the vector
    }
    return inputs;
}
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void selctionSort(int n,vector<int> &array){
    int index_minimum;
    for(int i=0;i<n;i++){
        index_minimum=i;//keep minimum value's index
        for(int j=i+1;j<n;j++){
            if(array[j]<array[index_minimum]){//check for minimum value
                index_minimum=j;
            }
        }
        if(index_minimum!=i){//minimum index changed, that means need to swap
            swap(array[index_minimum],array[i]);
        }
    }
}
void print(int n,vector<int> &array){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    //read inputs
    vector<int> num_array=readInputs();
    
    //selection sort
    selctionSort(num_array.size(),num_array);
    
    //print sorted vector
    print(num_array.size(),num_array);
}
```
