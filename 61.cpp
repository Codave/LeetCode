#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL|| head->next==NULL || k==0) return head;
		ListNode* p;
		int n = 1;
		for (p = head; p->next; ++n) {	//���������������forѭ�������ѭ������p����ָ��NULL������ָ�����һ�����
			p = p->next;				//��Ȼp��ʼ��ָ��head��
		}
		p->next = head;
		
		for (int i = 0; i < n - k % n; i++) {
			p = head;
			head = head->next;
		}
		p->next = NULL;

		return head;
	}
};

int main() {

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode* head = Solution().rotateRight(&a, 2);
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