#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		ListNode dummy(0);//设置头节点
		dummy.next = head;//连通头节点和给定链表
		ListNode* pre = &dummy;//指向前置节点
		ListNode* curr = head;//指向第一个节点
		while (curr != NULL) {
			while (curr->next != NULL && (curr->val == curr->next->val)) {
				curr = curr->next;//如果下一个节点仍然和这个节点相等，则继续向后移动直至curr指向重复的最后一个节点
			}
			if (pre->next != curr) {//如果存在重复节点
				pre->next = curr->next;//直接指向重复的最后一个结点的下一个节点。
				curr = curr->next;//指针后移
			}
			else {
				curr = curr->next;
				pre = pre->next;
			}
		}
		return dummy.next;
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

	ListNode* head = Solution().deleteDuplicates(&a);
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

	return 0;
}