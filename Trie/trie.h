#include <unordered_map>
#include <string>

using namespace std;

class Trie;

class Node {
private:
	char ch;
	unordered_map<char, Node*> mp;
	bool isTerminal;

public:
	Node(char data) : ch(data), isTerminal(false){}
	
	friend class Trie;
};

class Trie {
private:
	Node* root;

public:
	Trie() {
		root = new Node('\0');
	}
	
	void insert(string word) {
		Node* temp = root;
		
		for (char ch : word) {
			if (temp->mp.count(ch) == 0) {
				temp->mp[ch] = new Node(ch);
			}
			temp = temp->mp[ch];
		}
		temp->isTerminal = true;
	}
	
	bool search(string word) {
		Node* temp = root;
		
		for (char ch : word) {
			if (temp->mp.count(ch) == 0) {
				return false;
			}
			temp = temp->mp[ch];
		}
		return temp->isTerminal;
	} 
};
