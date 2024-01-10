/*
簡化版本。
*/

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
        ListNode * ans = new ListNode();
        ListNode * index;
        int sum, flag = 0;
        index = ans;
        while(l1 != nullptr || l2!=nullptr || flag ==1){
            if(flag == 1){
                sum=1;
                flag = 0;
            }
            else
                sum = 0;
            if(l1!=nullptr){
                sum +=l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2 = l2->next;
            }            
            if(sum >= 10){
                flag = 1;
                sum = sum%10;
            }
            ListNode* temp = new ListNode(sum);
            index->next = temp;
            index = index->next;

        }
        return ans->next;
    }
};
