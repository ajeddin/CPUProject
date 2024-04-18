#include <iostream>
#include <sstream>
#include <map>
#include <vector>

union Type;
class Variable;
class Number;
class Word;
namespace memory {
    void addValueToMemory(Variable* aVar);
    float getValue(Number* aNum);
std::string getValue(Word* aWord);
}


template <typename T> class CPUClass{
std::vector<T> allVar;
    public:
    void load(T aVar){
        allVar.push_back(aVar);
    }
    T add(){
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b =  allVar.at(1);
       return a+b;
    }
    T subtract(){
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b =  allVar.at(1);
       return a-b;
    }
    T divide(){
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b =  allVar.at(1);
       return a/b;
    }
    T multiply(){
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b =  allVar.at(1);
       return a*b;
    }
    



};

union Type {
    std::string str;
    float flt;
};

template <typename V> 
class Variable{
    private:
    V value;
    public:
    
    // int parent;
    // std::string valueString;
    Variable(){
     memory::addValueToMemory(this);

    }
    // virtual Variable operator+();
    // virtual std::string getValueStr()=0;
    V getValue(){
    return value;
   };
 
};
//Unions;
class Number: public Variable<float>{
 CPUClass<float> pc;
    public:
        Number(){};
    // std::string getValueStr(){return "2";};

float Type
float getValue()  {return value;}
float operator+(Number& aNum){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aNum;
        // std::cout<<"INSIDE +\n\n\n"<<ocs2.str()<<std::endl;
    // memory::getValue(this);
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        float n = pc.add();
        // std::cout<<n;
        return n;


     };
float operator-(Number& aNum){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aNum;
        // std::cout<<"INSIDE +\n\n\n"<<ocs2.str()<<std::endl;
    // memory::getValue(this);
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        float n = pc.subtract();
        // std::cout<<n;
        return n;


     };
float operator/(Number& aNum){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aNum;
        // std::cout<<"INSIDE +\n\n\n"<<ocs2.str()<<std::endl;
    // memory::getValue(this);
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        float n = pc.divide();
        // std::cout<<n;
        return n;


     };
float operator*(Number& aNum){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aNum;
        // std::cout<<"INSIDE +\n\n\n"<<ocs2.str()<<std::endl;
    // memory::getValue(this);
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        float n = pc.multiply();
        // std::cout<<n;
        return n;


     };
    void operator=(float aNum){
    this->value = aNum;

     };
};
class Word: public Variable<std::string>{
    CPUClass<std::string> pc2;
    public: 
    std::string getValue(){return value;};
    std::string value;
    // std::string getValueStr()  {
    
    // return value;}
std::string operator+(Word& aWord){
        std::ostringstream ocs, ocs2;
        // ocs << this;
        ocs2 << &aWord;
        // std::cout<<"INSIDE +\n\n\n"<<ocs2.str()<<std::endl;
    // memory::getValue(this);
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aWord));
        std::string n = pc2.add();
        // std::cout<<n;
        return n;


     };
     void operator=(std::string aWord){
    this->value = aWord;

     };
     void operator=(char aWord){
    this->value = aWord;

     };
    

};




namespace memory{
    
    std::map<std::string,Variable<Type>*> allVariables;
void addValueToMemory(Variable<Type>* aVar){
        std::ostringstream ocs;
ocs << aVar;  
    allVariables[ocs.str()] = aVar;


};
float getValue(Number* aNum){
    std::ostringstream ocss;
ocss << aNum;  
   return allVariables[ocss.str()]->getValue();
   };



std::string getValue(Word* aWord){
    std::ostringstream ocss;
ocss << aWord;  
   return allVariables[ocss.str()]->getValue();
   };
   }