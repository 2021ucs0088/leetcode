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
        ListNode* current = head;
        ListNode* prev = nullptr;
        set<int>s;
        for (auto ele:nums){
            s.insert(ele);
        }
        
        while (current != nullptr) {
            if (s.find(current->val) !=s.end()) {
                if (prev == nullptr) {
                    // Head needs to be removed
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    // Non-head node needs to be removed
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        return head;
    }
};
