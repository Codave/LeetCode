#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

//�ⷨһ
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* meet = NULL;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast) {  // ���fast��������β���򷵻�NULL
				return NULL;  //��ʵ�������˳������������Ϊ����
			}
			fast = fast->next;
			if (fast == slow) {
				meet = fast;
				break;
			}
		}
		// if(meet==NULL){
		//     return NULL;  //���û����������֤���޻�
		// }
		while (head && meet) {
			if (head == meet) {
				return head;
			}
			head = head->next;
			meet = meet->next;
		}
		return NULL;  //
	}
};

//�ⷨ��
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast) {  // ���fast��������β
				break;
			}
			fast = fast->next;
			if (fast == slow) {
				slow = head;
				while (slow && fast) {
					if (slow == fast) {
						return slow;
					}
					slow = slow->next;
					fast = fast->next;
				}
			}
		}
		return NULL;
	}
};