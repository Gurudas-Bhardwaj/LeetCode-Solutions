#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isValid(string s) {
    stack<char> stk;

    for(auto ch : s){
        if(ch == '(' || ch == '{' || ch == '[')
            stk.push(ch);
        else{
            if(!stk.empty()) return false;

            char top = stk.top();
            stk.pop();
            
            if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) return false;

        }
    }

    return stk.empty();
}

int main() {
    vector<string> tests = {"()[]{}", "(]", "([{}])", "((()))", "([)]"};
    for (auto &s : tests) {
        cout << s << " -> " << (isValid(s) ? "true" : "false") << endl;
    }
    return 0;
}