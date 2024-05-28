#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
from typing import List


class Solution:
    def twoSum(self,nums: List[int], target: int) -> List[int]:
        maps = {}
        result = []
        for index in range(len(nums)):
            complement = target - nums[index]
            if complement in maps:
                result.append(maps[complement])
                result.append(index)
                break
            else:
                maps[nums[index]] = index
        return result        
# @lc code=end

