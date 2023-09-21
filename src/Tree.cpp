#include "Headers/Tree.hpp"

#include <iostream>

Tree::Tree(Point *_root, int _depth, int _scale)
{
    scale = _scale;
    render(_root, _depth);
}

Tree::Tree(Point *_root, int _depth)
{
    scale = 100;
    std::unordered_map<char, std::string> m = {{'F', "F[+F]F[-F]F"}};
    nthWord("F", m, 3);
    // render(_root, _depth);
}
void Tree::render(Point *root, int depth)
{
    if (depth == 0)
        return;

    int l = depth * scale;

    Point *p1 = root->copy()->translate(l, 0);
    Point *p2 = root->copy()->translate(l, l);
    Point *p3 = root->copy()->translate(0, l);

    new Line(root, p1);
    new Line(root, p2);
    new Line(root, p3);

    render(p1, depth - 1);
    render(p2, depth - 1);
    render(p3, depth - 1);
};

std::string Tree::nthWord(std::string s, std::unordered_map<char, std::string> m, int n)
{
    if (n == 0)
        return s;

    for (int i = 1; i <= n; i++)
    {
        s = nextWord(s, m);
        std::cout << s << std::endl;
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