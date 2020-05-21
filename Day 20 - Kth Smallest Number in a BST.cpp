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
    int answer = -1;
    int counter = 0;
    
    void inorder(TreeNode* node, int k)
    {
        if(node)
        {
            inorder(node->left, k);
            if(counter<k)
                counter++;
            
            if(answer!=-1)
                return;
            
            //cout<<node->val<<" "<<counter<<"\n";
            
            if(counter==k && answer==-1)
            {
                answer = node->val;
                return;
            }
            inorder(node->right, k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
       inorder(root, k);
       return answer;
    }
};