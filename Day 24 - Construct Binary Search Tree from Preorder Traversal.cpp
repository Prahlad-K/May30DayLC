/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void preorderTree(TreeNode* root)
    {
        if(root)
        {
            cout<<root->val<<" ";
            preorderTree(root->left);
            preorderTree(root->right);
        }
    }
   
    void addNode(TreeNode* &root, int value)
    {
       if(root)
       {
           if(value<root->val)
           {           
               if(root->left)
               {
                   addNode(root->left, value);
               }
               else
               {
                   root->left = new TreeNode(value);
               }
           }
           else
           {
               if(root->right)
               {
                   addNode(root->right, value);
               }
               else
               {
                   root->right = new TreeNode(value);
               }
           }
       }
        else
        {
            root = new TreeNode(value);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       
        TreeNode* root = NULL;
        for(int i=0;i<preorder.size();i++)
        {
            addNode(root, preorder[i]);
            // preorderTree(root);
            // cout<<endl;
        }
        
        return root;
        
    }
};