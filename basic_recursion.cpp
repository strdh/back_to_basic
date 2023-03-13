#include <iostream>

void countdown(int n) {
    if (n == 0) {
        std::cout<<"end";
    } else {
        std::cout<<n<<" ";
        countdown(n-1);
    }
}

int factorial(int n) {
    if (n == 0) {
        std::cout<<"1\n";
        return 1;
    } 
    int result = n * factorial(n-1);
    std::cout<<result<<"\n";
    return result;
    // return n * factorial(n-1);
}

int main() {
    countdown(10);
    std::cout<<"\n";
    factorial(5);

    return 0;
}