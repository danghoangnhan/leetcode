#
# @lc app=leetcode id=896 lang=python3
#
# [896] Monotonic Array
#

# @lc code=start
from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return True
        
        minValue = nums[0]
        maxValue = nums[0]
        minCheck = True
        maxCheck = True
        
        for i in range(len(nums)):
            if nums[i] <= minValue:
                minValue = nums[i]
            else:
                minCheck = False
            
            if nums[i] >= maxValue:
                maxValue = nums[i]
            else:
                maxCheck = False
            
            if not minCheck and not maxCheck:
                return False
        
        return True
# @lc code=end

