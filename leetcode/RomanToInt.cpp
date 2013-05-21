/*
 * Roman to Integer
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    if (s.empty())
        return 0;

    map<char, int> rt;
    rt['I']=1;
    rt['V']=5;
    rt['X']=10;
    rt['L']=50;
    rt['C']=100;
    rt['D']=500;
    rt['M']=1000;

    auto iter = s.begin();
    int ret = rt[*iter];
    int pre = rt[*iter];
    iter++;
    for (; iter != s.end(); ++iter) {
        if(rt[*iter] <= pre)
            ret += rt[*iter];
        else
            ret = ret - 2 * pre + rt[*iter];
        pre = rt[*iter];       
    }
    return ret;
}