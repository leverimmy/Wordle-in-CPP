#ifndef TASK
#include "task.h"
#define TASK
#endif


void Task::solve() {
    this->input();
    while (true) {
        guess();
        if (guessWord.length() != wordLen || !wordset.in_acceptable_set(guessWord)) {
            std::cout << "INVALID" << std::endl;
            continue;
        }
        compare(guessWord);
            printGuessState();
            std::cout << ' ';
            printAlphabetState();
            std::cout << std::endl;
        if (guessWord != answerWord) {
            chance--;
            if (chance == 0) {
                std::transform(answerWord.begin(), answerWord.end(), answerWord.begin(), ::toupper);
                std::cout << "FAILED The answer is" + answerWord << "." << std::endl;
                break;
            }
        }
        else {
            std::cout << "CORRECT You guessed " << MAX_CHANCE - chance + 1 << " times in total." << std::endl;
            break;
        }
    }
}

void Task::compare(std::string str) { // compare str with answerWord
    for (int i = 0; i < wordLen; i++) {
        if (str[i] == answerWord[i]) {
            guessState[i] = COLOR_GREEN;
            alphabetState[ answerWord[i] - 'a' ] = COLOR_GREEN;
        }
        else {
            if (answerWord.find(str[i]) != answerWord.npos && guessAlphabetCount[ str[i] - 'a' ] < answerAlphabetCount[ str[i] - 'a' ]) {
                guessState[i] = COLOR_YELLOW;
            }
            else {
                guessState[i] = COLOR_RED;
            }
            if (alphabetState[ str[i] - 'a' ] == COLOR_NULL || alphabetState[ str[i] - 'a' ] == COLOR_RED) {
                if(answerWord.find(str[i]) != answerWord.npos) {
                    alphabetState[ str[i] - 'a' ] = COLOR_YELLOW;
                }
                else {
                    alphabetState[ str[i] - 'a' ] = COLOR_RED;
                }
            }
        }
        guessAlphabetCount[ str[i] - 'a' ]++;
    }
}

void Task::input() {
    // std::cin >> answerWord;
    // std::getline(std::cin, this->answerWord, '\n');
    answerWord = wordset.randomWord();
    wordLen = answerWord.length();
    for (int i = 0; i < wordLen; i++)
        answerAlphabetCount[ answerWord[i] - 'a' ]++;
    guessState.resize(wordLen);
}

void Task::guess() {
    // std::cin >> this->guessWord;
    std::getline(std::cin, this->guessWord, '\n');
    // std::cout << '[' << this->guessWord << ']' << std::endl;
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++)
        guessAlphabetCount[i] = 0;
}

void Task::printGuessState() {
    for (int i = 0; i < wordLen; i++) {
        print(guessWord[i], guessState[i]);
        /*switch (guessState[i]) {
            case COLOR_NULL: std::cout << 'X'; break;
            case COLOR_RED: std::cout << 'R'; break;
            case COLOR_YELLOW: std::cout << 'Y'; break;
            case COLOR_GREEN: std::cout << 'G'; break;
            default: break;
        }*/
    }
}

void Task::printAlphabetState() {
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        print('a' + i, alphabetState[i]);
        /*switch (alphabetState[i]) {
            case COLOR_NULL: std::cout << 'X'; break;
            case COLOR_RED: std::cout << 'R'; break;
            case COLOR_YELLOW: std::cout << 'Y'; break;
            case COLOR_GREEN: std::cout << 'G'; break;
            default: break;
        }*/
    }
}

Task::Task(int chn) : chance(chn), MAX_CHANCE(chn) {
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        alphabetState[i] = COLOR_NULL;
        answerAlphabetCount[i] = 0;
    }
    guessState.reserve(100);
}

Task::~Task() { }
