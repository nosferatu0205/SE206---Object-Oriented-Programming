import java.util.*;
public class MainFunc {
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        //System.out.println("Please enter account name");
        //String AccountName = s.nextLine();
//momenfahmid's code

        BankAccount account1 = new BankAccount();

        System.out.println("Account Balance  " +account1.getBalance(9999));
}
}