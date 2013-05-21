/*
* Longest Substring Without Repeating Characters
* Given a string, find the length of the longest substring without repeating
* characters. For example, the longest substring without repeating letters for
* ¡°abcabcbb¡± is ¡°abc¡±, which the length is 3. For ¡°bbbbb¡± the longest substring 
* is ¡°b¡±, with the length of 1.
*/

#include <iostream>
#include <string>

using namespace std;

int GetLongestSubstr(string s)
{
    int n = s.length();
    int i=0,j=0;
    int maxLen = 0;
    bool exist[256] = {false};

    while (j<n) {
        if (exist[s[j]]) {
            maxLen = max(maxLen, j-i);
            while (s[i] != s[j]) {
                exist[s[i]] = false;
                i++;
            }
            i++;
            j++;
        } else {
            exist[s[j]] = true;
            j++;
        }
    }
    return max(maxLen, n-i);
}