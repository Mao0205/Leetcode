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
        int val, flag = 0;
        index = ans;
        while(l1 != nullptr && l2!=nullptr){
            val = l1->val+l2->val;
            if(flag == 1){
                val++;
                flag = 0;
            }
            if(val >= 10){
                flag = 1;
                val = val%10;
            }
            ListNode* temp = new ListNode(val);
            index->next = temp;
            index = index->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* temp;
        if(l1 != nullptr){
            if(flag == 1){
                l1->val = l1->val + 1;
                temp = l1;
                while(temp->val>=10){
                    temp->val = 0;
                    if(temp->next != nullptr)
                        (temp->next)->val ++;
                    else{
                        ListNode* temp1 = new ListNode(1);
                        temp->next = temp1;
                    }
                    temp = temp->next;
                }
            }
            index->next = l1;
        }else if(l2 != nullptr){
            if(flag == 1){
                l2->val = l2->val+1;
                temp = l2;
                while(temp->val>=10){
                    temp->val = 0;
                    if(temp->next != nullptr)
                        (temp->next)->val ++;
                    else{
                        ListNode* temp1 = new ListNode(1);
                        temp->next = temp1;
                    }
                    temp = temp->next;
                }
            }
            index->next = l2;
        }else{
            if(flag == 1){
                ListNode* temp = new ListNode(1);
                index->next = temp;
            }
        }
        return ans->next;
    }
};
