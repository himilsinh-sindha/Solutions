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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int cnt = 1;
        ListNode* temp = head;

        while(temp->next){
            temp=temp->next;
            cnt++;
        }

        k = k%cnt;
        if(k==0) return head;

        temp->next = head;

        int stop = cnt - k;

        ListNode* prev = nullptr;

        while(stop){
            prev = head;
            head = head->next;
            stop--;
        }

        prev->next = nullptr;

        return head;
    }
};