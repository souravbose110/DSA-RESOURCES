template<typename T>
class Vector {
private:
	T* arr;
	int current_size;
	int max_size;
	
public:
	Vector(int ms = 1) {
		current_size = 0;
		max_size = ms;
		arr = new T[max_size];
	}
	
	void push_back(const T x) {
		if (current_size == max_size) {
			T* oldArr = arr;
			max_size <<= 1;
			arr = new T[max_size];
			for (int i=0; i<current_size; ++i) {
				arr[i] = oldArr[i];
			}
			delete [] oldArr;
		}
		arr[current_size] = x;
		++current_size;
	}
	
	void pop_back() {
		if (current_size >= 0) {
			--current_size;
		}
	}
	
	bool isEmpty() const {
		return current_size == 0;
	}
	
	int size() const {
		return current_size;
	}
	
	T front() const {
		return arr[0];
	}
	
	T back() const {
		return arr[current_size-1];
	}
	
	T at(int i) const {
		return arr[i];
	}
	
	int capacity() const {
		return max_size;
	}
	
	T operator[] (const int i) const {
		return arr[i];
	}
};
