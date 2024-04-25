#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int infinity = 99999;
	int problem_num = 0;
	cin >> problem_num;

	for (int problem = 0; problem < problem_num; ++problem) {
		int query_num = 0;
		cin >> query_num;
		stack<int> min_stack;
		stack<int> max_stack;

		min_stack.push(infinity);
		max_stack.push(infinity);
		for (int query = 0; query < query_num; ++query) {
			int input1, input2 = 0;
			cin >> input1;
			switch (input1) {
			case 1:
				int new_block;
				cin >> input2;
				new_block = input2;
				min_stack.push(min(min_stack.top(), new_block));
				max_stack.push(max(max_stack.top(), new_block));
				cout << min_stack.top() << " " << max_stack.top() << "\n";
				break;
			case 2:
				if (min_stack.top() != infinity) {
					min_stack.pop();
				}
				if (max_stack.top() != -infinity) {
					max_stack.top();
				}
				break;
			}
		}
	}
}