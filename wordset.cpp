#ifndef WORDSET
#include "wordset.h"
#define WORDSET
#endif

WordSet::WordSet() {
    srand(time(0));
    std::ifstream FINAL_FILE; 
    FINAL_FILE.open("./FINAL.txt", std::ifstream::in);
    while(!FINAL_FILE.eof()) {
        std::string str;
        FINAL_FILE >> str;
        final_set.insert(str);
    }
    FINAL_FILE.close();
    
    std::ifstream ACCEPTABLE_FILE;
    ACCEPTABLE_FILE.open("./ACC.txt", std::ifstream::in);
    while(!ACCEPTABLE_FILE.eof()) {
        std::string str;
        ACCEPTABLE_FILE >> str;
        acceptable_set.insert(str);
    }
    ACCEPTABLE_FILE.close();
}

WordSet::~WordSet() { }

// 判断输入参数 word 是否属于候选集合
bool WordSet::in_final_set(std::string word) {
    return final_set.find(word) != final_set.end();
}

// 判断输入参数 word 是否属于可用集合
bool WordSet::in_acceptable_set(std::string word) {
    return acceptable_set.find(word) != acceptable_set.end();
}

int random(int l, int r) {
    return 1LL * rand() * rand() % (r - l + 1) + l;
}

std::string WordSet::randomWord() {
    std::set<std::string>::iterator it = final_set.begin();
    for (int cnt = random(1, final_set.size()); cnt; ++it, --cnt);
    return *it;
}