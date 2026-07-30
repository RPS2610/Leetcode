#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();

        if (len % 2 != 0) return false;

        char stack[len];
        int top = -1;

        for (int i = 0; i < len; i++) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                top++;
                stack[top] = c;
            } else {
                if (top == -1) return false;

                char lastOpen = stack[top];

                if ((c == ')' && lastOpen == '(') ||
                    (c == '}' && lastOpen == '{') ||
                    (c == ']' && lastOpen == '[')) {
                    top--;
                } else {
                    return false;
                }
            }
        }

        return top == -1;
    }
};