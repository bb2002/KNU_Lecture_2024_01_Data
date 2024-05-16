#include "stdio.h"

#define MAX_N 100

int main() {
	int num_of_tests;
	scanf("%d", &num_of_tests);
	for (int test = 0; test < num_of_tests; test++) {
		int num_of_candy, request;
		scanf("%d %d", &num_of_candy, &request);

		int heights[MAX_N];
		int max_height = 0;
		for (int i = 0; i < num_of_candy; ++i) {
			scanf("%d", &heights[i]);
			if (heights[i] > max_height) {
				max_height = heights[i];
			}
		}

		int low = 0;
		int high = max_height;
		int result = 0;

		while (low <= high) {
			int mid = (low + high) / 2;
			long long total = 0;
			for (int i = 0; i < num_of_candy; ++i) {
				if (heights[i] > mid) {
					total += heights[i] - mid;
				}
			}

			if (total >= request) {
				result = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		printf("%d\n");
	}
}