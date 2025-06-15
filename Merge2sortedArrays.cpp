My solution:
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedlist = nullptr;
        ListNode* tail = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode* temp = nullptr;
            if (list1->val <= list2->val) {
                temp = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (mergedlist == nullptr) {
                mergedlist = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        // Append remaining nodes
        if (list1 != nullptr) {
            if (mergedlist == nullptr) {
                mergedlist = list1;
            } else {
                tail->next = list1;
            }
        }

        if (list2 != nullptr) {
            if (mergedlist == nullptr) {
                mergedlist = list2;
            } else {
                tail->next = list2;
            }
        }

        return mergedlist;
    }
};

/*Somebody's solution 
		1. how effeiciently he has used a dummy node just to avoid the condition
			mergedlist == nullptr check always and handle the condition differently
			this handles if one or both of the linked list is empty
		2. appending the orphan nodes in a single condition
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;        
    }
};