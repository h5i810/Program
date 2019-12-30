#include <iostream>

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) :val(x), next(NULL){}
};


ListNode* ReverseList(ListNode* pHead){
    if(pHead==NULL)
        return NULL;
    ListNode* temp=pHead;
    ListNode* node=NULL;
    while(temp->next){
        node=temp->next;
        temp->next=node->next;
        node->next=pHead;
        pHead=node;
    }
    return pHead;
}
