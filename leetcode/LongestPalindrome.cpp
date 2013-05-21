/*
 * Longest Palindromic Substring
 * 
 * Given a string, find the length of the longest substring without repeating
 * characters. For example, the longest substring without repeating letters
 * for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
 * substring is "b", with the length of 1.
 */

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string longestPalindrome(string s) {
    string stemp = "^";
    for (int i=0; i < s.length(); i++)
        stemp = stemp + "#" + s[i];
    stemp = stemp + "#";
    if (s.empty())
        stemp = "^$";

    int mx = 0, id = 0;
    int p[2002] = {0};
    for(int i=1; i<stemp.length(); i++){
        p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
        while (stemp[i+p[i]] == stemp[i-p[i]])
            p[i]++;
        if (i+p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }

    int maxlen = 0;
    int centerIndex = 0;
    for (int i = 1; i < stemp.length(); i++) {
        if (p[i] > maxlen) {
            maxlen = p[i];
            centerIndex = i;
        }
    }

    return s.substr((centerIndex + 1 - maxlen)/2, maxlen-1);
}