// Ex2_02A.cpp
// Sorting strings in a vector container
#include <iostream>                         // For standard streams
#include <string>                           // For string types
#include <algorithm>                        // For swap() and copy() functions
#include <vector>                           // For vector (and iterators)
#include <iterator>

using std::string;
using std::vector;

// Our very own algorithm to sort a range specified by iterators
template<typename RandomIter>
void bubble_sort(RandomIter start, RandomIter last)
{
    std::cout << "Starting sort." << std::endl;
    bool out_of_order{ false };                // true when values are not in order
    while (true)
    {
        for (auto first = start + 1; first != last; ++first)
        {
            if (*(first - 1) > *first)
            { // Out of order so swap them
                std::swap(*first, *(first - 1));
                out_of_order = true;
            }
        }
        if (!out_of_order)                      // If they are in order (no swaps necessary)...
            break;                                // ...we are done...
        out_of_order = false;                   // ...otherwise, go round again.
    }
}
int insert(){
    //this function will explain how to insert element into the Vector
    vector<string> words;
    words.reserve(10);
    words.push_back("Algo");

    words.emplace_back("absremious");//use emplace_back() instead of push_back()
    // because the front is more efficient than the rara

    string str {"Alkabela"};

    words.emplace_back(str,2,3);//生成一个string对象,然后把它添加到words序列中,
    // 它会生成一个从索引2开始,包含str中三个字符的字串

    auto iter = words.insert(++std::begin(words),"two");//在insert函数中,第一个参数与emplace_back函数一样是一个插入点的迭代器,
            // 后面加上要插入的元素,但是insert函数主要用于一个序列的插入,见下例
    string more[] {"fir","six","siven"};

    iter = words.insert(--std::end(words),std::begin(more),std::end(more));

    iter = words.insert(--std::end(words),2,"nine");//第二个参数是第三个参数所制定的对象的插入次数
}


int main()
{
    vector<string> words;                     // Stores words to be sorted
    words.reserve(10);                        // Allocate some space for elements
    std::cout << "Enter words separated by spaces. Enter Ctrl+Z on a separate line to end:" << std::endl;
    std::copy(std::istream_iterator < string > {std::cin}, std::istream_iterator < string > {},
              std::back_inserter(words));//在这个copy函数中,第一,二个参数是输入迭代器,
    //可以接受任何其他类别的迭代器,第三个是读入值的存放位置

    bubble_sort(std::begin(words), std::end(words));  // Sort the words array

    // Output the sorted vector
    std::cout << "your words in ascending sequence:" << std::endl;
    std::copy(std::begin(words), std::end(words), std::ostream_iterator < string > {std::cout, " "});
    std::cout << std::endl;

    // Create a new vector by moving elements from words vector
    vector<string> words_copy{ std::make_move_iterator(std::begin(words)),
                               std::make_move_iterator(std::end(words)) };
    std::cout << "\nAfter moving elements from words, words_copy contains:" << std::endl;
    std::copy(std::begin(words_copy), std::end(words_copy), std::ostream_iterator < string > {std::cout, " "});
    //在这个语句中,第三个参数是一个输出流迭代器,std::cout表示使用cout输出,后一个表示用空格进行分割
    std::cout << std::endl;

    // See what's happened to elements in words vector...
    std::cout << "\nwords vector has " << words.size() << " elements\n";
    if (words.front().empty())
        std::cout << "First element is empty string object." << std::endl;

    std::cout << "First element is \"" << words.front() << "\"" << std::endl;
    system("PAUSE");
}
