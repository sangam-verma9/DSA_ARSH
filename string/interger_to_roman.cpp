#include <bits/stdc++.h>
using namespace std;
//******** my first approach (good but not best)
class Solution
{
public:
    string intToRoman(int num)
    {
        string s = "";
        int a1 = num / 1000;
        if (a1 == 1)
            s += "M";
        else if (a1 == 2)
            s += "MM";
        else if (a1 == 3)
            s += "MMM";
        num = num % 1000;

        int a2 = num / 100;
        if (a2 == 1)
            s += "C";
        else if (a2 == 2)
            s += "CC";
        else if (a2 == 3)
            s += "CCC";
        else if (a2 == 4)
            s += "CD";
        else if (a2 == 5)
            s += "D";
        else if (a2 == 6)
            s += "DC";
        else if (a2 == 7)
            s += "DCC";
        else if (a2 == 8)
            s += "DCCC";
        else if (a2 == 9)
            s += "CM";

        num = num % 100;
        int a3 = num / 10;
        if (a3 == 1)
            s += "X";
        else if (a3 == 2)
            s += "XX";
        else if (a3 == 3)
            s += "XXX";
        else if (a3 == 4)
            s += "XL";
        else if (a3 == 5)
            s += "L";
        else if (a3 == 6)
            s += "LX";
        else if (a3 == 7)
            s += "LXX";
        else if (a3 == 8)
            s += "LXXX";
        else if (a3 == 9)
            s += "XC";

        num = num % 10;
        int a4 = num % 10;
        if (a4 == 1)
            s += "I";
        else if (a4 == 2)
            s += "II";
        else if (a4 == 3)
            s += "III";
        else if (a4 == 4)
            s += "IV";
        else if (a4 == 5)
            s += "V";
        else if (a4 == 6)
            s += "VI";
        else if (a4 == 7)
            s += "VII";
        else if (a4 == 8)
            s += "VIII";
        else if (a4 == 9)
            s += "IX";

        return s;
    }
};
//************ second approach better same idea
class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};
//********
int main()
{

    return 0;
}