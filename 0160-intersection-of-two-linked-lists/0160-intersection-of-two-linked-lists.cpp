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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>s;
        ListNode*current1=headA;
        ListNode*current2=headB;
        while(current1){
            s.insert(current1);
            current1=current1->next;
        }
        while(current2){
            if(s.find(current2) !=s.end()){
                return current2;
            }
            current2=current2->next;
        }
        return nullptr;

    }
};