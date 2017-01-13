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

    // # 26 Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int>& nums)
    {
        vector<int>::iterator it = nums.begin();
        int res = nums.size();
        while(it != nums.end())
        {
            int dup = 0;
            vector<int>::iterator cur = it;
            while(cur+1 != nums.end() && *cur == *(cur+1))
            {
                dup++;
                nums.erase(cur);
            }
            res -= dup;
            it = cur;
            it++;
        }
        return res;
    }

    // # 27 Remove elements
    int removeElement(vector<int>& nums, int val)
    {
        vector<int>::iterator it = nums.begin();
        int len = nums.size();
        while(it < nums.end())
        {
            cout << *it << endl;
            if(*it == val)
            {
                nums.erase(it);
                --len;
            }
            else
                it++;
        }
        return len;
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

    // # 111 Minimum Depth of Binary Tree
    int minDepth(TreeNode* root){
        int level = 0;

    }
    bool hasTwoChildren(TreeNode* root)
    {
        return (root->left)&&(root->right);
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
    // # 167 Two Sum II - Input array is sorted
    vector<int> twoSum(vector<int>&nums, int target){
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++) {
            int toFind = target - numbers[i];
            if (hash.find(toFind) != hash.end()) {
                res.push_back(hash[toFind]+1);
                res.push_back(i+1);
                return res;
            } else
                hash[numbers[i]] = i;
        }
        return res;
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

// # 232  Implement Queue using Stacks
class Queue {
private:
    vector<int> stack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack.erase(stack.begin());
    }

    // Get the front element.
    int peek(void) {
        return stack[0];
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack.empty();
    }
};

// 50. Pow(x, n)
// Implement pow(x, n).
/*
double myPow(double x, int n) {

    }
*/
// 413. Arithmetic Slices
/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.
1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

int numberOfArithmeticSlices(vector<int>& A) {

}

*/
// 406. Queue Reconstruction by Height
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

}

*/


// 38. Count and Say
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

string countAndSay(int n) {

}

*/
// 112. Path Sum
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
            5
            / \
           4   8
          /   / \
         11  13  4
        /  \      \
       7    2      1
Given the below binary tree and sum = 22,
*/

// 257. Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.


// 412. Fizz Buzz
/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
