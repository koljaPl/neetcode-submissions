class TreeNode:
    def __init__(self):
        self.children = {}
        self.is_endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TreeNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        
        for c in word:
            if c not in cur.children:
                cur.children[c] = TreeNode()
            cur = cur.children[c]
        
        cur.is_endOfWord = True

    def search(self, word: str) -> bool:

        def dfs(j, root):
            cur = root

            for i in range(j, len(word)):
                c = word[i]

                if c == ".":
                    for child in cur.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                
                else:
                    if c not in cur.children:
                        return False
                    cur = cur.children[c]
            
            return cur.is_endOfWord

        return dfs(0, self.root)
