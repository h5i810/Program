#include <iostream>
#include <algorithm>
void bubble_sort(int arr[], int length){
    if(arr==NULL||length<=1)
        return;
    bool flag=false;
    for(int i=length-1; i>0; i--){
        flag=false;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                flag=true;
            }
        }
        if(flag==false)
            return;
    }
}
