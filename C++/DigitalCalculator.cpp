// any base to any base [2 - 20]

//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#define size 4
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class Base
{
   char str1[100]; //char str1[] = "11A";
   char str2[100];
   int sourceBase = 0;
   int desBase = 0;
   int op = 0;
   int num1 = 0, num2 = 0;
   int dec = 0;
   int ans = 0;
   

public:
   int choice = 0;
   char binary[size + 1], one[size + 1], two[size + 1];
   int i, carry = 1, fail = 0;
   string number;

   int val(char c);

   void getInput_BaseConvertor()   
   {
      cout << endl << "Enter number: ";
      cin >> str1;

      cout << "From Base   : ";
      cin >> sourceBase;

      cout << "To base     : ";
      cin >> desBase;
      convert_decimal();
   }

   void getInput_BaseCalculator()   
   {
      sourceBase = 10;  // first converting to decimal base then back to des base
      cout << endl << "Enter Base: ";
      cin >> desBase;

      cout << "First Number   : ";
      cin >> str1;

      cout << "Select Operation   : ";
      cin >> op;

      cout << "Second Number     : ";
      cin >> str2;

      num1 = convert_decimal2(str1);
      num2 = convert_decimal2(str2);

      //cout << endl << num1 << endl << num2;

      BaseCalculator();
   }

   void getInput_Comp1and2()
   {
      cout << " Input a 4 " << " bit binary number: ";
      cin >> binary;
   }  

   void getInput_Comp9and10()
   {
      cout << "Enter Decimal number: ";
      cin >> number;
   }   

   void conv(int decimal)  // method converts decimal to any base
   {
      string result = "";
      char NUMS[] = "0123456789ABCDEFGHIJ";

       if(decimal == 0) 
           exit(0);  

        do{
           result.push_back(NUMS[decimal%desBase]);   // push_back fun -> inserts new element at the end of vector and increases size of vector by one.
           // Append the appropriate character in NUMS based on the equation decimal%base
           
           decimal /= desBase; // Calculate new value of decimal
            }
          while(decimal != 0); // Do while used for slight optimisation
       
       //cout << endl << result << endl;

            cout << endl << "Result Number : " << string(result.rbegin(), result.rend()) << endl << endl;
            // using string() constructer with iterators to reverse the string
            //std::vector::rbegin() returns a reverse iterator which points to the last element of the vector.
            //std::vector::rend() returns a reverse iterator which points to the reverse end of the vector i.e. beginning of the vector.
   }

   void convert_decimal()  // base converter
   {
      int len = strlen(str1);
      int power = 1;
      int num = 0;

      for (int i = len - 1; i >= 0; i--) {
         if (val(str1[i]) >= sourceBase) {
            cout << "Invalid Number" << endl;;
            exit(0);
         }
         num += val(str1[i]) * power;
         power = power * sourceBase;
      }
      //cout << endl << num << endl;
      conv(num) ;
   }

   int convert_decimal2(char *str)   // base calculator
   {
      int len = strlen(str);
      int power = 1;
      int num = 0;
      int i;
      for (i = len - 1; i >= 0; i--) {
         if (val(str[i]) >= desBase) {
            printf("Invalid Number");
            return -1;
         }
         num += val(str[i]) * power;
         power = power * desBase;
      }
      return num;
   }

   void BaseCalculator()
   {
      switch(op)
      {
         case 0:
            cout << "No Operation Selected!!"<< endl;
            break;

         case 1:
            ans = num1+num2;
            break;

         case 2:
            ans = num1-num2;
            break;

         case 3:
            ans = num1*num2;
            break;

         case 4:
            ans = num1/num2;
            break;

         defaulf:
            cout <<"Invalid option!!" << endl;   
      }
      //cout << endl << ans << endl;
      conv(ans);
   }

};//class ends here

int Base :: val(char c)    // 0 - J
{
   if (c >= '0' && c <= '9')
      return (int)c - '0';
   else
      return (int)c - 'A' + 10; 
}

class Complement: public Base       // Inheritance
{
   int code =0;

public:
   void Decision()
   {
      cout << endl << endl << "Enter Operation: ";
      cin >> code;
      
      if(code == 1)
      {
         getInput_Comp1and2();
         Complement1and2();
      }
      else if(code == 2)
      {
         getInput_Comp9and10();
         Complement9and10();
      }
      else
         cout << "Enter Valid Option!!";  
   }

   void Complement1and2()
   {
      for (i = 0; i < size; i++) 
      {
       if (binary[i] == '1') {
         one[i] = '0';
       } else if (binary[i] == '0') {
         one[i] = '1';
       } else {
         cout << "Error! Input the number of assigned bits." << endl;
         fail = 1;
         break;
       }
      }
      one[size] = '\0';

     for (i = size - 1; i >= 0; i--) 
     {
       if (one[i] == '1' && carry == 1) {
         two[i] = '0';
       } else if (one[i] == '0' && carry == 1) {
         two[i] = '1';
         carry = 0;
       } else {
         two[i] = one[i];
       }
     }
     two[size] = '\0';
     
     if (fail == 0) 
     {
       cout << " The original binary = " << binary << endl;
       cout << " After ones complement the value = " << one << endl;
       cout << " After twos complement the value = " << two << endl;
     }
   }

   void Complement9and10()
   {
      for (int i=0 ; i < number.length() ; i++ )
        if (number[i] != '.')
            number[i] = '9' - number[i] + '0';
 
       cout << "9's complement is : " << number << endl;
       
       // way to convert strings of digits into ints, floats or doubles using stringstream
       // object from the class stringstream
       stringstream Tointerger(number);
    
       // The object has the value 12345 and stream
       // it to the integer x
       int x = 0;
       Tointerger >> x;
       
       x++;
       cout << "10's complement is : " << x << endl << endl;
   }
};

//***************************************************************
//       function declaration
//****************************************************************
void Project_Intro();
void intro_BaseConverter();
void intro_BaseCalculator();
void intro_ComplementCalculator();

//***************************************************************
//       THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
   Base b;
   Complement c;

   Project_Intro();
   cout << "Enter Operation: ";
   cin >> b.choice;

   switch(b.choice)
   {
      case 1: 
         intro_BaseConverter();
         b.getInput_BaseConvertor();
         break;

      case 2:
         //Base b;
         intro_BaseCalculator();
         b.getInput_BaseCalculator();
         break;

      case 3:
         intro_ComplementCalculator();
         c.Decision(); 
         break;

      default:
         cout << "Enter Valid Option" << endl;
   }
   return 0;  
}

//***************************************************************
//       INTRODUCTION FUNCTION
//****************************************************************
void Project_Intro()
   {
      cout<<"\n\n\n\t  Digital Calculator";
      cout<<"\n\n\tPerforms following Operations" << endl << endl << endl;
      cout<<"1. Base Convertor" << endl;
      cout<<"2. Base Calculator" << endl; 
      cout<<"3. Complement Calculator" << endl; 
      cout<<"-------------------------------------------" << endl; 
      
      cin.get();
   }

void intro_BaseConverter()
{
   cout<<"\n\n\n\t  Base Converter";
   cout<<"\n\t     [2 - 20]";
   cout<<"\n\n\n\nConvert number from any base to any base";
   
   cin.get();
}

void intro_BaseCalculator()
{
   cout<<"\n\n\n\t  Base Calculator";
   cout<<"\n\t     [2 - 20]";
   cout<<"\n\n\n\nBase calculations with 2 numbers" <<endl; 
   cout << "1. addition\n2. subtraction\n3. multiplication\n4. division:" << endl << endl;
   
   cin.get();
}

void intro_ComplementCalculator()
{
   cout<<"\n\n\n\t  Complement Calculator" << endl << endl << endl;
   cout << "1| 1's and 2's  |\n2| 9's and 10's |" << endl << endl;
   
   cin.get();
}
//***************************************************************
//             END OF PROJECT
//***************************************************************