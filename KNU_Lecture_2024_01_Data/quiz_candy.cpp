#include <iostream>
#include <vector>

int main() {
	int treeCount, treeLength;
	int min = 2147483647;
	int max = 0;
	std::vector<int> trees;

	std::cin >> treeCount;
	std::cin >> treeLength;

	for (int i = 0; i < treeCount; ++i) {
		int tmp;
		std::cin >> tmp;
		if (tmp < min) {
			min = tmp;
		}
		if (tmp > max) {
			max = tmp;
		}

		trees.push_back(tmp);
	}
	
	int mid = 0;
	while (min <= max) {
		mid = (max + min) / 2;
		int get = 0;
		for (int i = 0; i < treeCount; ++i) {
			get += (trees[i] - mid < 0) ? 0 : (trees[i] - mid);
		}

		if (get <= treeLength) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}

	std::cout << mid << std::endl;
}