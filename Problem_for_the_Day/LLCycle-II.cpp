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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
       // ListNode* result=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
                //result=p;
            }
        }
            if(!fast || !fast->next || !fast->next->next){
                return NULL;
            }
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
        return slow;
    }
};
