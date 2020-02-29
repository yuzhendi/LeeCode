/*************************************************************************
	> File Name: 234.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 16时09分33秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head, int n){
    if(head == NULL) return NULL;
    struct ListNode ret, *p = head, *q = head;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p) {
        q = p;
        p = p->next;
        q->next = ret.next;
        ret.next = q;
    }
    return ret.next;
}
int get_len(struct ListNode *a) {
    int len = 0;
        while(a) {
        len++;
        a = a->next;
    }
    return len;
}
bool isPalindrome(struct ListNode* head){
    int len = 0;//时间复杂度 O(n), 空间复杂度 O(1)
    struct ListNode *a = head, *b = head;
    len = get_len(head);//将链表一分为二
    b = reverseList(b, (len + 1) / 2);
    while(b) {//a 的长度小于等于b， 但是 其实是一条链
        if(a->val != b->val) return false;
        a = a->next;
        b = b->next;
    
    }
    return true;
}
