#include <string>
#include <vector>
#include <set>
#ifndef WORDSET
#include "wordset.h"
#define WORDSET
#endif

#define MAX_ALPHABET_SIZE 26

enum COLOR { COLOR_NULL, COLOR_RED, COLOR_YELLOW, COLOR_GREEN };

class Task {
    private:
    std::string answerWord;
    std::string guessWord;
    std::vector <COLOR> guessState;
    int chance;
    int wordLen;
    int MAX_CHANCE;
    int guessAlphabetCount[MAX_ALPHABET_SIZE];
    int answerAlphabetCount[MAX_ALPHABET_SIZE];
    COLOR alphabetState[MAX_ALPHABET_SIZE];
    WordSet wordset;

    public:
    void solve();
    void input();
    void guess();
    void compare(std::string str);
    void printGuessState();
    void printAlphabetState();

    Task(int chn);
    ~Task();
};

void print(char str, COLOR color){
    switch (color) {
        case COLOR_NULL: std::cout << "\033[37;1m" << str << "\033[0m"; break;
        case COLOR_RED: std::cout << "\033[31;1m" << str << "\033[0m"; break;
        case COLOR_YELLOW: std::cout << "\033[33;1m" << str << "\033[0m"; break;
        case COLOR_GREEN: std::cout << "\033[32;1m" << str << "\033[0m"; break;
        default: break;
    }
}