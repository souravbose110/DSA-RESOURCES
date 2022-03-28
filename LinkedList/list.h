#include <iostream>

using namespace std;

template<typename T>
class List;

template<typename T>
class ListNode {
private:
	T data;
	
public:
	ListNode<T>* next;

	ListNode(){}
	ListNode(T d) : data(d), next(NULL){}
	ListNode(T d, ListNode* n) : data(d), next(n){}
	
	~ListNode() {
		if (next != NULL) {
			delete next;
		}
	}
	
	friend class List<T>;
};

template<typename T>
class List {
private:
	ListNode<T>* head;
	ListNode<T>* tail;
	
	int helper(ListNode<T>* start, T key) {
		if (start == NULL) {
			return -1;
		}
		if (start->data == key) {
			return 0;
		}
		int idx = helper(start->next, key);
		if (idx == -1) return -1;
		else return idx + 1; 
	}
	
public:
	List() : head(NULL), tail(NULL){}
	
	ListNode<T>* begin() {
		return head;
	}
	
	ListNode<T>* end() {
		return tail;
	}
	
	void print() {
		if (head == NULL) {
			cout << "Empty List";
		}
		else {
			ListNode<T>* temp = head;
			while (temp != NULL) {
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << "NULL\n";
		}
	}
	
	void push_front(T data) {
		ListNode<T>* new_node = new ListNode(data);
		if (head == NULL) {
			head = tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
	}
	
	void push_back(T data) {
		ListNode<T>* new_node = new ListNode(data);
		if (head == NULL) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = tail->next;
		}
	}
	
	void insert(T data, int pos) {
		if (pos == 0) {
			push_front(data);
			return;
		}
		ListNode<T>* temp = head;
		for (int jump=0; jump<pos-1; ++jump) {
			temp = temp->next;
		}
		ListNode<T>* new_node = new ListNode(data);
		new_node->next = temp->next;
		temp->next = new_node;
	}
	
	void pop_back() {
		if (head == NULL) {
			return;
		}
		if (head->next == NULL) {
			delete head;
			return;
		}
		ListNode<T>* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		ListNode<T>* temp2 = tail;
		tail = temp;
		tail->next = NULL;
		delete temp2;
	}
	
	void pop_front() {
		if (head == NULL) {
			return;
		}
		if (head->next == NULL) {
			delete head;
			return;
		}
		ListNode<T>* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	
	void remove(int pos) {
		if (pos == 0) {
			pop_front();
			return;
		}
		ListNode<T>* temp = head;
		for (int jump=0; temp != NULL and jump<pos-1; ++jump) {
			temp = temp->next;
		}
		if (temp == NULL or temp->next == NULL) {
			return;
		}
		ListNode<T>* tolink = temp->next->next;
		temp->next = NULL;
		delete temp->next;
		temp->next = tolink; 
	}
	
	int search(T key) {
		ListNode<T>* temp = head;
		int i = 0;
		
		while (temp != NULL) {
			if (temp->data == key) {
				return i;
			}
			++i;
			temp = temp->next;
		}
		return -1;
	}
	
	int recSearch(T key) {
		return helper(head, key);
	}
	
	~List() {
		if (head != NULL) {
			delete head;
			head = NULL;
		}
	}
};
