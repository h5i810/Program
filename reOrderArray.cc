#include <vector>
#include <iostream>
using std::vector;

void reOrderArray(vector<int> &array){
    if(array.size()==0)
        return;
    int tag=0;
    for(size_t i=0; i<array.size();i++){
        if(array[i]%2){
            int j=i;
            while(j>tag){
                std::swap(array[j], array[j-1]);
                j--;
            }
            tag++;
        }
    }
}
