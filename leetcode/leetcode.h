#ifndef _LEETCODE_H_
#define _LEETCODE_H_


#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0){}
};

int GetLongestSubstr(std::string str);
std::vector<int> twoSum(std::vector<int> &numbers, int target);
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
std::string ZigZagconvert(std::string s, int nRows);
int reverse(int x);
int StringToInterger(char *str);
bool isPalindrome(int x);
std::string longestCommonPrefix(std::vector<std::string> &strs);
int romanToInt(std::string s);
std::string IntToRoman(int num);
int maxArea(std::vector<int> &height);
double findMedianSortedArrays(int A[], int m, int B[], int n);
std::string longestPalindrome(std::string s);
std::vector<std::vector<int> > threeSum(std::vector<int> &num);
int threeSumClosest(std::vector<int> &sum, int target);
std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target);
std::vector<std::string> letterCombinations(std::string digits);
ListNode *removeNthFromEnd(ListNode *head, int n);
bool isValidParentheses(std::string s);
std::vector<std::string> generateParenthesis(int n);
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

#endif