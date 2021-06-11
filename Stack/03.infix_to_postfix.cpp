#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string exp)
{
    string result = "";
    stack<char> st;

    for (int i = 0; i < exp.length(); i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
            result.push_back(exp[i]);

        else if (exp[i] == '(')
            st.push('(');

        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(exp[i]))
            {
                result.push_back(st.top());
                st.pop();
            }
            st.push(exp[i]);
        }
    }

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp) << endl;
    return 0;
}