// lambdas are quick disposable functions
// great for variable assignment
// define a function without defining
// ideal usecase: set a function pointer to a lambda

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional> // for marking a standard function

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = {1,2,3,4,5};
    ForEach(values, [](int val) { std::cout << "Value: " << val << std::endl; });
    int x = 10;
    // [] ---> capture brackets ---> used to capture external variables ---> by ref & or by value =
    auto lambda = [&](int val) { return val + x;}; // capture here passes by reference.
    std::cout << lambda(5);
    return 0;
}
