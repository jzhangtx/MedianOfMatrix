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
        v = std::move(Merge(v, *i));
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
    while (true)
    {
        int rows = 0;
        int cols = 0;
        std::cout << "The size of the matrix(rows, columns): ";
        std::cin >> rows >> cols;
        if (rows == 0 && cols == 0)
            break;

        std::vector<std::vector<int>> vecOfVec;
        vecOfVec.reserve(rows);

        for (int i = 0; i < rows; ++i)
        {
            std::vector<int> vec(cols);
            std::cout << "The " << i << "th row of the matrix: ";
            for (int i = 0; i < cols; ++i)
                std::cin >> vec[i];

            vecOfVec.push_back(std::move(vec));
        }

        std::cout << "The median element of the matrix is: " << CalculateMedianofMatrix(vecOfVec) << std::endl << std::endl;
    }
}
