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
    // Function to modify a linked list by removing nodes whose values exist in the 'nums' vector
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered_set to store all values from 'nums' for quick lookup
        unordered_set<int> ans(nums.begin(), nums.end());

        // Initialize temp to traverse the linked list and prev to keep track of the previous node
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 0;  // Counter to track the position in the linked list (1-based index)

        // Traverse the linked list
        while (temp) {
            cnt++;  // Increment counter for each node

            // Check if the current node's value exists in the 'nums' set (i.e., needs to be removed)
            if (ans.find(temp->val) != ans.end()) {
                if (cnt == 1) {
                    // Special case: If the node to be removed is the head of the list
                    head = head->next;  // Move the head to the next node
                    temp = temp->next;  // Move temp to the next node
                    cnt--;  // Adjust counter since the head node was removed
                } else {
                    // General case: Remove the node by linking the previous node to the next node
                    prev->next = prev->next->next;
                    temp = temp->next;  // Move temp to the next node
                    cnt--;  // Adjust counter since the current node was removed
                }
            } else {
                // If the current node's value is not in the set, move prev and temp forward
                prev = temp;  // Update prev to current node
                temp = temp->next;  // Move temp to the next node
            }
        }

        // Return the modified head of the list
        return head;
    }
};
