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
    
    // good problem, recursion must be taken care of very well!
    int depthAndParent(TreeNode* node, int x, TreeNode* &parent, int depth)
    {
        if(node)
        {
            
            if((node->left && node->left->val==x) || (node->right && node->right->val==x))
            {
                parent = node;
                return depth+1;
            }
            else
            {
                int dleft = -1; int dright = -1;
                TreeNode* p1;
                TreeNode* p2;
                dleft = depthAndParent(node->left, x, p1, depth+1);
                dright = depthAndParent(node->right, x, p2, depth+1);
            
                if(dleft==-1 && dright==-1)
                {
                    if(node->val==x)
                    {
                        // this is the root
                        parent = NULL;
                        return 0;    
                    }
                    else
                    {
                        // this is a leaf, can't go beyond this!
                        return -1;
                    }
                }
                else
                {
                    
                    if(dleft>-1)
                    {
                        parent = p1;
                        return dleft;
                    }
                    else
                    {
                        parent = p2;
                        return dright;
                    }
                }
            }
        }
        else
        {
            return -1;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        TreeNode* p1;
        TreeNode* p2;
        
        //TreeNode* main_root = root;
        int d1 = depthAndParent(root, x, p1, 0);
        //root = main_root;
        int d2 = depthAndParent(root, y, p2, 0);
        
        cout<<d1<<" "<<d2<<endl;
        if(p1 && p2)
            cout<<p1->val<<" "<<p2->val<<endl;
        
        return (p1 && p2 && d1==d2 && p1->val!=p2->val);
        
    }
};