/*************************************************************************
	> File Name: 203.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 15时34分08秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL ) return head;
    struct ListNode *p = head,*q1;
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->next = NULL;
    q1 = q;
    while(p!= NULL)
    {
        if(p->val != val)
        {
            q->next = p;
            q = q->next;
        }
        p = p->next;
    }
    q->next = NULL;
    return q1->next;
}
