/*************************************************************************
	> File Name: 237.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 16时40分56秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {//只给出被删除的节点
    struct ListNode *p = node->next;
    while(p) {
        node->val = p->val;//用后一个节点覆盖掉前一个
        p = p->next;    
        if(p) node = node->next;//不要最后一个节点
    }
    p = node->next;
    node->next= NULL;
    free(p);
    return ;
}

void deleteNode(struct ListNode* node) {//只给出被删除的节点
    struct ListNode *p = node->next;
    node->val = p->val;//删除node 后一个节点
    node->next = p->next;
    free(p);
    return ;
}
