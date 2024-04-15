#include <bits/stdc++.h>
using namespace std;

stack<char> s;
stack<int> res;

int pre(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void evaluate(string postfix) {
    int c;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            res.push(postfix[i] - '0');
        } else {
            int a = res.top();
            res.pop();
            int b = res.top();
            res.pop();
            if (postfix[i] == '^') {
                c = pow(b, a);
            } else if (postfix[i] == '*') {
                c = b * a;
            } else if (postfix[i] == '/') {
                c = b / a;
            } else if (postfix[i] == '+') {
                c = b + a;
            } else if (postfix[i] == '-') {
                c = b - a;
            }
            res.push(c);
        }
    }
    cout << "Result: " << res.top() << endl;
}

int main() {
    string infix, postfix = "";
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && pre(infix[i]) <= pre(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "POSTFIX: " << postfix << endl;
    evaluate(postfix);

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// stack<char>s;
// stack<int>res;
// int evaluate(string postfix)
// {
//     for(int i=0;i<postfix.size();i++)
//     {
//         char ch=postfix[i];
//         if(ch>='0'&&ch<='9')
//         {
//             res.push(ch-'0');
//         }
//         else
//         {
//             int a=res.top();
//             res.pop();
//             int b=res.top();
//             res.pop();
//             int c=0;
//             if(ch=='+')
//             {
//                 c=b+a;
//                   }
//             else if(ch=='-')
//             {
//                 c=b-a;
//             }
//             else if(ch=='*')
//             {
//                 c=b*a;
//             }
//             else if(ch=='/')
//             {
//                 c=b/a;
//             }
//             else if(ch=='^')
//             {
//                 c=pow(b,a);
//             }
//             res.push(c);
//         }
//     }
//     cout<<res.top();
//     res.pop();
//     return 0;
// }
// int priority(char ch)
// {
//     if(ch=='^')
//     {
//         return 3;
//     }
//     else if(ch =='*'||ch=='/')
//     {
//         return 2;
//     }
//     else if(ch=='+'||ch=='-')
//  {
//         return 1;
//     }
//     else
//         return 0;
// }
// int main(){
// string infix,postfix="";
// cin>>infix;
// //getline(cin,infix)   jodi space soho input nite chai taile getline use korbo


// for(int i=0;i<infix.size();i++){
//     char symbol=infix[i];

//     if(symbol>='0'&&symbol<='9'){
//         postfix=postfix+symbol;
//     }
//     else if(symbol>='a'&& symbol<='z')
//     {
//         postfix=postfix+symbol;
//     }
//     else if(symbol=='(')
// {
//         s.push(symbol);
//     }
//     else if(symbol==')')
//     {
//         while(!s.empty()&& s.top()!='(')
//         {
//             postfix=postfix+s.top();
//             s.pop();
//         }
//         s.pop();
//     }
//     else
//     {
//         while(!s.empty()&& priority(s.top())>=priority(symbol))
//         {
//             postfix=postfix+s.top();
//             s.pop();
//         }
//         s.push(symbol);

//     }

//   }
//   while(!s.empty())
//   {
//       postfix=postfix+s.top();
//       s.pop();
//   }
 
//   cout<<postfix<<endl;
//   evaluate(postfix);
//   return 0;

// }
// //(5+6/2*(8+4)-7)


