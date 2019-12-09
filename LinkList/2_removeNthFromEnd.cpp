/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*****
1、特殊情况：当输入为空链表，则直接返回
2、使用哑结点，防止头结点找不到的情况
3、空指针不能使用取值操作（->val），所以取值之前记得判断指针是否为空
4、空指针不能使用取后继（->next），同样在取后继之前判断指针是否为空
*****/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !n){
            return head;
        }
        ListNode dummy = ListNode(0);
        ListNode* thead = &dummy;
        thead->next = head;
        ListNode* slow = thead;
        ListNode* fast = thead;
        n = n+1;
        while(n && fast){
            fast = fast->next?fast->next:nullptr;
            n--;
        }
        if(!n){
            while(fast){
                slow = slow->next;
                fast = fast->next?fast->next:nullptr;
            }
        }
        
        slow->next = slow->next->next?slow->next->next:nullptr;
        return thead->next;
    }
};
