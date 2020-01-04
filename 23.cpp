#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

////解法一
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		if (lists.empty()) return NULL;
//		int n = lists.size();
//		while (n > 1) {
//			int k = (n + 1) / 2;
//			for (int i = 0; i < n / 2; i++) {
//				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
//			}
//			n = k;
//		}
//		return lists[0];
//	}
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode dummy(-1);
//		ListNode* cur = &dummy;
//		while (l1 && l2) {
//			if (l1->val < l2->val) {
//				cur->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				cur->next = l2;
//				l2 = l2->next;
//			}
//			cur = cur->next;
//		}
//		if (l1) cur->next = l1;
//		if (l2) cur->next = l2;
//		return dummy.next;
//	}
//};

//解法二
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto cmp = [](ListNode*& a, ListNode*& b) {
			return a->val > b->val;
		};
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
		for (auto node : lists) {
			if (node) q.push(node);
		}
		ListNode dummy(-1);
		ListNode* cur = &dummy;
		while (!q.empty()) {
			auto t = q.top();
			q.pop();
			cur->next = t;
			cur = cur->next;
			if (cur->next) q.push(cur->next);
		}
		return dummy.next;
	}
};

int main() {

	return 0;
}