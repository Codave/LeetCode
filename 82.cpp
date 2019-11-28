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
		if (head == NULL || head->next == NULL) return head;
		ListNode* temp = new ListNode(0);//����ͷ�ڵ�ͳһ����
		ListNode* pre, * curr;//ǰ�ýڵ���ֽ��
		temp->next = head;//��ͨͷ�ڵ�͸�������
		pre = temp;//ָ��ͷ�ڵ�
		curr = temp->next;//ָ���һ���ڵ�
		while (curr != NULL) {
			while (curr->next != NULL && (curr->val == curr->next->val)) {
				curr = curr->next;//�����һ���ڵ���Ȼ������ڵ���ȣ����������ƶ�ֱ��currָ���ظ������һ���ڵ�
			}
			if (pre->next != curr) {//�������ظ��ڵ�
				pre->next = curr->next;//ֱ��ָ���ظ������һ��������һ���ڵ㡣 #�˴�Ҳ�������һ�д���delete����Щ�ظ��ڵ�Ŀռ�
				curr = curr->next;//ָ�����
			}
			else {
				curr = curr->next;
				pre = pre->next;
			}
		}

		return temp->next;


	}
};

int main() {
	ListNode a(1);
	ListNode b(1);
	ListNode c(1);
	ListNode d(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;

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