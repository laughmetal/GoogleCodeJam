//============================================================================
// Name        : MinesweeperMaster.cpp
// Author      : Xuanchen Tang
// Version     :
// Copyright   : 
// Description : Google Code Jam, Qualification Round 2014, Problem C. Minesweeper Master
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

// Did NOT finish..
int main() {
	int caseNumber;
	cin >> caseNumber;

	int R, C, M;
	int i, j, base, space, count;
	vector<int> length, counter;
	for (i = 0; i < caseNumber; ++i) {
		cin >> R >> C >> M;
		space = R * C - M;

		if (min(R, C) == 1) {
			cout << 'c' << endl;
			for (j = 0; j < space - 1; ++j) {
				cout << '.' << endl;
			}
			for (j = 0; j < M; ++j) {
				cout << '*' << endl;
			}
			continue;
		}

		base = min(R, C);

		while (space > 1) {
			count = space / base;
			if ((space % base) == 1) {
				if (count > 1) {
					length.push_back(base);
					counter.push_back(count - 1);
					space -= (count - 1) * base;
					--base;
				} else {
					break;
				}
			} else {
				length.push_back(base);
				counter.push_back(count);
				space -= count * base;
				--base;
			}
			if (space == 1) {
				length.push_back(1);
				counter.push_back(1);
			}
		}

		if (counter.size() == 0) {
			cout << "Case #" << i + 1 << ":\nImpossible" << endl;
			continue;
		}

		if (accumulate(counter.begin(), counter.end(), 0) > max(R, C)) {
			cout << "Case #" << i + 1 << ":\nImpossible" << endl;
			continue;
		}
	}

	return 0;
}
