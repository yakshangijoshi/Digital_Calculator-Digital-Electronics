//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
import java.util.Scanner;

//***************************************************************
//                   CLASS Declaration IN PROJECT
//****************************************************************
public class ComplementCalculator
{
	static final int size = 4;  
	Scanner sc = new Scanner(System.in);
	int ch;
	//int binary, decimal;
	char[] binary = new char[size+1]; 
	char[] one = new char[size+1]; 
	char[] two = new char[size+1]; 
	int i, carry = 1, fail = 0; 

//***************************************************************
//       INTRODUCTION FUNCTIONS
//****************************************************************
	void Project_Intro()
	{
		System.out.println("\n\n\n\tComplement Calculator");
		System.out.println("\n\n\tPerforms following Complements");
	}

	void Intro2()
	{
	    System.out.println("1| 1's |\n2| 2's |");
	   	System.out.print("Enter Choice: ");
	   	ch = sc.nextInt();
	}

//***************************************************************
//       Decision FUNCTION
//****************************************************************
	void Decision()
	{
		if(ch == 1)
		{
			getInput_Comp1and2();
			check();
			Evaluate();
			Complement1();
		}	
			
		else if(ch == 2)
		{
			getInput_Comp1and2();
			check();
			Evaluate();
			Complement2();
		} 
		else
			System.out.println("Enter Valid Choice!!");
	}

//***************************************************************
//       Input FUNCTION
//****************************************************************
	void getInput_Comp1and2()
   	{
    	System.out.print("Input a 4 bit binary number: ");
    	binary = sc.next().toCharArray();  	
   	}  	

//***************************************************************
//       Correction FUNCTION
//****************************************************************
   	void check()
   	{
   		for (i = 0; i < size; i++) 
      {
       if (binary[i] == '1') {
         one[i] = '0';
       } else if (binary[i] == '0') {
         one[i] = '1';
       } else {
         System.out.println("Error! Input the number of assigned bits.");
         fail = 1;
         break;
       }
      }
      one[size] = '\0';
   	}

//***************************************************************
//       Evaluation FUNCTIONS
//****************************************************************	
	void Evaluate()
	{
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
 	}

 	void Complement1(){
     if (fail == 0) 
     {
       System.out.print("The original binary = ");
       for (char c:binary) {
       	System.out.print(c);  
       }
       System.out.println();

       System.out.print("After ones complement the value = ");
       for (char c:one) {
       	System.out.print(c);  
       }
       System.out.println();

     }
	}

	void Complement2()
	{
		System.out.print("The original binary = ");
       for (char c:binary) {
       	System.out.print(c);  
       }
       System.out.println();

       System.out.print("After twos complement the value = ");
       for (char c:two) {
       	System.out.print(c);  
       }
       System.out.println();
	}

//***************************************************************
//       THE MAIN FUNCTION OF PROGRAM
//****************************************************************
	public static void main(String args[])
	{
		ComplementCalculator obj = new ComplementCalculator();
		obj.Project_Intro();
		obj.Intro2();
		obj.Decision();
	}
}
//***************************************************************
//             END OF PROJECT
//***************************************************************