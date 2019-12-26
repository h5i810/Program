#include <iostream>
#include <stack>

using std::stack;

int pattern(int arr[], int start, int end){
    if(start>end||arr==NULL||start<0||end<=0)
        return -1;
    int i=start, j=end, x=arr[start];
    while(i<j){
        while(i<j && arr[j]>=x)
            j--;
        if(i<j)
            arr[i]=arr[j];
        while(i<j && arr[i]<=x)
            i++;
        if(i<j)
            arr[j]=arr[i];
    }
    arr[i]=x;
    return i;

}

void quick_sort(int arr[], int start, int end){
    
    if(start>end||arr==NULL||start<0||end<=0)
        return;
    int mid=pattern(arr, start, end);
    if(mid>start)
        quick_sort(arr, start, mid-1);
    if(mid<end)
        quick_sort(arr, mid+1, end);
}

//非递归快速排序
void QuickSort(int arr[], int start, int end){
    if(arr==NULL||start<0||end<=0||start>=end)
        return;
    stack<int> temp;
    int left,right;
    temp.push(end);
    temp.push(start);
    while(!temp.empty()){
        left=temp.top();
        temp.pop();
        right=temp.top();
        temp.pop();
        if(left<right){
            int mid=pattern(arr, left, right);
            if(mid>left){
                temp.push(mid-1);
                temp.push(left);
            }
            if(mid<right){
                temp.push(right);
                temp.push(mid+1);
            }
        }
    }
}

