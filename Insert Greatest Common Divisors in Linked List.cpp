/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {} // Default constructor initializes val to 0 and next to nullptr
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor initializes val to x and next to nullptr
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor initializes val to x and next to provided node
 * };
 */
class Solution {
public:

    // Function to calculate the greatest common divisor (GCD) of two numbers
    int gcd(int a, int b) {
        
        // Loop until one of the numbers becomes zero
        while (a && b) {
            // If a is greater, reduce it by taking modulo with b
            if (a > b) a = a % b;
            // Otherwise, reduce b by taking modulo with a
            else b = b % a;
        }

        // Return the maximum of a or b, whichever is non-zero (this is the GCD)
        return max(a, b);
    }

    // Function to insert the GCD between every pair of adjacent nodes in the linked list
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or has only one node, return the head as it is
        if (head == nullptr || head->next == nullptr) return head;

        // Initialize temp to traverse the list
        ListNode* temp = head;
        ListNode* temp2;

        // Loop through the list until we reach the end
        while (temp && temp->next) {
            temp2 = temp;               // temp2 points to the current node
            temp = temp->next;          // temp moves to the next node
            int data = gcd(temp->val, temp2->val); // Calculate GCD of the current node and the next node values

            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(data);

            // Insert the new GCD node between temp2 and temp
            temp2->next = gcdNode;
            gcdNode->next = temp;
        }

        // Return the modified head of the list
        return head;
    }
};
