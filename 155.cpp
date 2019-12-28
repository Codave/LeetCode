#include<iostream>
#include<stack>
using namespace std;

//解法一
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		_data.push(x);
		if (_min.empty()) {
			_min.push(x);
		}
		else {
			if (x > _min.top()) {
				x = _min.top();
			}
			_min.push(x);
		}
	}

	void pop() {
		_data.pop();
		_min.pop();
	}

	int top() {
		return _data.top();
	}

	int getMin() {
		return _min.top();
	}
private:
	std::stack<int> _data;
	std::stack<int> _min;

};

//解法二
class Solution {
public:
	void push(int value) {
		_data.push(value);
		if (_min.empty()) {
			_min.push(value);
		}
		else if (value <= _min.top()) {
			_min.push(value);
		}
	}

	void pop() {
		if (!_data.empty()) {
			if (_data.top() == _min.top()) {
				_min.pop();
			}
			_data.pop();
		}
	}

	int top() {
		return _data.top();
	}

	int min() {
		return _min.top();
	}
private:
	std::stack<int> _data;
	std::stack<int> _min;
};