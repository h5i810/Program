#include <iostream>

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
    if(pHead1==NULL||pHead2==NULL)
        return NULL;
    ListNode* p1=pHead1;
    ListNode* p2=pHead2;
    int x=0, y=0, temp=0;
    while(p1){x++; p1=p1->next;}
    while(p2){y++; p2=p2->next;}
    if(x>y){
        temp=x-y;
        while(temp--) pHead1=pHead1->next;
    }
    else if(x<y){
        temp=y-x;
        while(temp--) pHead2=pHead2->next;
    }
    while(pHead1&&pHead2){
        if(pHead1==pHead2)
            return pHead1;
        pHead1=pHead1->next;
        pHead2=pHead2->next;
    }
    return NULL;
}
