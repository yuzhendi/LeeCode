/*************************************************************************
	> File Name: 206.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 15时32分17秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode *temp, *p = head->next, *q = head;
    q->next = NULL;
    while(p) {
        temp = p;
        p = p->next;
        temp->next = q;
        q = temp;
    }
    return q;
}
