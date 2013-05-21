/* 
* Palindrome Number
* Determine whether an integer is a palindrome. Do this without extra space.
*/
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int len = 0;
    int temp = x;
    while (temp) {
        len++ ;
        temp = temp / 10;
    }
    for (int i=0; i < len/2; i++){
        int head, tail = 0;
        head = x / std::pow(10, len-i-1);
        if (i) {
            head = head % 10;
        }

        tail = x % int(std::pow(10, i+1));

        int j = i;
        while (j) {
            tail = tail / 10;
            j--;
        }

        if (tail == head){
            continue;
        }
        return false;
    }
    return true;
}