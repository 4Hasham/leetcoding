#include<iostream>

class Solution {
public:
    int pow(int n, int p) {
        int a = 1;
        for(int i = 0; i < p; ++i)
            a *= n;
        return a;
    }

    bool checkValidity(char l, char c) {
        if(l == ' ')
            return true;
        if((l == 'a' && c != 'e') ||
            (l == 'e' && (c != 'a' && c != 'i')) ||
            (l == 'i' && c == 'i') ||
            (l == 'o' && (c != 'i' && c != 'u')) ||
            (l == 'u' && c != 'a')) {
                return false;
        }
        return true;
    }
    
    int generatePerm(std::string s, char l, int n) {
        if(s.length() >= n)
            return 0;
        char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
        char c;
        int count = 0;
        for(int i = 0; i < 5; ++i) {
            c = vowel[i];
            if(checkValidity(l, c)) {
                if(s.length() + 1 <= n) {
                    s += c;
                    if(s.length() != n) {
                        count += generatePerm(s, c, n);
                        s.pop_back();
                    }
                    else
                        ++count;
                }
                else {
                    s[s.length() - 1] = c;
                    ++count;
                }
            }
        }
        return count;
    }
    
    int countVowelPermutation(int n) {
        return generatePerm("", ' ', n) % (pow(10, 9) + 7);
    }
};