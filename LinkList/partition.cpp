给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

// 为防止丢失头结点，需要使用哑结点，但是此题构造哑结点需要特别注意的一点是哑结点的值该如何选取，如果取0
// 那么对于x为负数的情况就不能适用了,取个巧，取个非常大的负数（如-65530）,然后就可以了，当然这会增加额外的存储空间
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
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return head;
        }
        ListNode dummy = ListNode(-65530);
        ListNode* dum = &dummy;
        dum->next = head;
        ListNode* p = dum;
        while(p->val < x && p->next && p->next->val < x){
            p = p->next;
        }
        ListNode* curr = p->next?p->next:nullptr;
        ListNode* temp = curr;
        while(curr){
            if(curr->next && curr->next->val < x ){
                p->next = curr->next;
                p = p->next;
                curr->next = curr->next->next?curr->next->next:nullptr;
            }
            else{
                curr = curr->next;
            }
        }
        p->next = temp;
        return dum->next;
    }
    
};
