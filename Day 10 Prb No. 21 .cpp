#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node create kiya merged list banane ke liye
        ListNode dummy(0);

        // Tail merged list ke last node ko point karega
        ListNode* tail = &dummy;

        // Dono lists ko compare karte hue traverse karo
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Jo list bach gayi ho usko attach kar do
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};

// Linked List create karne ka function
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    return head;
}

// Linked List print karne ka function
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter size of first sorted list: ";
    cin >> n1;

    cout << "Enter elements of first list: ";
    ListNode* list1 = createList(n1);

    cout << "Enter size of second sorted list: ";
    cin >> n2;

    cout << "Enter elements of second list: ";
    ListNode* list2 = createList(n2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}