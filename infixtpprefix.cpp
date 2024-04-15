#include<bits/stdc++.h>
using namespace std;

stack<char> s;
stack<int> res;

int evaluate(string postfix) {
    for (int i = 0; i < postfix.size(); i++) {
        char ch = postfix[i];
        if (ch >= '0' && ch <= '9') {
            res.push(ch - '0');
        } else {
            int a = res.top();
            res.pop();
            int b = res.top();
            res.pop();
            int c = 0;
            if (ch == '+') {
                c = b + a;
            } else if (ch == '-') {
                c = b - a;
            } else if (ch == '*') {
                c = b * a;
            } else if (ch == '/') {
                c = b / a;
            } else if (ch == '^') {
                c = pow(b, a);
            }
            res.push(c);
        }
    }
    cout << "Evaluation Result: " << res.top() << endl;
    return 0;
}

int priority(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

string infixToPostfix(string infix) {
    string postfix = "";
    for (int i = 0; i < infix.size(); i++) {
        char symbol = infix[i];

        if (symbol >= '0' && symbol <= '9') {
            postfix = postfix + symbol;
        } else if (symbol >= 'a' && symbol <= 'z') {
            postfix = postfix + symbol;
        } else if (symbol == '(') {
            s.push(symbol);
        } else if (symbol == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix = postfix + s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && priority(s.top()) >= priority(symbol)) {
                postfix = postfix + s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }
    while (!s.empty()) {
        postfix = postfix + s.top();
        s.pop();
    }
    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    cout<<infix<<endl;
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix, postfix = "";
    cout << "Enter the infix expression: ";
    cin >> infix;

    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    evaluate(postfix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}
