#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> unique(std::vector<std::string> & in_vec) {
    std::sort(in_vec.begin(), in_vec.end());
    std::vector<std::string> out_vec = { in_vec[0] };
    
    for (auto it = in_vec.begin(); it != in_vec.end()-1; ++it) {
        if(*it != *(it + 1)) {
            out_vec.push_back(*(it + 1));
        }
    }
    
    return out_vec;
}


// Example function that calls union.
std::vector<std::string> doSomeWork()
{
    std::vector<std::string> list = { "Allan", "Ivor", "Allan", "Jake", "Jake", "Allan", "Tom", "Allan", "Kayte", "Paul", "Claire", "Allan", "Jake" };
    
    return unique(list);
}

int main()
{
    std::vector<std::string> vec_unique = doSomeWork();
    
    for (auto it = vec_unique.begin(); it != vec_unique.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
