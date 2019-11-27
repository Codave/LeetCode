#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//解法一
//class Solution {
//public:
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		int change_len = n - m + 1; //计算需要逆置的节点个数
//		ListNode* pre_head = NULL;  //初始化开始逆置的节点的前驱
//		ListNode* result = head;    //最终转换后的链表头结点，非特殊情况即为head
//		while (head && --m) {
//			pre_head = head;
//			head = head->next;
//		}
//		ListNode* modify_list_tail = head;
//		ListNode* new_head = NULL;
//		while (head && change_len) {
//			ListNode* next = head->next;
//			head->next = new_head;
//			new_head = head;
//			head = next;
//			change_len--;
//		}
//		modify_list_tail->next = head;
//		if (pre_head) {
//			pre_head->next = new_head;
//		}
//		else {
//			result = new_head;
//		}
//		return result;
//	}
//};

//解法二
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		dummy->next = head;
		for (int i = 0; i < m - 1; i++) {
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		for (int i = m; i < n; i++) {
			ListNode* t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	ListNode* head = Solution().reverseBetween(&a, 1, 2);
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << "->NULL";
		}
		head = head->next;
	}
	return 0;
}