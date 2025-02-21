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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * current=head;
        if(head==nullptr){
            return head;
        }
        set<int>s(nums.begin(),nums.end());
        ListNode*dummy=new ListNode();
        ListNode*c=dummy;
        while(current){
            if(s.find(current->val) ==s.end()){
                c->next=current;
                c=c->next;
                current=current->next;
                

            }
            else{
                current=current->next;

            }
            
        }
        c->next=nullptr;
        return dummy->next;

    }
};