/*
* String to Integer (atoi)
* 
* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases. If you want a challenge, 
* please do not see below and ask yourself what are the possible input cases.

* Notes: It is intended for this problem to be specified vaguely (ie, no given 
* input specs). You are responsible to gather all the input requirements up front.

* Requirements for atoi:
* The function first discards as many whitespace characters as necessary until
* the first non-whitespace character is found. Then, starting from this character,
* takes an optional initial plus or minus sign followed by as many numerical digits
* as possible, and interprets them as a numerical value.

* The string can contain additional characters after those that form the integral
* number, which are ignored and have no effect on the behavior of this function.

* If the first sequence of non-whitespace characters in str is not a valid 
* integral number, or if no such sequence exists because either str is empty
* or it contains only whitespace characters, no conversion is performed.

* If no valid conversion could be performed, a zero value is returned. If the
* correct value is out of the range of representable values, INT_MAX (2147483647)
* or INT_MIN (-2147483648) is returned.
*/


#include <iostream>
using namespace std;
int StringToInterger(char *str) {
    int len = strlen(str);
    long long ret = 0;
    bool num_existed = false;
    int sign = 1;
    bool exist_signed = false;
    for (int i=0; i<len; i++){
        if (str[i] == ' ') {
            if (num_existed) {
                break;
            }
            continue;
        }
        if (str[i] == '+' && !num_existed) {
            if (exist_signed)
                return 0;
            int temp = i+1;
            exist_signed = true;
            if ((temp <= len) && (str[temp] != ' '))
                continue;
            else
                return 0;
        }
        if (str[i] == '-' && !num_existed) {
            if (exist_signed)
                return 0;
            sign = -1;
            int temp = i+1;
            exist_signed = true;
            if ((temp <= len) && (str[temp] != ' '))
                continue;
            else
                return 0;
        }
        if (str[i] > '9' || str[i] < '0') {
            if (num_existed)
                break;
            return 0;
        }
        int tmp = str[i] - '0';
        ret = ret * 10 + tmp;
        num_existed = true;
    }
    ret = sign * ret;
    if (ret > INT_MAX)
        return INT_MAX;
    if (ret < INT_MIN)
        return INT_MIN;
    return ret;
}