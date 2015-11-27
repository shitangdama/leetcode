class ValidWordAbbr(object):
    def __init__(self, dictionary):
        """
        initialize your data structure here.
        :type dictionary: List[str]
        """
        self.d = {}
        for word in dictionary:
            abbr = self.getAbbr(word)
            if abbr in self.d:
                self.d[abbr] += word,
            else:
                self.d[abbr] = [word]

    def isUnique(self, word):
        """
        check if a word is unique.
        :type word: str
        :rtype: bool
        """
        abbr = self.getAbbr(word)
        return abbr not in self.d or len(self.d[abbr]) == 1 and self.d[abbr][0] == word
    
    def getAbbr(self,word):
        if len(word) < 3:
            abbr = word
        else:
            abbr = word[0]+str(len(word)-2)+word[-1]
        return abbr


# Your ValidWordAbbr object will be instantiated and called as such:
# vwa = ValidWordAbbr(dictionary)
# vwa.isUnique("word")
# vwa.isUnique("anotherWord")
