#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>


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
        // std::cout<<"\nVal of a "<<a<<" \t vall of b "<<b<<std::endl;
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
    bool compare(){
         T a = allVar.at(0);
        T b =  allVar.at(1);
       return a==b;
    }
    void clearVector(){
        allVar.clear();
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
  friend std::ostream& operator<<(std::ostream& out,  Number& aNum);

 CPUClass<float> pc;
    public:
        Number(){};
    std::string getValueStr(){return "2";};
    int operator==(Variable& aVar){
    std::ostringstream ocs;
    ocs << this;
    return (this->value== aVar.getValue());
}
    int operator==(Number& aVar){
    std::ostringstream ocs;
    ocs << &aVar;
 pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aVar));
   return pc.compare();
            // return (this->value== aVar.getValue());

}
void operator=(std::string aWord){
   std::cout<<"\nError\n";
    this->value =0;
}
    int operator==(Word& aVar){
   std::cout<<"\nError\n";
   return 0;
            // return (this->value== aVar.getValue());

}
    int operator==(std::string aVar){
   std::cout<<"\nError\n";
   return 0;
            // return (this->value== aVar.getValue());

}
void operator=(Word& aWord){
    std::cout<<"\nError\n";
    this->value =0;
    

}
    int operator==(float aVar){
        pc.clearVector();
//    std::cout<<"\nError\n";
    std::ostringstream ocs;
    ocs << &aVar;
 pc.load(memory::getValue(this));
        pc.load(aVar);
   return pc.compare();

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
float operator+(float aNum){
          pc.clearVector();

        pc.load(memory::getValue(this));
        pc.load(aNum);
        float n = pc.add();
        // std::cout<<"\n val of aNUM in char "<<n<<"\n";
        
        return n;


     };
float operator-(float aNum){
    pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        float n = pc.subtract();
        // std::cout<<n;
        return n;


     };

float operator/(float aNum){
     pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        float n = pc.divide();
        // std::cout<<n;
        return n;


     };
float operator*(float aNum){
     pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        float n = pc.multiply();
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
float operator+( Word& aWord){
    std::cout<<"\nError\n";
    return 0;
}
float operator-( Word& aWord){
    std::cout<<"\nError\n";
    return 0;
}
float operator*( Word& aWord){
    std::cout<<"\nError\n";
    return 0;
}
float operator/( Word& aWord){
    std::cout<<"\nError\n";
    return 0;
}
float operator+( std::string aword){
    std::cout<<"\nError\n";
    return 0;
}
float operator-( std::string aword){
    std::cout<<"\nError\n";
    return 0;
}
float operator*( std::string aword){
    std::cout<<"\nError\n";
    return 0;
}
float operator/( std::string aword){
    std::cout<<"\nError\n";
    return 0;
}
// float operator+( char aword){
//     std::cout<<"\nError\n";
//     return 0;
// }
    void operator=(float aNum){
    this->value = static_cast<float> (aNum);

     };

};
class Word: public Variable{
             friend std::ostream& operator<<(std::ostream& out,  Word& aNum);

    CPUClass<std::string> pc2;
    public: 
    float getValue(){return 9.4;};
    std::string value;
    std::string getValueStr()  {
    
    return value;}

    std::string operator==(char aVar){
        pc2.clearVector();
        std::ostringstream ocs,ocs1;
        ocs << aVar;
 pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}
    std::string operator==(Number& aVar){
        pc2.clearVector();
        std::ostringstream ocs,ocs1;
        ocs << memory::getValue(&aVar);
 pc2.load(memory::getValue(this));
 pc2.load(ocs.str());
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}
    std::string operator==(int aVar){
        pc2.clearVector();
        std::ostringstream ocs,ocs1;
        ocs << aVar;
 pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}
    std::string operator==(std::string aVar){
        pc2.clearVector();
        std::ostringstream ocs1;

 pc2.load(memory::getValue(this));
        pc2.load(aVar);
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}
    std::string operator==(double aVar){
        pc2.clearVector();
        std::ostringstream ocs,ocs1;
        ocs << aVar;
 pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}
    std::string operator==(Word& aVar){
        std::ostringstream ocs,ocs1;
        ocs << aVar;
 pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aVar));
    ocs1 << std::boolalpha <<pc2.compare();  

   return ocs1.str();


}







template <typename T> std::string operator-(T aWord){
    std::cout<<"\nError\n";
    return "Error";
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

std::string operator+(std::string aWord){
    pc2.clearVector();
        pc2.load(memory::getValue(this));
        pc2.load(aWord);
        std::string n = pc2.add();
        return n;


     };

std::string operator+(Number aWord){
       std::cout<<"\nError\n";
        return "Error";


     };
std::string operator+(char aWord){
        pc2.clearVector();
        pc2.load(memory::getValue(this));
        std::string s(1,aWord);
        pc2.load(s);
        std::string n = pc2.add();
        // std::cout<<"\n"<<n<<" Val of add and in op+\t"<<aWord<<" val of aword\n"; 
        return n;


     };
     
std::string operator+(float aWord){ return "Error"; };
std::string operator+(double aWord){ return "Error"; };
std::string operator+(int aWord){ return "Error"; };
     void operator=(std::string aWord){

    this->value = aWord;

     };
     void operator=(char aWord){
    this->value = aWord;

     };
     void operator=(int aWord){
    this->value = std::to_string(aWord);

     };
     void operator=(double aWord){
        
        std::ostringstream ocs;
        ocs << aWord;
        ocs << std::fixed <<std::setprecision(2);
        
    this->value = ocs.str();
        // this->value = std::to_string(ocs.str());


     };
     void operator=(Number& aWord){
        
        std::ostringstream ocs;
        ocs << aWord.value;
        ocs << std::fixed <<std::setprecision(2);
       this->value = ocs.str();
        // this->value = std::to_string(ocs.str());


     };
    template<typename T>
     std::string  operator/(T Word){
std::cout<<"\nCannot Preform This Action on Word Variable\n";
    return "Error";
     };
    template<typename T>

      std::string operator*(T aWord){
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




          std::ostream& operator<<(std::ostream& out,  Number& aNum){
 return out << aNum.value;;
}
          std::ostream& operator<<(std::ostream& out,  Word& aWord){
return out << aWord.value;;
}