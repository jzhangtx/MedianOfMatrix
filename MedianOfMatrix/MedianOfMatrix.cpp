// MedianOfMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& v, const std::vector<int>& vv)
{
    std::vector<int> result;
    result.reserve(v.size() + vv.size());

    auto i = v.cbegin();
    auto j = vv.cbegin();
    for (; i != v.cend() && j != vv.cend();)
    {
        if (*i < *j)
            result.push_back(*i++);
        else
            result.push_back(*j++);
    }

    for (; i != v.cend(); ++i)
        result.push_back(*i);
    for (; j != vv.cend(); ++j)
        result.push_back(*j);

    return result;
}

std::vector<int> Merge(const std::vector<std::vector<int>>& matrix)
{
    std::vector<int> v(*matrix.cbegin());
    for (auto i = matrix.cbegin()+1; i != matrix.cend(); ++i)
    {
        std::vector<int> vec = Merge(v, *i);
        v.clear();
        v.assign(vec.begin(), vec.end());
    }

    return v;
}

int CalculateMedianofMatrix(std::vector<std::vector<int>>& matrix)
{
    std::vector<int> vec = Merge(matrix);
    return vec[(vec.size()-1) / 2];
}

int main()
{
    std::vector<std::vector<int>> vv{ {1, 6, 7, 7, 8},
        {2, 2, 3, 3, 4},
        {1, 2, 2, 2, 2} };

    std::cout << "The median of the matrix is: " << CalculateMedianofMatrix(vv) << std::endl;
}
