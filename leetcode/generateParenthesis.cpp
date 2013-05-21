/*
* Generate Parentheses
* Given n pairs of parentheses, write a function to generate all combinations
* of well-formed parentheses.
* For example, given n = 3, a solution set is:
* "((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    if (n == 0) {
        ret.push_back("");
        return ret;
    }
    if (n == 1){
        ret.push_back("()");
        return ret;
    }
    set<string> ret1;

    vector<string> last = generateParenthesis(n-1);
    for (auto iter = last.begin(); iter != last.end(); ++iter) {
        int len = iter->size();
        for (int i=0; i<len; ++i) {
            string tmp = *iter;
            tmp.insert(i,string("()"));
            ret1.insert(tmp);
        }
    }

    for (auto iter = ret1.begin(); iter != ret1.end(); ++iter) {
        ret.push_back(*iter);
    }
    return ret;
}