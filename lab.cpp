#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {2, 3, 3, 4, 5, 5, 6};

    // sort the vector first
    std::sort(vec.begin(), vec.end());

    // find the first unique element
    auto unique_it = std::unique(vec.begin(), vec.end());

    // erase the unique elements
    vec.erase(unique_it, vec.end());

    // print the vector after deleting the unique elements
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
