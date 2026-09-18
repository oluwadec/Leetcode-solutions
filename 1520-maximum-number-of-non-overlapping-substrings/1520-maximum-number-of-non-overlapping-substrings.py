class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        n = len(s)
        first = [-1] * 26
        last = [-1] * 26
        
        for i, ch in enumerate(s):
            c = ord(ch) - ord('a')
            if first[c] == -1:
                first[c] = i
            last[c] = i
        
        intervals = []
        
        for i, ch in enumerate(s):
            c = ord(ch) - ord('a')
            if first[c] != i:      # only expand starting from a first occurrence
                continue
            
            end = last[c]
            j = i
            valid = True
            while j <= end:
                cj = ord(s[j]) - ord('a')
                if first[cj] < i:   # needs an occurrence before i -> can't be valid
                    valid = False
                    break
                end = max(end, last[cj])
                j += 1
            
            if valid:
                intervals.append((i, end))
        
        # Greedy interval scheduling: sort by end, pick earliest-ending non-overlapping ones
        intervals.sort(key=lambda p: p[1])
        
        result = []
        last_end = -1
        for start, end in intervals:
            if start > last_end:
                result.append(s[start:end + 1])
                last_end = end
        
        return result