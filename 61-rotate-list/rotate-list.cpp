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
        if(head==NULL || head->next==NULL) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        for(int i=0;i<k;i++) {
            ListNode* node = head;
            ListNode* prev = NULL;
            while(node->next!=NULL) {
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
            node->next = head;
            head = node;
        }

        return head;
    }
};