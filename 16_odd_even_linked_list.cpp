/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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


// Solution By saving the nodes at even positions (Multiple pointer solution)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* temp = head;
        ListNode* even = head->next;
        ListNode* save = even;
        ListNode* odd = save;
        while (even != nullptr and even->next != nullptr) {
            temp->next = even->next;
            temp = temp->next;
            even = even->next->next;
            save->next = even;
            save = save->next;
        }
        while (odd != nullptr) {
            temp->next = odd;
            temp = temp->next;
            odd = odd->next;
        }
        temp->next = nullptr;
        return head;
    }
};

// Shorter solution using two pointers
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* cp_nxt = temp2;
        while (temp2 and temp2->next) {
            temp1->next = temp1->next->next;
            temp2->next = temp2->next->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = cp_nxt;
        return head;
    }
};
