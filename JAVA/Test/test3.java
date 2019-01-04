import java.io.*;

class A 
{
    int a;
    A() 
    {
        a = 10;
    }
    int getDate() 
    {
        return a;
    }
}
public class test3 
{
    public static void main(String[] args) 
    {
        A aa = new A();
        boolean isTrue;
        isTrue = aa instanceof A;
        System.err.println(isTrue);
    }
}