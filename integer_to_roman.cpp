#include<iostream>

class Solution {
public:
    int pow(int n, int p) {
        int a = 1;
        for(int i = 0; i < p; ++i)
            a *= n;
        return a;
    }
    
    std::string convert(int n) {
        std::string s = "";
        if(n > 0) {
            int diff = 0;
            if(n >= 900) {
                if(n == 900)
                    s += "CM"; 
                else {
                    diff = n - 1000;
                    s += "M" + convert(diff);
                }
            }
            else if(n >= 400) {
                if(n == 400)
                    s += "CD";
                else {
                    diff = n - 500;
                    s += "D" + convert(diff);
                }
            }
            else if(n >= 90) {
                if(n == 90)
                    s += "XC";
                else {
                    diff = n - 100;
                    s += "C" + convert(diff);
                }
            }
            else if(n >= 40) {
                if(n == 4) 
                    s += "XL";
                else {
                    diff = n - 50;
                    s += "L" + convert(diff);
                }
            }
            else if(n >= 9) {
                if(n == 9)
                    s += "IX";
                else {
                    diff = n - 10;
                    s += "X" + convert(diff);
                }
            }
            else if(n >= 4) {
                if(n == 4)
                    s += "IV";
                else {
                    diff = n - 5;
                    s += "V" + convert(diff);
                }
            }
            else {
                for(int i = 0; i < n; ++i)
                    s += "I";
            }
        }
        return s;
    }
    
    std::string intToRoman(int num) {
        int cur = 0;
        int digit = 0;
        int n = num;
        int p = 0;
        std::string s = "";
        while(n > 0) {
            digit = n % 10;
            cur = digit * pow(10, p);
            if(cur > 0)
                s = convert(cur) + s;
            n = n / 10;
            ++p;
        }
        return s;
    }
};