#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_vec(const std::vector<std::string> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
}

std::vector<std::string> filter(std::vector<std::string> & in_vec) {
    std::sort(in_vec.begin(), in_vec.end());
    std::vector<std::string> out_vec = { in_vec[0] };
    
    for (auto it = in_vec.begin(); it != in_vec.end()-1; ++it) {
        if(*it != *(it + 1)) {
            out_vec.push_back(*(it + 1));
        }
    }
    
    return out_vec;
} 

int main()
{
    std::vector<std::string> in_vec;
    std::vector<std::string> list_1 = { "Ivor", "Allan", "Jake", "Jake", "Allan", "Tom", "Allan" };
    std::vector<std::string> list_2 = { "Kayte", "Paul", "Claire", "Allan", "Jake" };

    in_vec.reserve(list_1.size() + list_2.size()); 
    in_vec.insert(in_vec.end(), list_1.begin(), list_1.end());
    in_vec.insert(in_vec.end(), list_2.begin(), list_2.end());
    
    std::vector<std::string> out_vec = filter(in_vec);
    print_vec(out_vec);

    return 0;
}
