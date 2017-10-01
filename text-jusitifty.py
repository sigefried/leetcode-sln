class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        ret, cur, letters = [], [], 0
        for w in words:
            if len(w) + len(cur) + letters > maxWidth:
                for i in range (maxWidth - letters):
                    cur[i % (len(cur) - 1 or 1)] += ' '
                ret.append(''.join(cur))
                cur, letters = [],0
            cur += [w]
            letters += len(w)
        return ret + [' '.join(cur).ljust(maxWidth)]