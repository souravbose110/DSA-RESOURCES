template<typename T>
class Stack;

template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	
	Node(T d) : data(d), next(NULL){}
};

template<typename T>
class Stack {
private:
	Node<T>* head;
	
public:
	Stack() : head(NULL){}
	
	void push(T data) {
		Node<T>* new_node = new Node(data);
		new_node->next = head;
		head = new_node;
	}
	
	void pop() {
		if (head == NULL) {
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	
	bool empty() {
		return head == NULL;
	}
	
	T top() {
		return head->data;
	}
};
