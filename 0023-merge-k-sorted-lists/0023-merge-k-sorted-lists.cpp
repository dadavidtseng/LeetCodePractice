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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;

        // merge two lists as we iterate through lists
        for (int i = 0; i < static_cast<int>(lists.size()); ++i) {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

    ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
        // initialize a dummy node and attach a tail node on that dummy node
        ListNode dummy(0, nullptr);
        ListNode* tail = &dummy;

        // exit the loop when listA and listB are both exhausted
        while (listA != nullptr && listB != nullptr) {
            // when listA's value is smaller than listB's value
            // 1. attach listA to tail
            // 2. advance listA
            if (listA->val < listB->val) {
                tail->next = listA;
                listA = listA->next;
            }
            // when listA's value is larger or equal to listB's value
            // 1. attach listB to tail
            // 2. advance listB
            else {
                tail->next = listB;
                listB = listB->next;
            }

            // advance tail
            tail = tail->next;
        }

        // attach the remaining of listA and listB
        tail->next = (listA != nullptr) ? listA : listB;

        // return the head of the merged list
        return dummy.next;
    }
};