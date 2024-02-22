> # Info
> - Before run this code,
>  1. Add your pragrams to proper places (read comments and follow them)
>  2. Change the number of algorithms in the main method
>  3. According to your programs count, change the switch case (I have created it for 4 algorithms)
>
```cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
void print(int n,vector<int> arr){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
vector<vector<int>> makeRandomArrays(int start_size,int end_size,int step, int value_limit){
    vector<vector<int>> arrays;
    vector<int> sample;
    for(int i=start_size;i<end_size+1;i=i+step){
        sample.clear();
        for(int j=0;j<i;j++){
            sample.push_back(rand()%(value_limit+1));
        }
        arrays.push_back(sample);
    }
    return arrays;
}

//Add your programs and other functions here.


void runtheProgram1(int n,vector<int> inputs){
       
}
void runtheProgram2(int n,vector<int> inputs){
       
}
void runtheProgram3(int n,vector<int> inputs){
       
}
void runtheProgram4(int n,vector<int> inputs){
       
}

int main() {
    //Get the values
    vector<vector<int>> arrays=makeRandomArrays(3,50,2,100);

    double sum_duration;
    vector<double> avg_duration;
    string topic;
    for(int sorting=0;sorting<4;sorting++){  // change the number of sorting algorithms (sorting < (number of algorithms))
        avg_duration.clear();
        for(int t=0;t<arrays.size();t++){
            sum_duration=0.0f;
    
            for(int i=0;i<5;i++){//5 times
    
                auto start = chrono::high_resolution_clock::now();
    
    
                switch(sorting){
                    case 0:
                    runtheProgram1(arrays[t].size(),arrays[t]);
                    topic="\n\n\nTopic 1\n#########\n";
                    break;
                    case 1:
                    runtheProgram2(arrays[t].size(),arrays[t]);
                    topic="\n\n\nTopic 2\n#########\n";
                    break;
                    case 2:
                    runtheProgram3(arrays[t].size(),arrays[t]);
                    topic="\n\n\nTopic 3\n#########\n";
                    break;
                    case 3:
                    runtheProgram4(arrays[t].size(),arrays[t]);
                    topic="\n\n\Topic 4\n#########\n";
                    break;
                    default:
                    break;
                }
                auto end = chrono::high_resolution_clock::now();
    
                // Calculating total time taken by the program.
                double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      
    
                sum_duration=sum_duration+time_taken;
     
    
            }
            avg_duration.push_back(sum_duration/5.0f);
        }
        cout<<topic;
        for(int i=0;i<avg_duration.size();i++){
            printf("%.20f\n",avg_duration[i]);
        }
    }
    

    return 0;
}
```
