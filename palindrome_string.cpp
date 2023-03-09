#include <iostream>
#include <string>

bool is_palindrome(std::string str) {
    for (int i = 0, j = str.length() - 1; i<str.length()/2; i++, j--) {
        if (std::isspace(str[i])) {
            i++;
        }

        if (std::isspace(str[j])) {
            j--;
        }

        if (std::tolower(str[i]) != std::tolower(str[j])) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string str1 = "Racecar", str2 = "A man a plan a canal Panama", str3 = "kasurrusak";
    std::cout<<str1<<" -> "<<is_palindrome(str1)<<"\n";
    std::cout<<str2<<" -> "<<is_palindrome(str2)<<"\n";
    std::cout<<str3<<" -> "<<is_palindrome(str3)<<"\n";

    return 0;
}