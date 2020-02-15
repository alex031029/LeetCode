# Range-based for Loop

It works like `for(a in items):` in Python,

An example

    #include <iostream>
    #include <vector>

    int main() {
        std::vector<int> v = {0, 1, 2, 3, 4, 5};

        for (const int& i : v) // access by const reference
            std::cout << i << ' ';
        std::cout << '\n';

        for (auto i : v) // access by value, the type of i is int
            std::cout << i << ' ';
        std::cout << '\n';

        for (auto&& i : v) // access by forwarding reference, the type of i is int&
            std::cout << i << ' ';
        std::cout << '\n';

        const auto& cv = v;

        for (auto&& i : cv) // access by f-d reference, the type of i is const int&
            std::cout << i << ' ';
        std::cout << '\n';

        for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
            std::cout << n << ' ';
        std::cout << '\n';

        int a[] = {0, 1, 2, 3, 4, 5};
        for (int n : a) // the initializer may be an array
            std::cout << n << ' ';
        std::cout << '\n';

        for ([[maybe_unused]] int n : a)  
            std::cout << 1 << ' '; // the loop variable need not be used
        std::cout << '\n';

    }
    
The output

    0 1 2 3 4 5
    0 1 2 3 4 5
    0 1 2 3 4 5
    0 1 2 3 4 5
    0 1 2 3 4 5
    1 1 1 1 1 1
