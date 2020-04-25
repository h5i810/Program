#ifndef DATA_ARRANGE_H
#define DATA_ARRANGE_H

#include <iostream>

template <typename T>
void Perm(T List[], int k, int m)
{
    if(k==m){
        for(int i=0; i<=m; i++)
            std::cout << List[i];
        std::cout<<std::endl;
    }
    else{
        for(int i=k; i<=m; i++){
            std::swap(List[k], List[i]);
            Perm(List, k+1, m);
            std::swap(List[k], List[i]);
        } 
    }
}

#endif
