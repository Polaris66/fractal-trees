#include <string>
#include <unordered_map>

#include "Point.hpp"
#include "Line.hpp"

class Tree
{
public:
    int scale;
    Tree(Point *_root, int _depth);
    Tree(Point *_root, int _depth, int _scale);
    void render(Point *root, int _depth);
    std::string nthWord(std::string s, std::unordered_map<char, std::string> m, int n);
    std::string nextWord(std::string s, std::unordered_map<char, std::string> &m);
};