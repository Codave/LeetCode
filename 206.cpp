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
//	ListNode* reverseList(ListNode* head) {
//		ListNode new_head(0);  //0代表初始化NULL,是因为上面有初始化列表
//		while (head) {
//			ListNode* next = head->next;
//			head->next = new_head.next;
//			new_head.next = head;
//			head = next;
//		}
//		return new_head.next;
//	}
//};

//解法二
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = head;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
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
	
	ListNode* head = Solution().reverseList(&a);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}

	return 0;
}