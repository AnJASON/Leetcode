/*题目描述：
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/****solution1****/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode rs(0);
        ListNode *p = &rs;
        if(l1==nullptr){
            return l2;
        }
        else if(l2==nullptr){
            return l1;
        }
        int flag=0;
        while(l1||l2||flag){
            int tmp = 0;
            tmp += flag;
            if(l1) tmp += l1->val;
            if(l2) tmp += l2->val;
            flag = tmp/10;

            // ListNode next(tmp%10);
            ListNode *next;
            next = new ListNode(tmp%10);
            p->next = next;
            p = p->next;         
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return rs.next;
    }
};

/***solution2***/
