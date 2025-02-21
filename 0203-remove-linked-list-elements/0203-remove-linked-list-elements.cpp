/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode();
        ListNode *current=head;
        ListNode * c=dummy;
        while(current){
            if(current->val!=val){
                c->next=current;
                c=c->next;
            }
            current=current->next;
        }
        c->next=nullptr;
        return dummy->next;
        
    }
};