
#include <iostream>
#include <stack>
#include <cmath>

#include "Headers/Tree.hpp"
Tree::Tree(Point *_root, int _depth, int _scale)
{
    scale = _scale;
}

Tree::Tree(Point *_root, int _depth)
{
    scale = 100;
    render(5, 0.3926991, 0.1, 20);
}
void Tree::render(int n, double dA, double dL, double L)
{
    std::stack<std::pair<Point *, std::pair<double, double>>> St;
    std::unordered_map<char, std::string> m = {{'F', "FF-[-F+F+F]+[+F - F - F]"}};
    std::string word = nthWord("F", m, n);

    Point *p = new Point(320, 0);
    double theta = std::acos(0.0);

    for (char c : word)
    {
        std::cout << c << std::endl;
        switch (c)
        {
        case 'F':
            new Line(p, theta, L);
            p->print();
            std::cout << p << ' ' << theta << ' ' << L << std::endl;
            p = p->translate(L * std::cos(theta), L * std::sin(theta));
            p->print();
            break;
        case '+':
            theta += dA;
            break;
        case '-':
            theta -= dA;
            break;
        case '[':
            St.push({p->copy(), {theta, L}});
            p->print();
            std::cout << theta << ' ' << L << std::endl;
            L -= dL;
            break;
        case ']':
            auto prev = St.top();
            St.pop();
            p = prev.first;
            theta = prev.second.first;
            L = prev.second.second;
            p->print();
            std::cout << theta << ' ' << L << std::endl;
            break;
        }
    }
}
std::string Tree::nthWord(std::string s, std::unordered_map<char, std::string> m, int n)
{
    if (n == 0)
        return s;

    for (int i = 1; i <= n; i++)
    {
        s = nextWord(s, m);
    }

    return s;
}

std::string Tree::nextWord(std::string s, std::unordered_map<char, std::string> &m)
{
    std::string res = "";
    for (char c : s)
    {
        if (m.count(c))
        {
            res += m[c];
        }
        else
        {
            res += c;
        }
    }

    return res;
}