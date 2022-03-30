template<typename T>
class Queue {
	
	T *arr;
	int max_size;
	int current_size;
	int front;
	int rear;

public:
	Queue(int default_size = 5) {
		max_size = default_size;
		current_size = 0;
		front = 0;
		rear = max_size - 1;
		arr = new T[default_size];
	}
	
	~Queue() {
		max_size = 0;
		current_size = 0;
		delete [] arr;
	}
	
	bool full() {
		return current_size == max_size;
	}
	
	void push(T data) {
		if (!full()) {
			rear = (rear + 1) % max_size;
			arr[rear] = data;
			++current_size;
		}
	}
	
	bool empty() {
		return current_size == 0;
	}
	
	void pop() {
		if (!empty()) {
			front = (front + 1) % max_size;
			--current_size;
		}
	}
	
	T getFront() {
		return arr[front];
	}
};
