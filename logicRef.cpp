#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

// Forward Dec.
class Variable;
class Number;
class Word;
namespace memory
{

    void addValueToMemory(Variable *aVar);
    float getValue(Number *aNum);
    std::string getValue(Word *aWord);
    extern std::map<std::string, Variable *> allVariables; // gosh i hate this

}

template <typename T>
class CPUClass
{
    std::vector<T> allVar;

public:
    void load(T aVar)
    {
        allVar.push_back(aVar);
    }
    T add()
    {
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b = allVar.at(1);
        // std::cout<<"\nVal of a "<<a<<" \t vall of b "<<b<<std::endl;
        return a + b;
    }
    T subtract()
    {
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b = allVar.at(1);
        return a - b;
    }
    T divide()
    {
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b = allVar.at(1);
        return a / b;
    }
    T multiply()
    {
        // std::cout<<allVar.at(0);
        T a = allVar.at(0);
        T b = allVar.at(1);
        return a * b;
    }
    bool compare()
    {
        T a = allVar.at(0);
        T b = allVar.at(1);
        return a == b;
    }
    void clearVector()
    {
        allVar.clear();
    }

    bool andCompare()
    {
        bool a, b;
        std::istringstream(allVar.at(0)) >> std::boolalpha >> a;
        std::istringstream(allVar.at(1)) >> std::boolalpha >> b;
        return (a && b);
    }
    bool orCompare()
    {
        bool a, b;

        std::istringstream(allVar.at(0)) >> std::boolalpha >> a;
        std::istringstream(allVar.at(1)) >> std::boolalpha >> b;
        return (a || b);
    }
    bool notCompare()
    {
        T a = allVar.at(0);
        T b = allVar.at(1);
        return a != b;
    }

    bool andCompareFloat()
    {
        bool a = allVar.at(0);
        bool b = allVar.at(1);
        return (a && b);
    }
    bool orCompareFloat()
    {
        bool a = allVar.at(0);
        bool b = allVar.at(1);
        return (a || b);
    }
};

class Variable
{
public:
    Variable() { memory::addValueToMemory(this); }
    virtual std::string getValueStr() = 0;
    virtual float getValue() = 0;
};

class Number : public Variable
{
private:
    CPUClass<float> pc;
    friend std::ostream &operator<<(std::ostream &out, Number &aNum);
    friend std::istream &operator>>(std::istream &in, Number &aNum);

public:
    Number(){};
    float value;
    std::string getValueStr() { return "2"; };
    float getValue() { return value; }

    //------OPERATOR = -----------------------------------------------
    void operator=(std::string aWord)
    {
        std::cout << "\nError\n";
        this->value = 0;
    }
    void operator=(Word &aWord)
    {
        std::cout << "\nError\n";
        this->value = 0;
    }
    void operator=(float aNum)
    {
        this->value = static_cast<float>(aNum);
    };
    //------OPERATOR == -----------------------------------------------
    int operator==(Word &aVar)
    {
        std::cout << "\nError\n";
        return 0;
    }
    int operator==(Number &aVar)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aVar));
        return pc.compare();
    }
    int operator==(std::string aVar)
    {
        std::cout << "\nError\n";
        return 0;
    }
    int operator==(float aVar)
    {
        pc.clearVector();
        std::ostringstream ocs;
        ocs << &aVar;
        pc.load(memory::getValue(this));
        pc.load(aVar);
        return pc.compare();
    }
    //------OPERATOR + -----------------------------------------------

    float operator+(Word &aWord)
    {
        std::cout << "\nError\n";
        return 0;
    }
    float operator+(Number &aNum)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        return pc.add();
    };

    float operator+(float aNum)
    {
        pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        return pc.add();
    };
    float operator+(std::string aword)
    {
        std::cout << "\nError\n";
        return 0;
    }
    //------OPERATOR - -----------------------------------------------

    float operator-(float aNum)
    {
        pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        return pc.subtract();
    };
    float operator-(Number &aNum)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        return pc.subtract();
    };

    float operator-(Word &aWord)
    {
        std::cout << "\nError\n";
        return 0;
    }
    float operator-(std::string aword)
    {
        std::cout << "\nError\n";
        return 0;
    }
    //------OPERATOR / -----------------------------------------------

    float operator/(float aNum)
    {
        pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        return pc.divide();
    };
    float operator/(std::string aword)
    {
        std::cout << "\nError\n";
        return 0;
    }

    float operator/(Number &aNum)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        return pc.divide();
    };

    float operator/(Word &aWord)
    {
        std::cout << "\nError\n";
        return 0;
    }
    //------OPERATOR * -----------------------------------------------
    float operator*(float aNum)
    {
        pc.clearVector();
        pc.load(memory::getValue(this));
        pc.load(aNum);
        return pc.multiply();
    };
    float operator*(Number &aNum)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aNum));
        return pc.multiply();
    };
    float operator*(Word &aWord)
    {
        std::cout << "\nError\n";
        return 0;
    }

    float operator*(std::string aword)
    {
        std::cout << "\nError\n";
        return 0;
    }
    //------OPERATOR && -----------------------------------------------
    int operator&&(std::string aFlag)
    {
        if ((aFlag != "true" && aFlag != "false") || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        if (aFlag == "true")
        {
            pc.load(1);
        }
        else if (aFlag == "false")
        {
            pc.load(0);
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc.load(0);
        }
        pc.load(memory::getValue(this));

        return pc.andCompareFloat();
    }
    int operator&&(Word &aFlag)
    {
        if ((memory::getValue(&aFlag) != "true" && memory::getValue(&aFlag) != "false") || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        if (memory::getValue(&aFlag) == "true")
        {
            pc.load(1);
        }
        else if (memory::getValue(&aFlag) == "false")
        {
            pc.load(0);
        }
        pc.load(memory::getValue(this));
        return pc.andCompareFloat();
    }
    int operator&&(Number &aFlag)
    {
        if ((memory::getValue(&aFlag) != 1 && memory::getValue(&aFlag) != 0) || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        pc.load(memory::getValue(&aFlag));
        pc.load(memory::getValue(this));

        return pc.andCompareFloat();
    }
    int operator&&(float aFlag)
    {
        if ((aFlag != 1 && aFlag != 0) || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        pc.load(aFlag);
        pc.load(memory::getValue(this));

        return pc.andCompareFloat();
    }
    //------OPERATOR != -----------------------------------------------

    int operator!=(std::string aFlag)
    {
        std::cout << "\nError\n";
        return 0;
    }
    int operator!=(Word &aFlag)
    {
        std::cout << "\nInvalid Flag\n";
        return 0;
    }
    int operator!=(Number &aFlag)
    {
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aFlag));
        return pc.notCompare();
    }
    int operator!=(float aFlag)
    {
        pc.load(aFlag);
        pc.load(memory::getValue(this));
        return pc.notCompare();
    }
    //------OPERATOR || -----------------------------------------------

    int operator||(std::string aFlag)
    {
        if ((aFlag != "true" && aFlag != "false") || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        if (aFlag == "true")
        {
            pc.load(1);
        }
        else if (aFlag == "false")
        {
            pc.load(0);
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc.load(0);
        }
        pc.load(memory::getValue(this));
        return pc.orCompareFloat();
    }
    int operator||(Word &aFlag)
    {
        if ((memory::getValue(&aFlag) != "true" && memory::getValue(&aFlag) != "false") || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        if (memory::getValue(&aFlag) == "true")
        {
            pc.load(1);
        }
        else if (memory::getValue(&aFlag) == "false")
        {
            pc.load(0);
        }
        pc.load(memory::getValue(this));
        return pc.orCompareFloat();
    }
    int operator||(float aFlag)
    {
        if ((aFlag != 1 && aFlag != 0) || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        pc.load(aFlag);
        pc.load(memory::getValue(this));
        return pc.orCompareFloat();
    }
    int operator||(Number& aFlag)
    {
        if ((aFlag.getValue() != 1 && aFlag.getValue() != 0) || (this->value != 1 && this->value != 0))
        {
            std::cout << "\nInvalid Flag\n";
            return 0;
        }
        pc.load(memory::getValue(this));
        pc.load(memory::getValue(&aFlag));
        return pc.orCompareFloat();
    }
};

class Word : public Variable
{
    friend std::ostream &operator<<(std::ostream &out, Word &aNum);

    CPUClass<std::string> pc2;

public:
    float getValue() { return 9.4; };
    std::string value;
    std::string getValueStr()
    {
        return value;
    }
    //------OPERATOR == -----------------------------------------------

    std::string operator==(char aVar)
    {
        pc2.clearVector();
        std::ostringstream ocs, ocs1;
        ocs << aVar;
        pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
        ocs1 << std::boolalpha << pc2.andCompare();
        return ocs1.str();
    }
    std::string operator==(Number &aVar)
    {
        pc2.clearVector();
        std::ostringstream ocs, ocs1;
        ocs << memory::getValue(&aVar);
        pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
        ocs1 << std::boolalpha << pc2.compare();

        return ocs1.str();
    }
    std::string operator==(int aVar)
    {

        pc2.clearVector();
        std::ostringstream ocs, ocs1;
        ocs << aVar;
        pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
        ocs1 << std::boolalpha << pc2.compare();

        return ocs1.str();
    }
    std::string operator==(std::string aVar)
    {
        pc2.clearVector();
        std::ostringstream ocs1;

        pc2.load(memory::getValue(this));
        pc2.load(aVar);
        ocs1 << std::boolalpha << pc2.compare();

        return ocs1.str();
    }
    std::string operator==(double aVar)
    {
        pc2.clearVector();
        std::ostringstream ocs, ocs1;
        ocs << aVar;
        pc2.load(memory::getValue(this));
        pc2.load(ocs.str());
        ocs1 << std::boolalpha << pc2.compare();

        return ocs1.str();
    }
    std::string operator==(Word &aVar)
    {
        std::ostringstream  ocs1;
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aVar));
        ocs1 << std::boolalpha << pc2.compare();
        return ocs1.str();
    }

    //------OPERATOR && -----------------------------------------------

    std::string operator&&(std::string aFlag)
    {
        if ((aFlag != "true" && aFlag != "false") || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;

        pc2.load(memory::getValue(this));
        pc2.load(aFlag);
        ocs1 << std::boolalpha << pc2.andCompare();

        return ocs1.str();
    }
    std::string operator&&(bool &aFlag)
    {
        std::cout << aFlag;
        pc2.clearVector();
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        ocs << std::boolalpha << aFlag;
        pc2.load(ocs.str());
        ocs1 << std::boolalpha << pc2.andCompare();

        return ocs1.str();
    }

    std::string operator&&(float aFlag)
    {
        if (this->value != "false" && this->value != "true")
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        if (aFlag == 1)
        {
            pc2.load("true");
        }
        else if (aFlag == 0)
        {
            pc2.load("false");
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc2.load("false");
        }
        ocs1 << std::boolalpha << pc2.andCompare();

        return ocs1.str();
    }
    std::string operator&&(Word &aFlag)
    {
        if ((aFlag.value != "true" && aFlag.value != "false") || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aFlag));

        ocs1 << std::boolalpha << pc2.andCompare();

        return ocs1.str();
    }
    std::string operator&&(Number &aFlag)
    {
        if ((aFlag.value != 1 && aFlag.value != 0) || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;

        pc2.load(memory::getValue(this));
        ocs << memory::getValue(&aFlag);
        if (ocs.str() == "1")
        {
            pc2.load("true");
        }
        else if (ocs.str() == "0")
        {
            std::cout << "here";
            pc2.load("false");
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc2.load("false");
        }

        ocs1 << std::boolalpha << pc2.andCompare();

        return ocs1.str();
    }
    //------OPERATOR != -----------------------------------------------

    std::string operator!=(std::string aFlag)
    {
        if ((aFlag != "true" && aFlag != "false") || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;

        pc2.load(memory::getValue(this));
        pc2.load(aFlag);
        ocs1 << std::boolalpha << pc2.notCompare();

        return ocs1.str();

        // ocs1 << std::boolalpha <<pc2.compare();
    }
    std::string operator!=(float aFlag)
    {
        pc2.clearVector();
        std::ostringstream ocs, ocs2, ocs1;
        ocs << aFlag;
        std::string s(1, aFlag);
        int a = aFlag - '0';

        // std::cout<<a<<std::endl;
        std::cout << aFlag << "\t" << a << std::endl;
        std::cout << aFlag << "\t" << s << std::endl;
        std::cout << aFlag << "\t" << ocs.str() << std::endl;

        if ((aFlag - '0') >= 0 && (aFlag - '0') <= 127)
        {
            pc2.load(s);
        }
        else
        {
            std::cout << "here";
            pc2.load(ocs.str());
        }
        ///////THIS LOGIC is dumb but effiecent
        //  std::cout<<ocs.str()<<"here";
        pc2.load(memory::getValue(this));
        ocs1 << std::boolalpha << pc2.notCompare();
        return ocs1.str();
    }
    std::string operator!=(Word &aFlag)
    {
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aFlag));

        ocs1 << std::boolalpha << pc2.notCompare();

        return ocs1.str();
    }
    std::string operator!=(Number &aFlag)
    {
        if ((aFlag.value != 1 && aFlag.value != 0) || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;

        pc2.load(memory::getValue(this));
        ocs << memory::getValue(&aFlag);
        if (ocs.str() == "1")
        {
            pc2.load("true");
        }
        else if (ocs.str() == "0")
        {
            std::cout << "here";
            pc2.load("false");
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc2.load("false");
        }

        ocs1 << std::boolalpha << pc2.notCompare();

        return ocs1.str();
    }
    //------OPERATOR || -----------------------------------------------

    std::string operator||(std::string aFlag)
    {
        if ((aFlag != "true" && aFlag != "false") || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        pc2.load(aFlag);
        ocs1 << std::boolalpha << pc2.orCompare();

        return ocs1.str();
    }
    std::string operator||(float aFlag)
    {
        if (this->value != "false" && this->value != "true")
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        if (aFlag == 1)
        {
            pc2.load("true");
        }
        else if (aFlag == 0)
        {
            std::cout << "here";
            pc2.load("false");
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc2.load("false");
        }
        ocs1 << std::boolalpha << pc2.orCompare();

        return ocs1.str();
    }
    std::string operator||(Word &aFlag)
    {
        if ((aFlag.value != "true" && aFlag.value != "false") || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aFlag));

        ocs1 << std::boolalpha << pc2.orCompare();

        return ocs1.str();
    }
    std::string operator||(Number &aFlag)
    {
        if ((aFlag.value != 1 && aFlag.value != 0) || (this->value != "true" && this->value != "false"))
        {
            std::cout << "\nInvalid Flag\n";
            return "false";
        }
        std::ostringstream ocs, ocs1;

        pc2.load(memory::getValue(this));
        ocs << memory::getValue(&aFlag);
        if (ocs.str() == "1")
        {
            pc2.load("true");
        }
        else if (ocs.str() == "0")
        {
            std::cout << "here";
            pc2.load("false");
        }
        else
        {
            std::cout << "\nInvalid Flag\n";
            pc2.load("false");
        }

        ocs1 << std::boolalpha << pc2.orCompare();

        return ocs1.str();
    }
    //------OPERATOR - -----------------------------------------------

    template <typename T>
    std::string operator-(T aWord)
    {
        std::cout << "\nError\n";
        return "Error";
    }
    //------OPERATOR + -----------------------------------------------

    std::string operator+(Word &aWord)
    {
        pc2.load(memory::getValue(this));
        pc2.load(memory::getValue(&aWord));
        return pc2.add();
    };

    std::string operator+(std::string aWord)
    {
        pc2.clearVector();
        pc2.load(memory::getValue(this));
        pc2.load(aWord);
        return pc2.add();
    };

    std::string operator+(Number aWord)
    {
        std::cout << "\nError\n";
        return "Error";
    };
    std::string operator+(char aWord)
    {
        pc2.clearVector();
        pc2.load(memory::getValue(this));
        std::string s(1, aWord);
        pc2.load(s);
        return pc2.add();
    };

    std::string operator+(float aWord) { return "Error"; };
    std::string operator+(double aWord) { return "Error"; };
    std::string operator+(int aWord) { return "Error"; };
    //------OPERATOR = -----------------------------------------------

    void operator=(std::string aWord)
    {
        this->value = aWord;
    };
    void operator=(char aWord)
    {
        this->value = aWord;
    };
    void operator=(int aWord)
    {
        this->value = std::to_string(aWord);
    };
    void operator=(Word &aWord)
    {
        this->value = aWord.getValueStr();
    };
    void operator=(double aWord)
    {
        std::ostringstream ocs;
        ocs << aWord;
        ocs << std::fixed << std::setprecision(2);
        this->value = ocs.str();
    };
    void operator=(Number &aWord)
    {
        std::ostringstream ocs;
        ocs << aWord.value;
        ocs << std::fixed << std::setprecision(2);
        this->value = ocs.str();
    };
    //------OPERATOR / -----------------------------------------------
    template <typename T>
    std::string operator/(T Word)
    {
        std::cout << "\nCannot Preform This Action on Word Variable\n";
        return "Error";
    };
    //------OPERATOR * -----------------------------------------------

    template <typename T>

    std::string operator*(T aWord)
    {
        std::cout << "\nCannot Preform This Action on Word Variable\n";
        return "Error";
    };
};

namespace memory
{

    std::map<std::string, Variable *> allVariables;
    void addValueToMemory(Variable *aVar)
    {
        std::ostringstream ocs;
        ocs << aVar;
        allVariables[ocs.str()] = aVar;
    };
    float getValue(Number *aNum)
    {
        std::ostringstream ocss;
        ocss << aNum;
        return allVariables[ocss.str()]->getValue();
    };

    std::string getValue(Word *aWord)
    {
        std::ostringstream ocss;
        ocss << aWord;
        return allVariables[ocss.str()]->getValueStr();
    };
}

std::ostream &operator<(std::ostream &out, Number &aNum)
{
    return out << aNum.value;
}
std::ostream &operator<(std::ostream &out, Word &aWord)
{
    return out << aWord.value;
}

std::istream &operator>(std::istream &in, Number &aNum)
{
    in >> aNum.value;
    return in;
}
std::istream &operator>(std::istream &in, Word &aWord)
{
    in >> aWord.value;
    return in;
}
std::istream &operator>(std::istream &in, double aNum)
{
    in >> aNum;
    return in;
}
std::istream &operator>(std::istream &in, std::string aNum)
{
    in >> aNum;
    return in;
}
std::istream &operator>(std::istream &in, char aNum)
{
    in >> aNum;
    return in;
}


std::ostream &operator<(std::ostream &out, double aWord)
{
    return out << aWord;
}

std::ostream &operator<(std::ostream &out, std::string aWord)
{
    return out << aWord;
}
std::ostream &operator<(std::ostream &out, char aWord)
{
    return out << aWord;
}