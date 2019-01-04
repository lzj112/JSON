class test
{
    test() 
    {
        System.out.println("here is test2");
    }
    void func() 
    {
        System.out.println("here is func");
    }
}

class test2 
{
    public static void main(String agc[]) 
    {
        System.out.println("here is main");
        // test obj;
        // obj.func();
        test obj2 = new test();
        obj2.func();
    }
}