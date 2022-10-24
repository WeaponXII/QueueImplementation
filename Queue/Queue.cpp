#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	cout << "Running file." << endl;
	PriorityQueue<int> example;
	Queue<int> nums;
	try {
		for (int i = 0; i < 10; i++) {
			nums.push(i);
		}
		cout << nums << endl;
	}
	catch(const std::exception& e) {
		cout << endl <<"ERROR: " << e.what() << endl;
	}
	return 0;
}