/* 
* Valid Parentheses
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all 
* valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <stack>

using namespace std;

bool isValidParentheses(string s){
    if (s.size() == 0 || s.size() % 2) return false;
    stack<char> temp;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            temp.push(s[i]);
            continue;
        }
        if (temp.size() == 0) return false;
        if (s[i] == ')' && temp.top() != '(')
            return false;
        if (s[i] == ']' && temp.top() != '[')
            return false;
        if (s[i] == '}' && temp.top() != '{')
            return false;
        temp.pop();
    }
    return (temp.size()) ? false : true;
}