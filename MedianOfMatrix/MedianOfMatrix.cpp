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
    while (true)
    {
        int count = 0;
        std::cout << "Number of arries in the matrix: ";
        std::cin >> count;
        if (count == 0)
            break;
        int elementCount = 0;
        std::cout << "Number of elements in the sorted arries:";
        std::cin >> elementCount;

        std::vector<std::vector<int>> vecOfVec;
        vecOfVec.reserve(count);

        for (int i = 0; i < count; ++i)
        {
            std::vector<int> vec(elementCount);
            std::cout << "The numbers of the sorted array: ";
            for (int i = 0; i < elementCount; ++i)
                std::cin >> vec[i];

            vecOfVec.push_back(std::move(vec));
        }

        std::cout << "The median element of the matrix is: " << CalculateMedianofMatrix(vecOfVec) << std::endl << std::endl;
    }
}
