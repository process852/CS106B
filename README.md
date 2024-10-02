# CS106B 学习笔记

## chapter3

该章节主要是描述字符串处理内容。

## chapetr4

探索 C++ 中流(stream)存在那些特征，以及如何利用 stream 去处理文件数据。

`<<` 被称为插入运算符(insertion operation)，左侧为输出流，右侧为需要插入的数据。`<<` 通过重载操作符使得其可以输出不同类型的数据值。C++ 中利用一系列称为操纵器（manipulator）的东西实现格式化输出。有些操纵器是短暂的，仅仅影响下一个输出的字段，而有些操纵器则是持久的，直到显示调用改变其属性。

| manipulator | message |
| :---: | :---: |
| endl | 将换行结束符插入输出流
| setw(n) | 设置下一个字段输出为 n 个字符，若不足默认填充空格，该操作是短暂的
| setprecision(digits) | 设置数值的精度，该操作是持久的
| setfill(ch) | 设置流的填充为字符 ch，该操作是持久的
| left | 指定字段左对齐，持久操作
| right | 指定字段右对齐，持久操作
| intermal | 指定字段居中对齐，持久操作
| fixed | 指定浮点数具体显示数值，而不是科学计数法，持久操作
| scientific | 以科学计数法显示，持久操作
| showpoint/noshowpoint | 显示/不显示小数点，持久操作

#### Data file

持久存储数据在存储媒介中的数据集合称为**文件**。C++ 中头文件 `fstream` 中包含两个流处理类 `ifstream` 和 `ofstream` 用于处理文件的读取和写入。

读写文件的基本步骤：

```bash
1. 声明一个流变量引用该文件
    ifstream infile;
    ofstream outfile;
2. 打开文件
    infile.open("file.txt");
    由于流库的引入早于string 类，所以需要一个 C 风格的字符串表示
    infile.open(filename.c_str());
3. 转换数据
4. 关闭文件
    infile.close();
```

| 方法名 | 功能描述 |
| :---: | :---: |
| get(var) | 将文件流中的下一个字符以引用的方式存储到 var 变量中，并返回 stream
| get() | 返回文件流中的下一个字符
| clear() | 用于清除文件读写的错误标志
| fail() | 若文件读取发生错误，返回 true，否则返回 false
| close() | 关闭文件
| unget() | 撤回最近一个读取的字符，将其重新放回输入流中
| eof() | 若到达文件末尾则返回 true, 否则返回false
| operator>>() | 提取带格式的数据，跳过前导空格
| getline(infile, str) | 该函数是自由函数，传入两个引用参数，将读取的一行存储在 str 字符串中
| open(filename) | 打开文件


#### string streams

头文件 sstream 提供了一些类允许用户关联一个字符串和流，使得可以类似 fstream 中的方式处理字符串。主要是两个类 istringstream 和 ostringstream。

| 成员函数 | 功能说明
| :---: | :---: |
| str() | 获取流的字符串

#### 输出输出流的类层次结构

![](./images/ios.png)

