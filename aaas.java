import java.util.*; 
public class myPack
{
	double inr,usd;  Scanner in=new Scanner(System.in);  
     public void dollartorupee()
	{
		System.out.println("Enter dollars to convert into Rupees:");    
          usd=in.nextInt();
		inr=usd*67;
		System.out.println("Dollar ="+usd+"equal to INR="+inr);
	}
	public void rupeetodollar()
	{
		System.out.println("Enter Rupee to convert into Dollars:");    
         inr=in.nextInt();
		usd=inr/67;
		System.out.println("Rupee ="+inr+"equal to Dollars="+usd);
    }
}

import java.util.*; 
import java.io.*;
import myPack.*;   
class Converter
{
  public static void main(String args[])
  {
    Scanner s=new Scanner(System.in);
    int choice,ch;
    myPack c=new myPack();
   do
   {
	   System.out.println("1.dollar to rupee ");
	   System.out.println("2.rupee to dollar "); 
	   System.out.println("Enter ur choice"); choice=s.nextInt();   
        switch(choice)
	   {
	   case 1:
	   {
		   c.dollartorupee(); 
		   break;
	   }
	   case 2:
	   {
		   c.rupeetodollar(); 
		   break;
	   }
	   }
	   System.out.println("Enter 0 to quit and 1 to continue ");     
        ch=s.nextInt();
   }while(ch==1);
  }
}
