/*
This is a collections of all my solutions when I practice on the LeetCode.com for preparing the interview in this Oct.

Each question would have one or more solutions with Python or C++.

The main solution is based on C++ and I will add the solutions with other languages as comment.

*/
class Solution{


public:


// #1 Two Sum
	vector<int> twoSum(vector<int> nums&, int target){
		// code here
	}



	/* Python Verison

    def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
   
    """
    # Version 1
    for p1 in range(len(nums)):
        for p2 in range(p1+1,len(nums)):
            if nums[p2] == target - nums[p1]:
                return [p1+1,p2+1]
    # Version 2
    nums.sort()
    for p1 in range(len(nums)):
        left = p1
        mid = len(nums[p1+1:]) // 2
        right = len(nums) - 1
        while nums[p1] + nums[mid] > target:
            mid = len()
	*/
};

