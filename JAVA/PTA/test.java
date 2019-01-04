import java.io.*;


class A 
{
    int a;
}

class B extends A 
{
    int a;
}

class C extends A 
{
    int a;
}

public class test 
{
    public static void main(String[] args) 
    {
        A a;
        B b;
        C c;
        if (b instanceof A) 
        {
            c = (C)b;
        }
    }
}