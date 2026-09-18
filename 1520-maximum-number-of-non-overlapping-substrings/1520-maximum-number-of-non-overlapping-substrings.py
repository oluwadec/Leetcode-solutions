class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        n = len(s)
        # Convert once to integer codes (0-25) to avoid repeated ord() calls
        codes = [ord(c) - 97 for c in s]
        
        first = [-1] * 26
        last = [-1] * 26
        for i, c in enumerate(codes):
            if first[c] == -1:
                first[c] = i
            last[c] = i
        
        intervals = []
        append = intervals.append  # cache method lookup
        
        for i, c in enumerate(codes):
            if first[c] != i:
                continue
            
            end = last[c]
            j = i
            valid = True
            while j <= end:
                cj = codes[j]
                fj = first[cj]
                if fj < i:
                    valid = False
                    break
                lj = last[cj]
                if lj > end:
                    end = lj
                j += 1
            
            if valid:
                append((end, i))   # store as (end, start) so default sort works directly
        
        intervals.sort()  # sorts by end first (no key= overhead)
        
        result = []
        last_end = -1
        for end, start in intervals:
            if start > last_end:
                result.append(s[start:end + 1])
                last_end = end
        
        return result