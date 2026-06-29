class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return ""

        sizes, res = [], []

        for s in strs:
            sizes.append(len(s))
        
        for size in sizes:
            res.append(str(size))
            res.append(',')
        
        res.append('#')
        res.extend(strs)

        return ''.join(res)
    
    def decode(self, s: str) -> List[str]:
        if not s:
            return []

        sizes, res, i = [], [], 0

        while s[i] != '#':
            j = i

            while s[j] != ',':
                j += 1
            
            sizes.append(int(s[i:j]))
            i = j + 1
        
        i += 1
        for size in sizes:
            res.append(s[i:i + size])
            i += size

        return res
        