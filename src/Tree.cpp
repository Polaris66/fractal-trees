
#include <iostream>
#include <stack>
#include <cmath>

#include "Headers/Tree.hpp"

/**
 * @param -The root of the tree, the depth of the tree , and also the scale.
 *
 * @brief The base function to create a tree object
 *
 */
Tree::Tree(Point *_root, int _depth, int _scale)
{
    scale = _scale;
}

/**
 * @param  - it takes the number of iterations, the angle with which it will turn and also the length of the branches.
 *
 * @brief This function is used to make the tree by calling the line function recursively.
 */
Tree::Tree(Point *_root, int _depth)
{
    scale = 100;
    render(5, 0.3926991, 0.1, 20);
}

/**
 * @param  - it takes the number of iterations, the angle with which it will turn and also the length of the branches.It shows the main logic behind the code wherein it maintains a stack and calls a recursive formula to make a specific kind of tree
 *
 * @brief This function is used to render the tree by calling the line function recursively.
 *
 * @return It renders the tree on the window.
 */
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

/**
 * @param  - The string s and the map to convert F to a given function
 *
 * @brief This function is used to make the nth string that is to be called in the render function.
 *
 * @return It shows the next string.
 */
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
/**
 * @param  - The string s and the map to convert F to a given function and thr strind that is already made.
 *
 * @brief This function is used to make the string
 *
 * @return It shows the next string.
 */
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