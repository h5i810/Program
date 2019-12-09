/*******************************************************************
 * 题目：输入一个链表的头结点，从尾到头反过来打印每个节点的值
 ********************************************************************/

/**
 * struct ListNode{
 *     int val;
 *     struct ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/

//方法一：使用stack
 vector<int> printListFromTailToHead(ListNode *head){
     if(head==NULL)
        return vector<int>();

     stack<int> nodes;
     ListNode* pNode=head;
     while(pNode!=NULL){
        nodes.push(pNode->val);
        pNode=pNode->next;
     }

     vector<int> ret;
     while(!nodes.empty()){
        ret.push_back(nodes.top());
         nodes.pop()
     }

     return ret;
 }

//方法二：逆置链表，然后输出
vector<int> printListFromTailToHead(ListNode* head){
    if(head==NULL)
        return vector<int>();
    ListNode* pNode=head;
    ListNode* pre=pNode;
    while(pre->next){
        pNode=pre->next;
        pre->next=pNode->next;
        pNode->next=head;
        head=pNode;
    }

    vector<int> ret;
    pNode=head;
    while(pNode){
        ret.push_back(pNode->val);
        pNode=pNode->next;
    }

    return ret;

}
