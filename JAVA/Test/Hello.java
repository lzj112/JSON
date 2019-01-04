public class Hello
{
    public static void main(String[] args)
    {
        String[] meeting = new String[3];
        meeting[0] = "Hello guy!";
        meeting[1] = "Nice to meet Java.";
        meeting[2] = "I'm a student first learning to Java.";

        for (String str : meeting)
            System.out.println(str);
    }
}
