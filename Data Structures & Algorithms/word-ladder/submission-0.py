from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if len(beginWord)!=len(endWord):
            return 0
        
        words = set(wordList)
        if endWord not in words:
            return 0
        
        q = deque()
        q.append(beginWord)

        count = 2
        while len(q)!=0:
            x = len(q)

            for i in range(x):
                temp = q.popleft()

                for j in range(len(temp)):
                    for k in "abcdefghijklmnopqrstuvwxyz":

                        new_t = temp[:j] + k + temp[j + 1:]
                        if new_t == endWord:
                            return count
                        
                        if new_t in words:
                            q.append(new_t)
                            words.remove(new_t)
                        
            count += 1

        return 0