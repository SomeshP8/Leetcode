class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        subset=1<<n
        ans=[]
        for num in range(subset):
            list=[]
            for i in range(n):
                if num & (1<<i):
                    list.append(nums[i])
            ans.append(list)

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna