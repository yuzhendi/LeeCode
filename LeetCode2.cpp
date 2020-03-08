/*************************************************************************
	> File Name: LeetCode2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 21时40分27秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1)  return l2;
    if(!l2) return l1;
    struct ListNode *p = l1, *q = l2;
    while(p->next && q->next) {
        p->val += q->val;
        p = p->next;
        q = q->next;
    }
    p->val += q->val;
    if(p->next == NULL) {//l2比l1长的时候
        p->next = q->next;
    }
    p = l1;//重新回到头部，将大于 10 的转换
    while(p->next) {
        if(p->val > 9) {
            p->next->val += (p->val / 10);
            p->val %= 10; 
        }
        p = p->next;
    }
    if(p->val > 9) {
        //最后一个大于9 的时候， 需要开辟新空间
        p->val %= 10;
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = 1;
        p->next->next = NULL;
    }
    return l1;
}
