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
    bool hasCycle(ListNode* head) {
        if (!head) return false;

        unordered_set<int> track;
        ListNode* iter = head;
        
        while (iter->next)
        {
            if (track.contains(iter->val)) return true;
            else track.emplace(iter->val);

            iter = iter->next;
        }

        return false;
    }
};
