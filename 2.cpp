#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);//��Ž��������
		ListNode* h = head;//�ƶ�ָ��
		int sum = 0;//ÿ��λ�ļӺͽ��
		bool carry = false;//��λ��־
		while (l1 != NULL || l2 != NULL)
		{
			sum = 0;
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			if (carry)
				sum++;
			h->next = new ListNode(sum % 10);
			h = h->next;
			carry = sum >= 10 ? true : false;
		}
		if (carry)
		{
			h->next = new ListNode(1);
		}
		return head->next;
	}
};

int main() {
	ListNode a(2);
	ListNode b(4);
	ListNode c(3);
	ListNode d(5);
	ListNode e(6);
	ListNode f(4);
	a.next = &b;
	b.next = &c;

	d.next = &e;
	e.next = &f;

	ListNode* head = Solution().addTwoNumbers(&a,&d);
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