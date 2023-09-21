#include "Headers/Tree.hpp"

#include <iostream>

Tree::Tree(Point *_root, int _depth, int _scale)
{
    scale = _scale;
}

Tree::Tree(Point *_root, int _depth)
{
    scale = 100;
    std::unordered_map<char, std::string> m = {{'F', "F[+F]F[-F]F"}};
    nthWord("F", m, 3);
    // render(_root, _depth);
}
void Tree::render(int n, int dA, int dL, int L){

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