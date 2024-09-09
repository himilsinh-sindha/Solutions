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
class Solution {
public:
    // Function to fill an m x n matrix in spiral order using values from the linked list
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with default value -1
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        // Define boundaries for the spiral traversal
        int top = 0;           // Top row boundary
        int bottom = m - 1;    // Bottom row boundary
        int left = 0;          // Left column boundary
        int right = n - 1;     // Right column boundary

        // Pointer to traverse the linked list
        ListNode* temp = head;

        // Loop until the matrix is filled or we run out of linked list nodes
        while(top <= bottom && left <= right) {
            // Traverse from left to right on the current top row
            for(int i = left; i <= right; i++) {
                if(temp == nullptr) break; // If no more nodes, break out
                ans[top][i] = temp->val;   // Assign linked list value to matrix
                temp = temp->next;         // Move to the next node
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom on the current right column
            for(int i = top; i <= bottom; i++) {
                if(temp == nullptr) break; // If no more nodes, break out
                ans[i][right] = temp->val; // Assign linked list value to matrix
                temp = temp->next;         // Move to the next node
            }
            right--;  // Move the right boundary left

            // Check if there's still a bottom row to traverse
            if(top <= bottom) {
                // Traverse from right to left on the current bottom row
                for(int i = right; i >= left; i--) {
                    if(temp == nullptr) break; // If no more nodes, break out
                    ans[bottom][i] = temp->val; // Assign linked list value to matrix
                    temp = temp->next;          // Move to the next node
                }
                bottom--;  // Move the bottom boundary up
            }

            // Check if there's still a left column to traverse
            if(left <= right) {
                // Traverse from bottom to top on the current left column
                for(int i = bottom; i >= top; i--) {
                    if(temp == nullptr) break; // If no more nodes, break out
                    ans[i][left] = temp->val;  // Assign linked list value to matrix
                    temp = temp->next;         // Move to the next node
                }
                left++;  // Move the left boundary right
            }
        }

        // Return the filled matrix
        return ans;
    }
};
