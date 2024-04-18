#include <iostream>
#include <sstream>
#include <map>
#include <vector>
class Variable;
class Number;
namespace memory {
    void addValueToMemory(Variable* aVar);
    float getValue(Number* aNum);
    
    // extern std::map<std::string, Variable*> allVariables;
}
template <typename T> class CPUClass{
std::vector<T> allVar;
    public:
    void load(T aVar){
        allVar.push_back(aVar);
    }
    T add(){
        std::cout<<allVar.at(0);
        return allVar.at(0);
    //    return (allVar.at(0).value+ allVar.at(1).value);
    }


};
class Variable{
    
    public:
    
    int parent;
    std::string valueString;
    Variable(){
     memory::addValueToMemory(this);

    }
    // virtual Variable operator+();
    // virtual std::string getValue(){};
   virtual float getValue()=0;
 
};
class Number: public Variable{
    public:
        Number(){};

//  CPUClass<float> pc;
float value;
float getValue()  {return value;}
float operator+(Number& aNum){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aNum;
        std::cout<<"INSIDE +\n\n\n"<<ocs2.str();
        // pc.load(memory::getValue(this));
        // pc.load(memory::getValue(&aNum));

        return 4;


     };
    void operator=(float aNum){
    this->value = aNum;

     };
};
class Word: public Variable{
    public: 
    std::string value;
    std::string getValueStr()  {
   
    return value;}

};




namespace memory{
    
    std::map<std::string,Variable*> allVariables;
void addValueToMemory(Variable* aVar){
        std::ostringstream ocs;
ocs << aVar;  
// ocs.str();
    allVariables[ocs.str()] = aVar;


}

float getValue(Number* aNum){
    std::ostringstream ocs;
ocs << &aNum;  
   return allVariables[ocs.str()]->getValue();
   }
   }