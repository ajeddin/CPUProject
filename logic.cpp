#include <iostream>
#include <sstream>
#include <map>
// #include <boolean>
#include <vector>

class Variable;
class Number;
class Word;
namespace memory {
    
    void addValueToMemory(Variable* aVar);
    float getValue(Number* aNum);
std::string getValue(Word* aWord);
 extern std::map<std::string, Variable*> allVariables; //gosh i hate this

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

class Variable{
    
    public:
    
    // int parent;
    // std::string valueString;
    Variable(){
     memory::addValueToMemory(this);

    }
    // virtual Variable operator+();
    virtual std::string getValueStr()=0;
   virtual float getValue()=0;
 
 
};

class Number: public Variable{
 CPUClass<float> pc;
    public:
        Number(){};
    std::string getValueStr(){return "2";};
    int operator==(Variable& aVar){
    // if (this->value == aVar->getValue()){
    std::ostringstream ocs;
    ocs << this;

    // }
    return (this->value== aVar.getValue());
    // return 1;
}
float value;
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
class Word: public Variable{
    CPUClass<std::string> pc2;
    public: 
    float getValue(){return 9.4;};
    std::string value;
    std::string getValueStr()  {
    
    return value;}
    int operator==(Variable& aVar){
    // if (this->value == aVar->getValue()){
    std::ostringstream ocs;
    ocs << this;

    // }
    return (this->value == aVar.getValueStr());
    // return 1;
}

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
     void operator=(int aWord){
    this->value = std::to_string(aWord);

     };
   
     std::string  operator/(Word& aWord){
std::cout<<"\nCannot Preform This Action on Word Variable\n";
    return "Error";
     };

      std::string operator*(Word& aWord){
std::cout<<"\nCannot Preform This Action on Word Variable\n";
    return "Error";
     };
    

};




namespace memory{
    
    std::map<std::string,Variable*> allVariables;
void addValueToMemory(Variable* aVar){
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
   return allVariables[ocss.str()]->getValueStr();
   };
   }