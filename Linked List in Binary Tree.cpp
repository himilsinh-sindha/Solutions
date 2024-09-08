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
    bool dfs(TreeNode* node,ListNode* temp){
       if(temp==nullptr) return true; // all list are covered
       if(node==nullptr) return false; // we got the end of tree - tree leaf without covering lists

       if(node->val != temp->val) return false;

       // further checks if left or right which matches;
       return dfs(node->left,temp->next) || dfs(node->right,temp->next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
       if(root==nullptr) return false; // we return false if it is not the starting point of list

       // also checks for left and right subtree if it is valid start or not
       return dfs(root,head) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};