class Word:
    def __init__(self):
        self.children = {}
        self.is_end = False
        
class WordDictionary:
    WILDCARD = "."
    
    def __init__(self):
        self.root = Word()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Word()
            node = node.children[char]
        node.is_end = True

    def search(self, word: str) -> bool:
        stack = [(self.root, 0)]
        while stack:
            node, i = stack.pop()
            if i == len(word):
                if node.is_end:
                    return True
            elif word[i] == ".":
                for child_char in node.children:
                    stack.append((node.children[child_char], i + 1))
            elif word[i] in node.children:
                stack.append((node.children[word[i]], i + 1))
        return False

    
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)