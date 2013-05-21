/* 
* Letter Combinations of a Phone Number
* Given a digit string, return all possible letter combinations that the
* number could represent. A mapping of digit to letters (just like on the
* telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could
* be in any order you want.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits) {
    string tables[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ret;

    if (digits.empty()) {
        ret.push_back("");
        return ret;
    }
    if (digits.size() == 1){
        string str = tables[digits[0] - '2'];
        for (size_t i=0; i<str.size();i++){
            ret.push_back(str.substr(i,1));
        }
    } else {
        string str = tables[digits[0] - '2'];
        for (size_t i=0; i<str.size();i++){
            vector<string> last = letterCombinations(digits.substr(1, digits.size()-1));
            for (auto iter = last.begin(); iter != last.end(); ++iter) {
                string tmp = string(str.substr(i,1)) + *iter;
                ret.push_back(tmp);
            }
        }
    }

    return ret;
}