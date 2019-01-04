import java.util.*;

public class Final_1 
{
    public static long func(int a) 
    {
        if (a == 1 || a == 0) 
        {
            return 1;
        }
        else 
        {
            return a * func(a - 1);
        }
    }

    public static void main(String[] args) 
    {
        Scanner in_ = new Scanner(System.in);
        int a = in_.nextInt();
        int b  = 1;
        int c = 3;
        System.out.println(b + " " + c);
        // System.out.printf("%d\n", func(a));
    }
}