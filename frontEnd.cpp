#include "logic.cpp"

int main(){
Number a,b,c,z,sa;
Word word1, word2, result, result1;
a = 67;
b = 9900;

std::string strA = "322";
word1 = "a";
word2 = "a";

result = (word1 == 97.43);

std::cout<<result<<" Here\n";
std::cout<<word1.value<<" word val Here\n";
std::cout<<word1<<"\n";

std::string strB = (word1 == 97.43);
// int strB = (word1 == 97.43);
result1 = (word2 == 9);
result1 = (word2 + '0');

std::cout<<word1.value<<" word1 val Here\n";
// std::cout<<"\n";

    std::cout<<strB<<" val of STRB\n";
    std::cout<<result1<<" val of result1\n";
    std::cout<<result.value<<" val of result";
return 0;
}