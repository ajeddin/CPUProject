#include "logic.cpp"


int main(){
Number a,b,c;
a = 90.0;
// b = 78;
   std::ostringstream ocs, ocs2, ocs3;
    ocs << &a; 
    ocs2 << &b; 
    ocs3 << &c; 
// std::cout<<"\n"<<a.value<<"\n";
    std::cout<<ocs2.str()<<std::endl;
c = a+b;

    // std::cout<<memory::allVariables[ocs.str()]->getValue()<<std::endl;
    std::cout<<"\n";
    // std::cout<<memory::allVariables[ocs.str()]->getValue()<<std::endl;
    std::cout<<memory::allVariables[ocs3.str()]->getValue()<<std::endl;


}