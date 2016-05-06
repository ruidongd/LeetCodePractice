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
    // # 1 Two Sum
    // O(n), using hash table with for loop
    vector<int> twoSum(vector<int> &nums, int target) {
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
    }
  /* Python Verison
  def twoSum(self, nums, target):
  # Version 1
  for p1 in range(len(nums)):
  for p2 in range(p1+1,len(nums)):
      if nums[p2] == target - nums[p1]:
          return [p1+1,p2+1]
  */

  // # 2 Add Two
  // Time: O(max(len(l1), len(l2)+1)) or O(max(len(l1), len(l2)))
  // If the sum of the last val of l1 and l2 is greater than or equal to 10
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode res(0), *p = &res;
        int extra = 0;
        while (l1 || l2 || extra) {
            if (l1)
                extra += l1->val;
            if (l2)
                extra += l2->val;
                // remeber to delete
            p->next = new ListNode(extra % 10);
            extra = extra / 10 ? 1 : 0;
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return res.next;
    }


    // # 21 Merge Two Sorted Lists
    // Time complexcity: O(len(l1) + len(l2)) = O(n)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* p = res;
        while(l1 || l2){
            if(l1 && l2){
                p->next = (l1->val <= l2->val) ? l1 : l2;
                if(p->next == l1)
                    l1 = l1->next;
                else
                    l2 = l2->next;
            }
            else{
                if (l1){
                p->next = l1;
                l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            p = p->next;
        }
        return res->next;
    }
    // # 66 Plus One
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while(digits[index] == 9 && index >= 0){
            digits[index] = 0;
            index--;
        }
        if(index >= 0){
            digits[index] += 1;
            return digits;
        }
        else{
            vector<int> res;
            res.push_back(1);
            int i = 0;
            while(i< digits.size()){
                res.push_back(0);
                i++;
            }
            return res;
        }
    }
    // # 141 Linked List Cycle
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow){
            slow = slow->next;
            if(fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;
            if(fast == slow)
                return true;
        }
        return false;
    }
    // # 171 Excel Sheet Column Number
    int titleToNumber(string s) {
        int res = 0;
        for (int index = 0; index >= 0; index-- ){
            res += pow(26,index) * (s[s.length()-index-1] - 'A' +1);
        }
    return res;
    }

    // # 202 Happy Number
    bool isHappy(int n) {
        int count = 100;
        while (count) {
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            };
            n = sum;
            count--;
        }
        return n == 1;
    }

  // # 206 Reverse Linked List
    ListNode *reverseList(ListNode *head) {
        ListNode *res = nullptr;
        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = res;
            res = p;
        }
        return res;
    }
    // # 235 Lowest Common Ancestor
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> firstPath;
        vector<TreeNode *> secondPath;
        TreeNode *p1 = root;
        TreeNode *p2 = root;
        while (p1) {
            firstPath.push_back(p1);
            if (p1->val == p->val)
                break;
            else if (p->val < p1->val)
                p1 = p1->left;
            else if (p->val > p1->val) {
                p1 = p1->right;
            }
        }
        while (p2) {
            secondPath.push_back(p2);
            if (p2->val == q->val)
                break;
            else if (q->val > p2->val)
                p2 = p2->right;
            else if (q->val < p2->val)
                p2 = p2->left;
        }

        for (int index2 = secondPath.size() - 1; index2 >= 0; index2--) {
            for (int index1 = firstPath.size() - 1; index1 >= 0; index1--) {
                if (firstPath[index1] == secondPath[index2]) {
                    return firstPath[index1];
                }
            }
        }
    return nullptr;
    }
    // # 263 Ugly Number
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        else {
            while (num % 2 == 0)
                num = num / 2;
            while (num % 3 == 0)
                num = num / 3;
            while (num % 5 == 0)
                num = num / 5;
            return num == 1;
        }
    }
  // Awesome Verison
  /*
  4 is double of 2 so it is more effiective to solve this problem
  bool isUgly(int num) {
      for (int i=2; i<6 && num>0; i++)
          while (num % i == 0)
              num /= i;
      return num == 1;
  }
  */

  // # 338 Count 1 bits
  // Time: O(n) Space: O(n)
  vector<int> countBits(int num) {
    vector<int> res;
    res.push_back(0);
    int count = 0;
    int target = 1;
    for (int i = 1; i <= num; ++i) {
        res.push_back(1 + res[count]);
        count++;
        if (count == target) {
            target *= 2;
            count = 0;
        }
    }
    return res;
  }
  /* Awesome Verison
  // Time: O(n) Space: O(n)
  vector<int> countBits(int num) {
    vector<int> res(nums+1, 0);
    for(int i = 1; i <= num; ++i){
        res[i] = res[i&(i-1)] +1;
    }
    return res;
  }
  */
  // # 342 Power of Four
    bool isPowerOfFour(int num) {
        while (num != 1){
            if (num && num % 4 == 0)
                num /= 4;
            else
                return false;
        }
        return true;
  }
  /* Awesome Version
  bool isPowerOfFour(int num){
    if(num>0 && num&(num-1) && (num-1)%3 == 0)
        return true;
    return false;
  }
}
  */
};
