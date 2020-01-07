#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//方法一
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while (next) {
			if (cur->val == next->val) {
				next = next->next;
				cur->next = next;
			}
			else {
				cur = cur->next;
				next = next->next;
			}
			
		}
		return head;
	}
};

//方法二
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* cur = head;
		while (cur) {
			if (cur->next && cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}
};

int main() {

	ListNode a(1);
	ListNode b(2);
	ListNode c(2);
	a.next = &b;
	b.next = &c;
	ListNode* head = Solution().deleteDuplicates(&a);
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << endl;
		}
		head = head->next;
	}

	return 0;
}