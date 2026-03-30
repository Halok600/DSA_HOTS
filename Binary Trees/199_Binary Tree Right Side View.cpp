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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root==NULL)
            return {};
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* node;
            while(n--){
                node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);

            }
            res.push_back(node->val);
        }
        return res;
    }
};

// 2nd Approach PreOrder Traversal
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
    void preOrder(TreeNode* root,int lvl,vector<int>& res){
        if(root==NULL)
            return;
        if(res.size()<lvl){
            res.push_back(root->val);
        }
        preOrder(root->right,lvl+1,res);
        preOrder(root->left,lvl+1,res);
    }
//Dont know why editing?

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preOrder(root,1,res);
        return res;
    }
};
