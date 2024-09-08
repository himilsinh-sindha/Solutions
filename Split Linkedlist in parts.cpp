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
    // Function to split the linked list into 'k' parts
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Special case: If k is 1, just return the entire list as the only part
        if (k == 1)
            return {head};

        // Calculate the total number of nodes in the list
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++; // Increment the counter for each node
            temp = temp->next;
        }

        // Reset temp back to the head of the list
        temp = head;
        // Result vector to store the heads of the k parts
        vector<ListNode*> ans;
        ListNode* prev = nullptr; // Pointer to track the previous node

        // If k is greater than the number of nodes, we need to create k parts,
        // some of which will be null if there are not enough nodes.
        if (k > cnt) {
            while (k--) {
                if (temp) {
                    // Add the current node as the part's head
                    prev = temp;
                    // Move to the next node
                    temp = temp->next;
                    // Detach the current node from the list to form a part
                    prev->next = nullptr;
                    ans.push_back(prev);
                } else {
                    // If there are no more nodes, add nullptr as an empty part
                    ans.push_back(temp);
                }
            }
        } else {
            // If k is less than or equal to the number of nodes
            while (k) {
                if (temp) {
                    // Calculate the size of the current part
                    int size = cnt / k; // Base size for each part

                    // If there are remaining nodes, distribute one extra node
                    if (cnt % k != 0)
                        size++;

                    // Add the current node as the head of the part
                    ans.push_back(temp);

                    // Reduce the number of remaining nodes by the size of the part
                    cnt = cnt - size;

                    // Traverse 'size' nodes to form the current part
                    while (size && temp) {
                        prev = temp;
                        temp = temp->next;
                        size--;
                    }

                    // Detach the current part from the remaining list
                    prev->next = nullptr;
                } else {
                    // If no nodes are left, add nullptr for the remaining parts
                    ans.push_back(temp);
                }

                // Decrease the number of remaining parts
                k--;
            }
        }

        // Return the vector containing the heads of the k parts
        return ans;
    }
};
