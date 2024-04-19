#include "logicRef.cpp"
void testCasesNumberAdd();
void testCasesNumberMinus();
void testCasesNumberTimes();
void testCasesNumberDivide();
void testCasesNumberCompare();
void testCasesWordAdd();
void testCasesWordMinus();
void testCasesWordMultiply();
void testCasesWordDivide();
void testCasesWordCompare();

int main(){
// testCasesNumberAdd(); //Pass
// testCasesNumberMinus(); //Pass
// testCasesNumberTimes(); //Pass
// testCasesNumberDivide(); //Pass
// testCasesNumberCompare(); //Pass
testCasesWordAdd(); //Pass
testCasesWordMinus(); //Pass
testCasesWordMultiply(); //Pass
testCasesWordDivide(); //Pass
testCasesWordCompare(); //Pass
// Word word1,word2;
// Number a,b;
// a = 1;
// b=0;
// word1 = "false";
// // word2 = "false";
// // std::cout<<(word1 && "5");
// // std::cout<<(word1 && true);
// // std::cout<<(word1 && a);
// // std::cout<<(a && "false"); 
// // std::cout<<(a != 5.4);
// // std::cout<<(a || 5.4);
// b = (a || 5.4);
// std::cout<<b;
// // std::cout<<(a && word2);
// // std::cout<<(a && word1);
return 0;
}









// int main(){
// Number a , b, c;
// Word aw, ae2;
// aw= "2";
// a = 5;
// b = 43.3;
// // c = a&&b;
// std::cout<<"\n";
// // output <<c;// Error
// // std::cout<<"\n"; 
// // c = a!=b; 
// // c = a!=5; 
// // c = a!='s'; 
// // c = a!=aw;  
// // c = a != 5; 
// // ae2 = aw != "false";
// // ae2 = aw != 'i'; 
// // output <<ae2; // True
// ae2 = aw != 9090;
// std::cout<<"\n";
// output <<ae2; // True
// // c = a==b;
// // std::cout<<"\n";
// // output <<c;//False 0
// // output <<a;








// return 0;
// }













void testCasesNumberAdd(){
    Number a, b, c;
    Word word1,word;
    word1 = word;
    a =5;
b=10.3;
c = a +b;
std::cout<<"\tc = a +b;\t"<<c<<std::endl;
c = a + "b"; //error
std::cout<<"\tc = a + b string;\t"<<c<<std::endl;
c = a + 'b';// 
std::cout<<"\tc = a +b char ;\t"<<c<<std::endl;
c = a + word1;
std::cout<<"\tc = a + word1;\t"<<c<<std::endl;
c = a+ 2;
std::cout<<"\tc = a +2;\t"<<c<<std::endl;
c = a + 2.3;
std::cout<<"\tc = a +2.3;\t"<<c<<std::endl;
}
void testCasesNumberMinus(){
    Number a, b, c;
    Word word1;
    a =5;
b=10;
c = a -b;
std::cout<<"\tc = a -b;\t"<<c<<std::endl;
c = a - "b"; //error
std::cout<<"\tc = a - b string;\t"<<c<<std::endl;
c = a - 'b';// 
std::cout<<"\tc = a -b char ;\t"<<c<<std::endl;
c = a - word1;
std::cout<<"\tc = a - word1;\t"<<c<<std::endl;
c = a - 2;
std::cout<<"\tc = a -2;\t"<<c<<std::endl;
c = a - 2.3;
std::cout<<"\tc = a -2.3;\t"<<c<<std::endl;
}
void testCasesNumberTimes(){
    Number a, b, c;
    Word word1;
    a =5;
b=10;
c = a *b;
std::cout<<"\tc = a +b;\t"<<c<<std::endl;
c = a * "b"; //error
std::cout<<"\tc = a + b string;\t"<<c<<std::endl;
c = a * 'b';// 
std::cout<<"\tc = a +b char ;\t"<<c<<std::endl;
c = a * word1;
std::cout<<"\tc = a + word1;\t"<<c<<std::endl;
c = a * 2;
std::cout<<"\tc = a +2;\t"<<c<<std::endl;
c = a * 2.3;
std::cout<<"\tc = a +2.3;\t"<<c<<std::endl;
}
void testCasesNumberDivide(){
    Number a, b, c;
    Word word1;
    a =5;
b=10;
c = a /b;
std::cout<<"\tc = a +b;\t"<<c<<std::endl;
c = a / "b"; //error
std::cout<<"\tc = a + b string;\t"<<c<<std::endl;
c = a / 'b';// 
std::cout<<"\tc = a +b char ;\t"<<c<<std::endl;
c = a / word1;
std::cout<<"\tc = a + word1;\t"<<c<<std::endl;
c = a / 2;
std::cout<<"\tc = a +2;\t"<<c<<std::endl;
c = a / 2.3;
std::cout<<"\tc = a +2.3;\t"<<c<<std::endl;
}
void testCasesNumberCompare(){
    Number a, b, c;
    Word word1;
    a =5;
b=5;
c = a == b;
std::cout<<"\tc = a +b;\t"<<c<<std::endl;
c = a == "b"; //error
std::cout<<"\tc = a + b string;\t"<<c<<std::endl;
c = a == 'b';// 
std::cout<<"\tc = a +b char ;\t"<<c<<std::endl;
c = a == word1;
std::cout<<"\tc = a + word1;\t"<<c<<std::endl;
c = a == 5;
std::cout<<"\tc = a +2;\t"<<c<<std::endl;
c = a == 5.0;
std::cout<<"\tc = a +2.3;\t"<<c<<std::endl;
}
void testCasesWordAdd(){
    Number a,c;
    Word word1,word2, result;
a=5;
word1 ="word1";
word2 ='2';


result = word1 + word2;
std::cout<<"\tresult = word1 + word2;\t"<<result<<std::endl;
result = word1 + "b"; 
std::cout<<"\tresult = word1 + b string;\t"<<result<<std::endl;
result = word1 + 'b';// 
std::cout<<"\tresult = word1 + 'b';\t"<<result<<std::endl;
result = word2 + a;
std::cout<<"\tresult = word2 + a;\t"<<result<<std::endl;
result  = word1 + 5;
std::cout<<"\tresult  = word1 + 5;\t"<<result<<std::endl;
result = word1 + 2.3;
std::cout<<"\tresult = word1 + 2.3;\t"<<result<<std::endl;
}
void testCasesWordMinus(){
    Number a,c;
    Word word1,word2, result;
a=5;
word1 ="word1";
word2 ='2';


result = word1 - word2;
std::cout<<"\tresult = word1 - word2;\t"<<result<<std::endl;
result = word1 - "b"; 
std::cout<<"\tresult = word1 - b string;\t"<<result<<std::endl;
result = word1 - 'b';// 
std::cout<<"\tresult = word1 + 'b';\t"<<result<<std::endl;
result = word2 - a;
std::cout<<"\tresult = word2 + a;\t"<<result<<std::endl;
result  = word1 - 5;
std::cout<<"\tresult  = word1 + 5;\t"<<result<<std::endl;
result = word1 - 2.3;
std::cout<<"\tresult = word1 + 2.3;\t"<<result<<std::endl;
}
void testCasesWordMultiply(){
    Number a,c;
    Word word1,word2, result;
a=5;
word1 ="word1";
word2 ='2';


result = word1 * word2;
std::cout<<"\tresult = word1 - word2;\t"<<result<<std::endl;
result = word1 * "b"; 
std::cout<<"\tresult = word1 - b string;\t"<<result<<std::endl;
result = word1 * 'b';// 
std::cout<<"\tresult = word1 + 'b';\t"<<result<<std::endl;
result = word2 * a;
std::cout<<"\tresult = word2 + a;\t"<<result<<std::endl;
result  = word1 * 5;
std::cout<<"\tresult  = word1 + 5;\t"<<result<<std::endl;
result = word1 * 2.3;
std::cout<<"\tresult = word1 + 2.3;\t"<<result<<std::endl;
}
void testCasesWordDivide(){
    Number a,c;
    Word word1,word2, result;
a=5;
word1 ="word1";
word2 ='2';


result = word1 / word2;
std::cout<<"\tresult = word1 - word2;\t"<<result<<std::endl;
result = word1 / "b"; 
std::cout<<"\tresult = word1 - b string;\t"<<result<<std::endl;
result = word1 / 'b';// 
std::cout<<"\tresult = word1 + 'b';\t"<<result<<std::endl;
result = word2 / a;
std::cout<<"\tresult = word2 + a;\t"<<result<<std::endl;
result  = word1 / 5;
std::cout<<"\tresult  = word1 + 5;\t"<<result<<std::endl;
result = word1 / 2.3;
std::cout<<"\tresult = word1 + 2.3;\t"<<result<<std::endl;
}
void testCasesWordCompare(){
    Number a,c;
    Word word1,word2, result;
a=2.3;
word1 ="2";
word2 ='2';


result = word1 == word2;
std::cout<<"\tresult = word1 - word2;\t"<<result<<std::endl;
result = word1 ==  "2"; 
std::cout<<"\tresult = word1 - b string;\t"<<result<<std::endl;
result = word1 == '2';// 
std::cout<<"\tresult = word1 + 'b';\t"<<result<<std::endl;
result = word2 == a;
std::cout<<"\tresult = word2 + a;\t"<<result<<std::endl;
result  = word1 == 2;
std::cout<<"\tresult  = word1 + 5;\t"<<result<<std::endl;
result = word1 == 2.3;
std::cout<<"\tresult = word1 + 2.3;\t"<<result<<std::endl;
}
