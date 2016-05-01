/*
This is a collections of all my solutions when I practice on the LeetCode.com
for preparing the interview in this Oct.

Each question would have one or more solutions with Python or C++.

The main solution is based on C++ and I will add the solutions with other
languages as comment.

*/
using namespcae std;
class Solution {

public:
  // #1 Two Sum

  // O(n), using hash table with for loop
  vector<int> twoSum(vector<int> &nums, int target) {
    // code here
    unordered_map<int, int> hash;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int toFind = target - nums[i];
      if (hash.find(toFind) != hash.end()) {
        res.push_back(hash[toFind]);
        res.push_back(i);
        return res;
      } else
        hash[nums[i]] = i;
    }
    return res;
  };
  /* Python Verison
  def twoSum(self, nums, target):
  # Version 1
    for p1 in range(len(nums)):
    for p2 in range(p1+1,len(nums)):
        if nums[p2] == target - nums[p1]:
            return [p1+1,p2+1]
  */

  // #2 Add Two
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode res(0), *p = &res;
      int extra = 0;
      while(l1 || l2 || extra){
          if (l1)
              extra += l1->val;
          if (l2)
              extra += l2->val;
          // remeber to delete
          p->next = new ListNode(extra % 10);
          
          extra = extra/10 ? 1 : 0;
          p = p -> next;
          l1 = l1 ? l1->next : l1;
          l2 = l2 ? l2->next : l2;
      }
      return res.next;
  }

  // #9 Palindrome Number
  bool isPalindrome(int x) {
        
    }






};


