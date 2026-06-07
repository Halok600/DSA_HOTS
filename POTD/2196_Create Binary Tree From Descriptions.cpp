/**
C++ CODE FOR SOLUTION
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;
        for(vector<int>& vec : descriptions){
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);

            }
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
                

            }
            if (isLeft == 1){
                mp[parent] -> left = mp[child];
            }
            else{
                mp[parent] -> right = mp[child];
            }
            childSet.insert(child);
        }
        for(vector<int> &vec : descriptions){
            if(childSet.find(vec[0]) == childSet.end())
                return mp[vec[0]];
        }
        return NULL;
    }
};

/// PYTHON CODE SOLUTION:

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        mp = {}
        childSet = set()
        for parent, child, isLeft in descriptions:
            if parent not in mp:
                mp[parent] = TreeNode(parent)
            if child not in mp:
                mp[child] = TreeNode(child)
            if isLeft == 1:
                mp[parent].left = mp[child]
            else:
                mp[parent].right = mp[child]
            childSet.add(child)
        
        for parent, _, _ in descriptions:
            if parent not in childSet:
                return mp[parent]

        
