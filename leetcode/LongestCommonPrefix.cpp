/* Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0){
        return "";
    }
    
    int minlen = strs.begin()->length();
    for (auto iter = strs.begin(); iter != strs.end(); ++iter) {
        minlen = min(minlen, int(iter->length()));
    }
    string prefix;
    int i = 1;
    while (i <= minlen) {
        prefix =  strs.begin()->substr(0,i);
        for(auto iter = strs.begin(); iter != strs.end(); ++iter){
            if (iter->substr(0, prefix.length()) != prefix) {
               return prefix.substr(0, prefix.length()-1);
            }
        }
        i++;
    }
    return prefix;
}