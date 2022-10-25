#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	cout << "Running file." << endl;
	PriorityQueue<int> example;
	Queue<int> nums;
	Queue<int> copyNums;
	try {
		for (int i = 0; i < 10; i++) {
			nums.push(i);
		}
		cout << nums << endl;
		cout << "Is nums empty? " << nums.isEmpty() << endl;
		cout << "Is copyNums empty? " << copyNums.isEmpty() << endl;
		copyNums(nums);
		copyNums.pop();
		cout << copyNums << endl;
		example.push(5);
	}
	catch(const std::exception& e) {
		cout << endl <<"ERROR: " << e.what() << endl;
	}
	return 0;
}