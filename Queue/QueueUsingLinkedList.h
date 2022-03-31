template <typename T>
class Node {

public:
	T data;
	Node<T>* next;
	
	Node(T d) : data(d), next(NULL){}
	
	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};

template <typename T>
class Queue {

private:
	Node<T>* head;
	Node<T>* tail;
	
public:
	
	Queue() : head(NULL), tail(NULL){}
 
 	bool empty() {
		return head == NULL;	
	}	
 
	void push(T data) {
		Node<T>* new_node = new Node(data);
		if (head == NULL) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = tail->next;
		}
	}
	
	void pop() {
		if (head == NULL) {
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	
	T front() {
		return head->data;
	}
};
