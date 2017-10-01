class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        maxLen = 0;
        pathLen = {0 : 0}
        for l in input.splitlines():
            name  = l.lstrip("\t")
            depth = len(l) - len(name)
            if '.' in name:
                #last path
                maxLen = max(maxLen, pathLen[depth] + len(name))
            else:
                pathLen[depth + 1] = len(name) + 1 + pathLen[depth]
        return maxLen
        