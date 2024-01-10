/*
基本上將兩個lined list相加到其中一個結束，並將剩下的直接接在尾部。除了加法需要額外處理進位問題。
時間上比2版(較簡潔)得快。

複習new的用法，會動態生成空間並回傳指標。
ListNode* temp = new ListNode(val);
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* index = ans;
        int val, flag = 0;
        while (l1 != nullptr && l2 != nullptr) {
            val = (l1->val + l2->val + flag) % 10;
            flag = (l1->val + l2->val + flag) / 10;
            index->next = new ListNode(val);
            index = index->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != nullptr) {
            while (l1 != nullptr) {
                val = (l1->val + flag) % 10;
                flag = (l1->val + flag) / 10;
                index->next = new ListNode(val);
                index = index->next;
                l1 = l1->next;
            }
        } else {
            while (l2 != nullptr) {
                val = (l2->val + flag) % 10;
                flag = (l2->val + flag) / 10;
                index->next = new ListNode(val);
                index = index->next;
                l2 = l2->next;
            }
        }
        if (flag == 1) {
            index->next = new ListNode(1);
        }
        return ans->next;
    }
};
