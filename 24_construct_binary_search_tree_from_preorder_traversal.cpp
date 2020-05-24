/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  
Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Same solution as of Leetcode April Challenge 
class Solution {
public:
    int i = 0;
    TreeNode* bstBuilder(vector<int>& preorder, int bound=INT_MAX) {
        if(i == preorder.size() || preorder[i] > bound) 
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstBuilder(preorder, root->val);
        root->right = bstBuilder(preorder, bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstBuilder(preorder, INT_MAX);
    }
};


// A different solution
class Solution {
private:
    TreeNode* bstBuilder(TreeNode* root, int data) {
        if (root == nullptr) {
            root = new TreeNode(data);
        } else if (root->val > data) {
            root->left = bstBuilder(root->left, data);
        }
        else if (root->val < data) {
            root->right = bstBuilder(root->right, data);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i=0; i<preorder.size(); ++i) {
            TreeNode* node = bstBuilder(root, preorder[i]);
        }
        return root;
    }
};