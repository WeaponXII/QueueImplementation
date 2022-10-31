#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	cout << "Running file." << endl;
	PriorityQueue<int> example;
	Queue<int> nums;
	Queue<int> inputNums;
	Queue<int> addNums;
	PriorityQueue<int> copyExample;
	PriorityQueue<int> addExample;
	try {
		for (int i = 0; i < 10; i++) {
			nums.enqueue(i);
		}
		cout << nums << endl;
		cout << "Is nums empty? " << nums.isEmpty() << endl;
		Queue<int> copyNums(nums);
		nums == copyNums ? cout << "Nums and copyNums are equal" << endl : cout << "Nums and copyNums are not equal values." << endl;
		copyNums.dequeue();
		nums == copyNums ? cout << "Nums and copyNums are equal after dequeue" << endl : cout << "Nums and copyNums are not equal values after dequeue." << endl;
		cout << copyNums << endl;
		example.enqueue(5);
		example.enqueue(5, copyNums);
		example.enqueue(7, nums);
		cout << example << endl;
		cin >> inputNums;
		cin.ignore();
		example.dequeue();
		copyExample = example;
		copyExample == example ? cout << "copyExample is equal to example" << endl : cout << "copyExample and example are not equal" << endl;
		cout << copyExample << endl;
		cin >> copyExample;
		cin.ignore();
		addExample = copyExample + example;
		cout << copyExample<< endl;
		//Below creates a priority queue with the copy constructor then moves it to moveExample.
		PriorityQueue<int> moveExample = PriorityQueue<int>(copyExample);
		cout << "Move example is: "<<endl<<moveExample<<endl;
		addNums = inputNums + copyNums;
		moveExample.enqueue(3,addNums);
		cout << "After enqueue moveExample is: " << endl << moveExample << endl;

	}
	catch(const std::exception& e) {
		cout << endl <<"ERROR: " << e.what() << endl;
	}
	return 0;
}