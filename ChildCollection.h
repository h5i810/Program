#ifndef CHILD_COLLECTION_H
#define CHILD_COLLECTION_H

#include <iostream>

//
//  输出一个元素的全部子集
//


template <typename T>
void ChildCollection( T List[], int tag[], int k, int m)
{
    if(k==m+1){
        std::cout << "{";
        for(int i=0; i<=m; i++){
            if(tag[i]==1){
                std::cout << List[i] ;
                if(i<m){
                    std::cout << ", ";
                }
            }
        }
        std::cout << "}" <<std::endl;
        return;
    }
    tag[k]=0;
    ChildCollection(List, tag, k+1, m);
    tag[k]=1;
    ChildCollection(List, tag, k+1, m);
}
#endif
