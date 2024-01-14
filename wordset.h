#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// 此类读入并存储了候选词和可用词集合
// 调用此类的两个成员函数可以判断一个单词是否属于候选词/可用词集合
class WordSet {
public:

    // 在构造时，从文件读入候选集和可用集。
    // 你需要在代码中实例化一个 WordSet 类型变量。
    WordSet();
    ~WordSet();
    // 判断输入参数 word 是否属于候选集合
    bool in_final_set(std::string word);
    
    // 判断输入参数 word 是否属于可用集合
    bool in_acceptable_set(std::string word);
    std::string randomWord();
private:
    std::set<std::string> final_set;
    std::set<std::string> acceptable_set;
};
