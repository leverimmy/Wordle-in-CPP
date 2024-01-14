#include <bits/stdc++.h>

#include "wordset.cpp"
#include "task.cpp"

int main () {
    print('W', COLOR_GREEN);
    print('O', COLOR_RED);
    print('R', COLOR_NULL);
    print('D', COLOR_NULL);
    print('L', COLOR_GREEN);
    print('E', COLOR_YELLOW);
    std::cout << std::endl;
    // std::cout << "Wordle!" << std::endl;
    std::cout << "The length of the word is 5." << std::endl;
    std::cout << "You have (MAX_CHANCE) chances to guess the correct word." << std::endl;
    std::cout << "Please input the (MAX_CHANCE) you desire: ";
    int T;
    std::cin >> T; getchar();
    Task task(T);
    task.solve();
    return 0;
}
