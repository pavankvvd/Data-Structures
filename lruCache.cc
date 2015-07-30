#include <map>
#include <iostream>
using namespace std;

struct node {
    int key;
    int value;
    struct node *prev;
    struct node *next;
};
typedef struct node Node;

Node* createNode(int key, int value) {
    Node *newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *head = NULL;
Node *last = NULL;
std::map<int, Node*> cacheMap;

class LRUCache{
public:
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void moveToHead(Node *old) {
        if (head == old) {
            return;
        }
        old->prev->next = old->next;
        if (old->next) {
            old->next->prev = old->prev;
        } else {
            last = old->prev;
        }
        head->prev = old;
        old->next = head;
        old->prev = NULL;
        head = old;
    }
    
    int get(int key) {
//      cout << "search on Key " << key << endl;
        std::map<int, Node*>::iterator itr = cacheMap.find(key);
        if (itr == cacheMap.end()) {
            return -1;
        }
        moveToHead(itr->second);
        return itr->second->value;
    }
    
    void set(int key, int value) {
        std::map<int, Node*>::iterator itr = cacheMap.find(key);
        if (itr == cacheMap.end()) {
//          cout << "Key not found" << endl;
            Node *newNode = createNode(key, value);
            if (cacheMap.size() == capacity) {
//              cout << "Cache is full " << endl;
                cacheMap.erase(last->key);
//              cout << "erased from cacheMap " << endl;
                removeLastNode();
//              cout << "removed last node " << endl;
            }
            attachToList(newNode);
            cacheMap.insert(std::pair<int, Node*>(key,newNode));
        } else if (itr != cacheMap.end()) {
//          cout << "Key found" << endl;
            Node *old = itr->second;
//          cout << old->key << endl;
//          cout << old->value << endl;
            old->value = value;
            moveToHead(old);
        }
    }
    
    void removeLastNode() {
        if (head == last) {
            delete head;
            head = NULL;
            last = NULL;
        } else {
            Node *temp = last;
            last = last->prev;
            delete temp;
            last->next = NULL;
        }
    }
    
    void attachToList(Node *newNode) {
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};

void printList()
{
    Node *temp = head;
    while (temp) {
        cout << "Key: " << temp->key << "  Value : " << temp->value << endl;
        temp = temp->next;
    }
}

int main()
{
    LRUCache cache(2);
    cout << cache.get(2) << endl;
    cache.set(2,6);    
    cout << cache.get(1) << endl;
    cache.set(1,5);    
    cache.set(1,2);    
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    printList();
}
