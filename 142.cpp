#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* meet = NULL;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if (!fast) {  // 如果fast遇到链表尾，则返回NULL
				return NULL;  //其实在这里退出代表链表个数为奇数
			}
			fast = fast->next;
			if (fast == slow) {
				meet = fast;
				break;
			}
		}
		// if(meet==NULL){
		//     return NULL;  //如果没有相遇，则证明无环
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