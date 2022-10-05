#include"stack.h"
#include<iostream>

struct point {
	int x = 3;
	int y = 5;
	int z = 4;
};

int main() {
	point p;
	stack<int> q;
	std::string a;
	try {
		a = q.pop();
	}
	catch (Exception& e) {
		std::cerr << e.get();
	}

	for (int i = 1; i <= 10; i++) 
	{
		q.push(i);
	}
	
	stack<point> pq;
	pq.push(p);

	cout << q;
	return 0;
}