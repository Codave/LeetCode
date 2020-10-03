//#include<iostream>
//#include<stack>
//using namespace std;
//
////方法一
//class MyQueue {
//public:
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		_input.push(x);
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//		adjust();
//		int x = _output.top();
//		_output.pop();
//		return x;
//	}
//
//	/** Get the front element. */
//	int peek() {
//		adjust();
//		return _output.top();
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		return _input.empty() && _output.empty();
//	}
//private:
//	void adjust() {
//		if (!_output.empty()) {
//			return;
//		}
//		while (!_input.empty()) {
//			_output.push(_input.top());
//			_input.pop();
//		}
//	}
//	stack<int> _input;
//	stack<int> _output;
//};
//
////方法二 入栈就调整好顺序更好
//class Solution
//{
//public:
//	void push(int node) {
//		while (!stack1.empty()) {
//			stack2.push(stack1.top());
//			stack1.pop();
//		}
//		stack2.push(node);
//		while (!stack2.empty()) {
//			stack1.push(stack2.top());
//			stack2.pop();
//		}
//	}
//
//	int pop() {
//		int x = stack1.top();
//		stack1.pop();
//		return x;
//	}
//
//	int peek() {
//		return stack1.top();
//	}
//
//	bool empty() {
//		return stack1.empty();
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};