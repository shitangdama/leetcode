#include <bits/stdc++.h>

struct node{
	node* pre;
	int key;
	int value;
	node* next;
	node(int k, int v):key(k),value(v),pre(NULL),next(NULL){};
};

class LRUCache{
	unordered_map<int, node*> mp;
	int capacity;
	int size;
	node* head;
	node* tail;
public:
LRUCache(int c){
	if(c<0)return;
	head = new node(-1,-1);
	tail = new node(-1,-1);
	head->next = tail;
	tail->pre = head;
	mp.clear();
	capacity = c;
	size = 0;
}
    
int get(int k) {
	unordered_map<int, node*>::iterator it = mp.find(k);
	if(it != mp.end()){
		node* p = it->second;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		putToHead(p);
		return p->value;
	}
	else
		return -1;
}
    
void set(int k, int val) {
	if(capacity < 1) return; 
	unordered_map<int, node*>::iterator it = mp.find(k);
	if(it != mp.end()){
		node* p = it->second;
		p->pre->next = p->next;
		p->next->pre = p->pre;
		putToHead(p);
		p->value = val;
	}else{
		node* p = new node(k, val);
		putToHead(p);
		mp[k] = p;
		size++;
		if(size>capacity){
			p = tail->pre;
			tail->pre = p->pre;
			p->pre->next = tail;
			it = mp.find(p->key);
			mp.erase(it);
			delete p;
		}
	}
}

void putToHead(node* p)
{
	p->next = head->next;
	p->pre = head;
	head->next->pre = p;
	head->next = p;
}
};class KeyValue {
public:
    int key, value;
    KeyValue *next;
    KeyValue(int key, int value) {
        next = NULL;
        this->key = key;
        this->value = value;
    }
    KeyValue() {
        this->next = NULL;
        this->key = 0;
        this->value = 0;
    }
};

class LRUCache{
private:
    void moveToTail(KeyValue *prev) {
        if (prev->next == tail) {
            return;
        }
        
        KeyValue *node = prev->next;
        prev->next = node->next;
        if (node->next != NULL) {
            hash[node->next->key] = prev;
        }
        tail->next = node;
        node->next = NULL;
        hash[node->key] = tail;
        tail = node;
    }
    
public:
    unordered_map<int, KeyValue *> hash;
    KeyValue *head, *tail;
    int capacity, size;
    
    LRUCache(int capacity) {
        this->head = new KeyValue(0, 0);
        this->tail = head;
        this->capacity = capacity;
        this->size = 0;
        hash.clear();
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        
        moveToTail(hash[key]);
        return hash[key]->next->value;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->next->value = value;
            moveToTail(hash[key]);
        } else {
            KeyValue *node = new KeyValue(key, value);
            tail->next = node;
            hash[key] = tail;
            tail = node;
            size++;
            if (size > capacity) {
                hash.erase(head->next->key);
                head->next = head->next->next;
                if (head->next != NULL) {
                    hash[head->next->key] = head;
                }
                size--;
            }
        }
    }
};

int main() {
    LRUCache l(1);
    l.set(2,1);
    cout << l.get(2) << endl;
    l.set(3,2);
    cout << l.get(2) << endl;
    cout << l.get(3) << endl;
    return 0;
}

