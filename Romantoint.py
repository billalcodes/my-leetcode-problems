class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        my_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        temp = 0
        r = 0
        i = 0
        while i < len(s):
            if i < len(s) - 1 and s[i:i+2] in ['IV', 'IX', 'XL', 'XC', 'CD', 'CM']:
                temp = my_dict[s[i+1]] - my_dict[s[i]]
                r += temp
                i += 2
            else:
                temp = my_dict[s[i]]
                r += temp
                i += 1
        return r



# Example usage:
sol = Solution()
print(sol.romanToInt('MCMXCIV'))  # This should print 1994