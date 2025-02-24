/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        func(root,pq);
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
    void func(TreeNode*node,priority_queue<int,vector<int>,greater<int>>&pq){
        if(node ==nullptr){
            return ;
        }
        pq.push(node->val);
        if(node->left){
            func(node->left,pq);
        }
        if(node->right){
            func(node->right,pq);
        }
    }

};