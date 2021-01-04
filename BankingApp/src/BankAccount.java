import java.util.*;


class BankAccount
{
	Scanner s = new Scanner(System.in);


	private int balance;
	private int PIN;
	private String accountName;
	
	BankAccount()
	{
	System.out.println("Please enter account name");
	accountName = s.nextLine();
	System.out.println("Please enter primary deposit");
	balance = s.nextInt();
//momenfahmid's code
	System.out.println("Please create a PIN for your account");
	PIN = s.nextInt();

	System.out.println("Account has been created");
	}

	public int getBalance(int pin)
{
    if (pin == this.PIN)
    {
		//System.out
		return this.balance;
		
    }

    else
    {
        System.out.println("pin incorrect");
        return 0;
    }
}
}
