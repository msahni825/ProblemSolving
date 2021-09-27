class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        # counter = 0
        # for i in nums:
        #     counter = counter + 1
        high = len(nums) - 1
        while low <= high:
            mid = int(low + (high-low) / 2)
            #print(mid)
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        return -1