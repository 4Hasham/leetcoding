#include<iostream>

class Solution {
public:
    int recurse(std::string s, char l) {
        int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;
        int answer = 0;
        if(s.length() == 0)
            return answer;
        char c = s[s.length() - 1];
        std::string ns = s.substr(0, s.length() - 1);
        if(c == 'I' && (l == 'V' || l == 'X')) {
            answer -= 1;
        }
        else if(c == 'X' && (l == 'L' || l == 'C')) {
            answer -= 10;
        }
        else if(c == 'C' && (l == 'D' || l == 'M')) {
            answer -= 100;
        }
        else {
            switch(c) {
                case 'I':
                    answer += 1;
                    break;
                case 'V':
                    answer += 5;
                    break;
                case 'X':
                    answer += 10;
                    break;
                case 'L':
                    answer += 50;
                    break;
                case 'C':
                    answer += 100;
                    break;
                case 'D':
                    answer += 500;
                    break;
                case 'M':
                    answer += 1000;
                    break;
                default:
                    std::cout << "That's an error.";
                    break;
            }
        }
        return answer + recurse(ns, c);
    }
    
    int romanToInt(std::string s) {
        return recurse(s, ' ');
    }
};