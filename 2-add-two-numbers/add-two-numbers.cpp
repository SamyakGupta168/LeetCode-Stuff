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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1, num2;
        while(l1 != nullptr) {
            num1 += char(l1->val + '0');
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            num2 += char(l2->val + '0');
            l2 = l2->next;
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(num1.size() < num2.size()) swap(num1, num2);

        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        string sum = "";
        while(i2 >= 0) {
            int d1 = num1[i1] - '0', d2 =  num2[i2] - '0';
            int d = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            sum += char(d + '0');
            i1--, i2--;
        }

        while(i1 >= 0) {
            int d1 = num1[i1] - '0';
            int d = (d1 + carry) % 10;
            carry = (d1 + carry) / 10;
            sum += char(d + '0');
            i1--;
        }

        if(carry) sum += char(carry + '0');

        int i = 0;
        ListNode* prev;
        ListNode* ans = nullptr;
        while(i < sum.size()) {
            ListNode* curr = new ListNode(sum[i] - '0');
            if(ans == nullptr) {
                ans = curr;
                prev = curr;
            } else {
                prev->next = curr;
                prev = curr;
            }
            i++;
        }

        return ans;
    }
};