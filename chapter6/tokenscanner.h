#ifndef _tokenscanner_h
#define _tokenscanner_h

#include <string>

class TokenScanner{

public:
    // 构造函数
    TokenScanner();
    TokenScanner(std::string str);

    // 将 str 设置为需要扫描的字符串，之前的丢弃
    void setInput(std::string str);
    // 检查是否还有更多token
    bool hasMoreTokens();
    // 返回下一个 token,若不存在返回空字符串
    std::string nextToken();
    void ignoreWhiteSpace();

private:
    std::string buffer; // 输出字符串
    int cp; // 当前所在位置
    bool ignoreWhiteSpaceFlag = false;
    void skipWhiteSpace();
};

#endif