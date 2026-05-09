class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return 0;
                char c = stk.top();
                stk.pop();

                switch (s[i]) {
                    case ')': {
                        if (c != '(') return 0;
                    } break;
                    case '}': {
                        if (c != '{') return 0;
                    } break;
                    case ']': {
                        if (c != '[') return 0;
                    } break;
                    default: return 0;
                }
            }
        }
        if (!stk.empty()) return 0;
        return 1;
    }
};