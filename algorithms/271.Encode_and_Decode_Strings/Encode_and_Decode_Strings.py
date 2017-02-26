<<<<<<< HEAD
class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        # encode format '<total_length> <seperate length connected with -> <joined str>'
        if not strs:
            return ''
        separate_length = '-'.join([str(len(s)) for s in strs])
        total_length = str(len(separate_length))
        return total_length+' '+separate_length+' '+''.join(strs)

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        if not s:
            return []
        ind = s.index(' ')
        total_length = int(s[:ind])
        separate_length = [int(i) for i in s[ind+1:ind+1+total_length].split('-')]
        joined_str = s[ind+2+total_length:]
        result = []
        cur = 0
        for i in separate_length:
            result += joined_str[cur:cur + i],
            cur += i
        return result
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
=======
class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        # encode format '<total_length> <seperate length connected with -> <joined str>'
        if not strs:
            return ''
        separate_length = '-'.join([str(len(s)) for s in strs])
        total_length = str(len(separate_length))
        return total_length+' '+separate_length+' '+''.join(strs)

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        if not s:
            return []
        ind = s.index(' ')
        total_length = int(s[:ind])
        separate_length = [int(i) for i in s[ind+1:ind+1+total_length].split('-')]
        joined_str = s[ind+2+total_length:]
        result = []
        cur = 0
        for i in separate_length:
            result += joined_str[cur:cur + i],
            cur += i
        return result
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
