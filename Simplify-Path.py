class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        tmp = []
        for p in path.split('/'):
            if p == '' or p == '.':
                continue
            elif p == '..':
                if len(tmp) > 0:
                    tmp.pop()
            else:
                tmp.append(p)
                
        return '/' + '/'.join(tmp)