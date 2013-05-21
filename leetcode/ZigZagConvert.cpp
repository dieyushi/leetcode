/* ZigZag Conversion
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
* of rows like this: (you may want to display this pattern in a fixed font for 
* better legibility)
*     P   A   H   N
*     A P L S I I G
*     Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>

using namespace std;

string ZigZagconvert(string s, int nRows) {
    string ret;
    int len = s.length();
    int everyItem = 2 * nRows -2;

    if (everyItem == 0) {
        return s;
    }
    int cout = len/everyItem;
    int left = len%everyItem;

    //first line
    for (int i=0; i <= (cout-1); i++) {
        ret.append(1,s[(2*nRows-2)*i]);
    }
    if (left) {
        ret.append(1,s[(2*nRows-2)*(cout)]);
    }

    // next serval lines
    for (int i=1; i <= nRows-2; i++){
        for (int j=0; j<= (cout-1); j++){
            ret.append(1,s[(2*nRows-2) * j + i]);
            ret.append(1,s[(2*nRows-2) * j + i + (2*nRows-2)-2*i]);
        }
        if ((2*nRows-2) * cout+ i <= len-1) {
            ret.append(1,s[(2*nRows-2) * cout + i]);
        }
        if ((2*nRows-2) * cout + i + (2*nRows-2)-2*i <= len-1) {
            ret.append(1,s[(2*nRows-2) * cout + i + (2*nRows-2)-2*i]);
        }
    }

    //add the last line
    for (int i=0; i <= cout-1; i++) {
        ret.append(1,s[(2*nRows-2)*i + nRows -1]);
    }

    if ((2*nRows-2)*cout + nRows -1 <= len-1) {
        ret.append(1,s[(2*nRows-2)*cout + nRows -1]);
    }

    return ret;
}