#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1 || !l2)return l1 == NULL ? l2 : l1;//处理传进来有NULL的情况

		//根据链表构建两个栈
		stack<int> s1, s2;
		while (l1 != NULL) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL) {
			s2.push(l2->val);
			l2 = l2->next;
		}

		//根据两个栈计算数值并建表
		int carry = 0, n1 = 0, n2 = 0, sum = 0;
		ListNode* dummy = new ListNode(-1);//创建头节点
		ListNode* tmp = NULL;
		while (!s1.empty() || !s2.empty() || carry) {

			if (s1.empty())n1 = 0;
			else { n1 = s1.top(); s1.pop(); }

			if (s2.empty())n2 = 0;
			else { n2 = s2.top(); s2.pop(); }

			sum = (n1 + n2 + carry);

			//头插法建表
			tmp = new ListNode(sum % 10);
			tmp->next = dummy->next;
			dummy->next = tmp;

			//处理进位，给下一次迭代用
			carry = sum / 10;
		}

		return dummy->next;//注意别把头节点也一起返回了
	}
};

int main() {
	ListNode a(7);
	ListNode b(2);
	ListNode c(4);
	ListNode d(3);
	ListNode e(5);
	ListNode f(6);
	ListNode g(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	
	e.next = &f;
	f.next = &g;

	ListNode* head = Solution().addTwoNumbers(&a,&e);
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