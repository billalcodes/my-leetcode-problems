#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    
  };
  ListNode* createNode(int val) {
        ListNode* newNode = new ListNode;
        newNode->val = val;
        newNode->next = nullptr;
        return newNode;
    }
void insertAtBeginning(ListNode*& head, int data) {
    ListNode* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(ListNode*& head, int data) {
    ListNode* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(ListNode*& head, int key) {
    ListNode* temp = head;
    ListNode* prev = nullptr;

    if (temp != nullptr && temp->val == key) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->val != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Element not found in the linked list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = nullptr;
        ListNode* current = nullptr;

        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            if (!temp) {
                temp = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return temp;
    }
};
int main() {
    Solution sol;

    // Create linked lists for the two numbers
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Call the function to add the two numbers
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print the result
    while (result) {
        cout << result->val << " -> ";
        result = result->next;
    }

    // Output: 7 -> 0 -> 8 ->
    
    // Don't forget to deallocate the memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
