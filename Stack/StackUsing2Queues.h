#include <queue>

using namespace std;

template<typename T>
class Stack {
	
private:
	queue<T> q1, q2;
	
public:

	Stack() {
		q1 = queue<T>();
		q2 = queue<T>();
	}
	
	void push(T data) {
		if (q1.empty()) {
			q2.push(data);
		}
		else {
			q1.push(data);
		}
	}
	
	void pop() {
		if (q1.empty() and q2.empty()) {
			return;
		}
		if (q1.empty()) {
			while (!q2.empty()) {
				T val = q2.front(); q2.pop();
				if (!q2.empty()) {
					q1.push(val);
				}
			}
		}
		else {
			while (!q1.empty()) {
				T val = q1.front(); q1.pop();
				if (!q1.empty()) {
					q2.push(val);
				}
			}
		}
	}
	
	T top() {
		if (q1.empty() and q2.empty()) {
			return NULL;
		}
		if (q1.empty()) {
			while (!q2.empty()) {
				T val = q2.front(); q2.pop();
				if (!q2.empty()) {
					q1.push(val);
				}
				else {
					q1.push(val);
					return val;
				}
			}
		}
		else {
			while (!q1.empty()) {
				T val = q1.front(); q1.pop();
				if (!q1.empty()) {
					q2.push(val);
				}
				else {
					q2.push(val);
					return val;
				}
			}
		}
	}
	
	bool empty() {
		return (q1.empty() and q2.empty());
	}
};
