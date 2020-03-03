/*************************************************************************
	> File Name: LeetCode21.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时07分34秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode ret;
    struct ListNode *p1 = l1, *p2 = l2, *head;
   // ret.next = p1->val < p2->val ? : p1 : p2;
    head = &ret; 
    while(p1 && p2) {
        if(p1->val < p2->val) {
            head->next = p1;
            head = head->next;
            p1 = p1->next;
        }else{
            head->next = p2;
            p2 = p2->next;
            head = head->next;
        }
    }
    if(p1) {
        head->next = p1;
    }
    if(p2) {
        head->next = p2;
    }
    if(!p1 && !p2)head->next = NULL;
    return ret.next;
}
