/* 
 * Integer to Roman
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>

using namespace std;

string IntToRoman(int num) {
    int i = 0;
    string ret;
    int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    while (num > 0) {
        while (num >= a[i]) {
            ret = ret + r[i];
            num = num - a[i];
        }
        i++;
    }
    return ret;
}