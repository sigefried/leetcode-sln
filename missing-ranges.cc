class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        pre = lower-1
        nums.append(upper+1)
        ret = []
        for i in nums:
            if i == pre + 2:
                ret.append(str(i-1))
            elif i > pre+2:
                ret.append(str(pre+1) + "->" + str(i-1))
            pre = i
        return ret
        
        