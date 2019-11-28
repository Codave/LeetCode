#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* reverse(ListNode* head) {
		ListNode* root = nullptr;
		while (head) {
			ListNode* next = head->next;
			head->next = root;
			root = head;
			head = next;
		}
		return root;
	}
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode* fast = head, * slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (fast) // ³¤¶ÈÎªÆæ 5 / 2 = 2 
			slow = slow->next; //2->3
		slow = reverse(slow);
		while (head && slow) {
			if (head->val != slow->val) return false;
			head = head->next;
			slow = slow->next;
		}
		return true;

	}
};
int main() {
	ListNode a(1);
	ListNode b(1);
	ListNode c(1);
	ListNode d(2);
	ListNode e(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	int res = Solution().isPalindrome(&a);
	cout << res << endl;

	return 0;
}