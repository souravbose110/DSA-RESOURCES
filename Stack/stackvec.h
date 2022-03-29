#include <vector>

using namespace std;

template<typename T>
class Stack {
private:
	vector<T> v;
	
public:
	void push(T d) {
		v.push_back(d);
	}
	
	void pop() {
		v.pop_back();
	}
	
	bool empty() {
		return v.size() == 0;
	}
	
	T top() {
		return v.back();
	}
};
