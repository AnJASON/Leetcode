反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy = ListNode(0);
        ListNode* dum = &dummy;
        dum->next = head;
        ListNode* t1 = dum;
        for(int i = 1;i < m; i++){
            t1 = t1->next;
        }
        ListNode* p = t1;
        ListNode* q = p->next;
        ListNode* r = q->next;
        ListNode* t2 = q;
        for(int i = 1; i <= n-m; i++){
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        t1->next = q;
        t2->next = r;
        return dum->next;
    }
};
