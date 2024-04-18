#include "logic.cpp"

int main(){
Number a,b,c,z,sa;
Word word1, word2, result;
a = 90.0;
b = 78.90;


word1 = "sa";
word2 = 'a';
result = word1 + word2;
std::cout<<"\n"<<result.value<<"\n";
result = word1 / word2;
std::cout<<"\n"<<result.value<<"\n";



   std::ostringstream ocs, ocs2, ocs3;
    // ocs << &a; 
    ocs2 << &z; 
    ocs3 << &c; 
    // std::cout<<ocs2.str()<<std::endl;
;
c =(a==b);

// as = a/b;
// std::cout<<"\n"<<as.value<<"\n";

    // std::cout<<memory::allVariables[ocs.str()]->getValue()<<std::endl;
    std::cout<<"\n"<<c.getValue()<<"\n";
    // std::cout<<"\n"<<result.getValueStr()<<"\n";
    // std::cout<<memory::allVariables[ocs2.str()]->getValue()<<std::endl;
    // std::cout<<memory::allVariables[ocs3.str()]->getValue()<<std::endl;


}