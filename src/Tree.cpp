
#include <iostream>
#include <stack>
#include <cmath>
#include <GL/glut.h>

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
    render(6, 0.4, 4, 20);
}

/**
 * @param h The Hue of the color
 * @brief Converts color according to given hue
 */
void changeColor(int h)
{
    double c = 1;
    double k = (int)(h / (double)60) % 2 - 1;
    if (k < 0)
        k = -k;
    double x = 1 - k;

    if (h < 60)
    {
        glColor3f(c, x, 0.0f);
    }
    else if (h < 120)
    {
        glColor3f(x, c, 0.0f);
    }
    else if (h < 180)
    {
        glColor3f(0, c, x);
    }
    else if (h < 240)
    {
        glColor3f(0, x, c);
    }
    else if (h < 300)
    {
        glColor3f(x, 0, c);
    }
    else if (h < 360)
    {
        glColor3f(c, 0, x);
    }
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
    std::unordered_map<char, std::string> m = {{'F', "[-F][-F][-F]F[+F]F[+F][+F]"}};
    std::string word = nthWord("F", m, n);

    Point *p = new Point(320, 0);
    double theta = std::acos(0.0);

    for (char c : word)
    {
        std::cout << c << std::endl;
        switch (c)
        {
        case 'F':
            changeColor(((int)L * 12) % 360);
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