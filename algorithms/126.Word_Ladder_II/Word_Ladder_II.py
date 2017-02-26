<<<<<<< HEAD
Python Version:
class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    
    def getEntry(self, word, index):
        return word[:index] + word[index + 1:]
        
    def buildIndexes(self, length, dict):
        indexes = []
        for i in range(length):
            index = {}
            for word in dict:
                entry = self.getEntry(word, i)
                words = index.get(entry, [])
                words.append(word)
                index[entry] = words
            indexes.append(index)
        return indexes

    def BFS(self, start, end):
        self.distance = {}
        self.distance[start] = 0
        queue = [start]
        while len(queue) != 0:
            head = queue[0]
            del queue[0]
            for word in self.getNextWord(head):
                if word not in self.distance:
                    self.distance[word] = self.distance[head] + 1
                    queue.append(word)
    
    def DFS(self, curt, target, path):
        if curt == target:
            self.results.append(list(path))
            return
        
        for word in self.getNextWord(curt):
            if self.distance.get(word, -2) + 1 == self.distance[curt]:
                path.append(word)
                self.DFS(word, target, path)
                del path[len(path) - 1]
                
    def getNextWord(self, word):
        for i in range(len(word)):
            entry = self.getEntry(word, i)
            if entry in self.indexes[i]:
                for nextWord in self.indexes[i][entry]:
                    if nextWord != word:
                        yield nextWord
                    
    def findLadders(self, start, end, dict):
        if start is None or end is None or len(start) != len(end):
            return []
        if start not in dict or end not in dict:
            return []
            
        self.dict = dict
        self.indexes = self.buildIndexes(len(start), dict)
        self.BFS(end, start)
        
        self.results = []
        if start in self.distance:
            self.DFS(start, end, [start])
        return self.results
        
=======
Python Version:
class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    
    def getEntry(self, word, index):
        return word[:index] + word[index + 1:]
        
    def buildIndexes(self, length, dict):
        indexes = []
        for i in range(length):
            index = {}
            for word in dict:
                entry = self.getEntry(word, i)
                words = index.get(entry, [])
                words.append(word)
                index[entry] = words
            indexes.append(index)
        return indexes

    def BFS(self, start, end):
        self.distance = {}
        self.distance[start] = 0
        queue = [start]
        while len(queue) != 0:
            head = queue[0]
            del queue[0]
            for word in self.getNextWord(head):
                if word not in self.distance:
                    self.distance[word] = self.distance[head] + 1
                    queue.append(word)
    
    def DFS(self, curt, target, path):
        if curt == target:
            self.results.append(list(path))
            return
        
        for word in self.getNextWord(curt):
            if self.distance.get(word, -2) + 1 == self.distance[curt]:
                path.append(word)
                self.DFS(word, target, path)
                del path[len(path) - 1]
                
    def getNextWord(self, word):
        for i in range(len(word)):
            entry = self.getEntry(word, i)
            if entry in self.indexes[i]:
                for nextWord in self.indexes[i][entry]:
                    if nextWord != word:
                        yield nextWord
                    
    def findLadders(self, start, end, dict):
        if start is None or end is None or len(start) != len(end):
            return []
        if start not in dict or end not in dict:
            return []
            
        self.dict = dict
        self.indexes = self.buildIndexes(len(start), dict)
        self.BFS(end, start)
        
        self.results = []
        if start in self.distance:
            self.DFS(start, end, [start])
        return self.results
        
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
