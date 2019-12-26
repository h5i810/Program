#include <iostream>
namespace bin1{
    
    int binary_search(const int arr[], int start, int end, int target){
        if(start>end||arr==NULL)
            return -1;
        int mid=start+(end-start)/2;
        if(arr[mid]>target)
            return binary_search(arr, start, mid-1,target);
        else if(arr[mid]<target)
            return binary_search(arr, mid+1,end,target);
        else
            return mid;
    }
}

namespace bin2{

    int  binary_search(const int arr[], int start, int end, int target){
        int ret=-1;
        if(arr==NULL||start>end)
            return ret;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]<target)
                start=mid+1;
            else if(arr[mid]>target)
                end=mid-1;
            else{
                ret=mid;
                break;
            }
        }
        return ret;
    }
}
