class LinkedNode:
    
    def __init__(self, key=None, value=None, next=None):
        self.key = key
        self.value = value
        self.next = next

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.hash = {}
        self.head = LinkedNode()
        self.tail = self.head
        self.capacity = capacity
    
    def push_back(self, node):
        self.hash[node.key] = self.tail
        self.tail.next = node
        self.tail = node
    
    def pop_front(self):
        del self.hash[self.head.next.key]
        self.head.next = self.head.next.next
        self.hash[self.head.next.key] = self.head
        
    # change "prev->node->next...->tail"
    # to "prev->next->...->tail->node"
    def kick(self, prev):
        node = prev.next
        if node == self.tail:
            return
        prev.next = node.next
        if node.next is not None:
            self.hash[node.next.key] = prev
            node.next = None
        self.push_back(node)

    # @return an integer
    def get(self, key):
        if key not in self.hash:
            return -1
        self.kick(self.hash[key])
        return self.hash[key].next.value

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.hash:
            self.kick(self.hash[key])
            self.hash[key].next.value = value
        else:
            self.push_back(LinkedNode(key, value))
            if len(self.hash) > self.capacity:
                self.pop_front()
        class ListNode:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.next = None
        self.prev = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def insert(self, node):
        if self.head is None:
            self.head = node
        else:
            self.tail.next = node
            node.prev = self.tail
        self.tail = node
            
    def delete(self, node):
        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next
        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev
        del node

class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.list = LinkedList()
        self.dict = {}
        self.capacity = capacity
        
    def _insert(self, key, val):
        node = ListNode(key, val)
        self.list.insert(node)
        self.dict[key] = node
        

    # @return an integer
    def get(self, key):
        if key in self.dict:
            val = self.dict[key].val
            self.list.delete(self.dict[key])
            self._insert(key, val)
            return val
        return -1
        

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, val):
        if key in self.dict:
            self.list.delete(self.dict[key])
        elif len(self.dict) == self.capacity:
            del self.dict[self.list.head.key]
            self.list.delete(self.list.head)
        self._insert(key, val)
 
 
import collections
class LRUCache2:
    def __init__(self, capacity):
        self.cache = collections.OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        val = self.cache[key]
        del self.cache[key]
        self.cache[key] = val
        return val

    def set(self, key, value):
        if key in self.cache:
            del self.cache[key]
        elif len(self.cache) == self.capacity:
            self.cache.popitem(last=False)
        self.cache[key] = value   
        
if __name__ == "__main__":
    cache = LRUCache(3)
    cache.set(1, 1)
    cache.set(2, 2)
    cache.set(3, 3)
    print cache.get(1)
    cache.set(4, 4)
    print cache.get(2)

