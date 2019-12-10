// 给定一个链表，判断链表中是否有环。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：true
// 解释：链表中有一个环，其尾部连接到第二个节点。
//思路：快慢指针，慢指针一次走一步，快指针一次走两步，若有环则两者会相遇

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head || !head->next || !head->next->next){
            return false;
        }
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
