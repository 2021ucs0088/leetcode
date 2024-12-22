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
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool reversed=false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>level(n);
            for (int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
                level[i]=node;
                

            }
            if (reversed==true){
                for (int i=0;i<n/2;i++){
                    swap(level[i]->val,level[n-i-1]->val);
                }

            }
            reversed=!reversed;
            
        }
        return root;
        
    }
};