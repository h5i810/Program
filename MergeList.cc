#include <iostream>
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1==NULL) return pHead2;
    if(pHead2==NULL) return pHead1;
    ListNode* head=NULL;
    if(pHead1->val >pHead2->val){
        head=pHead2;
        pHead2=pHead2->next;
    }
    else{
        head=pHead1;
        pHead1=pHead1->next;
    }
    ListNode* temp=head;
    while(pHead1&&pHead2){
        if(pHead1->val > pHead2->val){
            temp->next=pHead2;
            pHead2=pHead2->next;
        }
        else{
            temp->next=pHead1;
            pHead1=pHead1->next;
        }
        temp=temp->next;
    }

    if(pHead1) temp->next=pHead1;
    if(pHead2) temp->next=pHead2;
    pHead1=NULL;
    pHead2=NULL;
    return head;
}
