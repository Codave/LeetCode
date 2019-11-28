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
		ListNode dummy(0);//����ͷ�ڵ�
		dummy.next = head;//��ͨͷ�ڵ�͸�������
		ListNode* pre = &dummy;//ָ��ǰ�ýڵ�
		ListNode* curr = head;//ָ���һ���ڵ�
		while (curr != NULL) {
			while (curr->next != NULL && (curr->val == curr->next->val)) {
				curr = curr->next;//�����һ���ڵ���Ȼ������ڵ���ȣ����������ƶ�ֱ��currָ���ظ������һ���ڵ�
			}
			if (pre->next != curr) {//��������ظ��ڵ�
				pre->next = curr->next;//ֱ��ָ���ظ������һ��������һ���ڵ㡣
				curr = curr->next;//ָ�����
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