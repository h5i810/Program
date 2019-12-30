#include <iostream>


struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x),  next(NULL){}
};

ListNode* FindKToTrail(ListNode* pListHead, unsigned int k){
    if(pListHead==NULL&&k==0)
        return NULL;
    ListNode* first=pListHead;
    ListNode* second=pListHead;
    while(k&&first!=NULL){
        first=first->next;
        k--;
    }
    if(k>0) return NULL;
    while(first){
        first=first->next;
        second=second->next;
    }
    return second;
}
