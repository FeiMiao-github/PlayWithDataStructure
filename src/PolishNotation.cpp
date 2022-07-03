/**
 * Four Arithmetic Operations 
 */
#include <string_view>
#include <string>
#include <iostream>
#include <stack>
#include <cassert>
#include <unordered_map>

using namespace std;

bool IsMulOrDiv(const char c)
{
    return c == '*' || c == '/';
}

bool IsPlusOrMinus(const char c)
{
    return c == '-' || c == '+';
}

bool IsOp(const char c)
{
    return IsMulOrDiv(c) || IsPlusOrMinus(c);
}

bool IsNum(const char c)
{
    return c >= '0' && c <= '9';
}

bool IsLBracket(const char c)
{
    return c == '(';
}

bool IsRBracket(const char c)
{
    return c == ')';
}

std::string TransToPolishNotation(const std::string_view sv)
{
    stack<char> notion;
    string ret;
    for (auto p = sv.begin(); p != sv.end(); p++)
    {
        if (IsNum(*p))
        {
            ret += *p;
        }
        else if (IsMulOrDiv(*p))
        {
            while (!notion.empty() && IsMulOrDiv(notion.top()))
            {
                ret += notion.top();
                notion.pop();
            }
            notion.push(*p);
        }
        else if (IsPlusOrMinus(*p))
        {
            while (!notion.empty() && IsOp(notion.top()))
            {
                ret += notion.top();
                notion.pop();
            }
            notion.push(*p);
        }
        else if (IsLBracket(*p))
        {
            notion.push(*p);
        }
        else if (IsRBracket(*p))
        {
            while (!notion.empty() && !IsLBracket(notion.top()))
            {
                ret += notion.top();
                notion.pop();
            }
            notion.pop();
        }
    }

    while (!notion.empty())
    {
        ret += notion.top();
        notion.pop();
    }
    return ret;
}

struct PolishNotationEle
{
    enum class T_t
    {
        i,
        op
    };

    union V_t
    {
        int i;
        char c;
    };

    T_t t;
    V_t v;
};


int CalcFromNotion(const string& notion)
{
    stack<int> st;
    int ret = 0;
    for (auto p = notion.begin(); p != notion.end(); p++)
    {
        if (IsNum(*p))
        {
            st.push(*p - '0');
        }
        else // is op
        {
            int a2 = st.top(); st.pop();
            int a1 = st.top(); st.pop();
            std::cout << a1 << *p << a2 << '\n';
            switch (*p)
            {
                case '+':
                    a1 = a1 + a2;
                    break;
                case '-':
                    a1 = a1 - a2;
                    break;
                case '*':
                    a1 = a1 * a2;
                    break;
                case '/':
                    a1 = a1 / a2;
                    break;
            }
            st.push(a1);
            ret = a1;
        }
    }
    return ret;
}

int main()
{
    constexpr std::string_view sv = "8 + (4 - 2) * 3 - 1 + 4";
    auto pnotion = TransToPolishNotation(sv);
    std::cout << "pnotion: " << pnotion << '\n';
    
    auto ret = CalcFromNotion(pnotion);
    cout << "ret: " << ret << '\n';
    return 0;
}