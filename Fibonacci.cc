#include <iostream>

//递归方法
int Fibonacci(int n)
{
    if(n<=0)
        return 0;
    else if(n==1||n==2)
        return 1;
    else 
        return Fibonacci(n-1)+Fibonacci(n-2);
}

//非递归方法
int Fibonacci(int n){
    if(n==0)
        return 0;
    if(n==1||n==2)
        return 1;
    int x=0, y=1;
    while(n--){
        y=x+y;
        x=y-x;
    }
    return x;
}
