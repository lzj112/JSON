import java.util.Scanner;
/* 你的代码将被嵌入到这里 */

class Rectangle 
{
    double width;
    double height;
    public Rectangle() 
    {
        width = 1;
        height = 1;
    }
    public Rectangle(double w, double h) 
    {
        width = w;
        height = h;
    }
    public double getArea() 
    {
        return width * height;
    }
    public double getPerimeter() 
    {
        return (2 * (width + height));
    }
}
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    double w = input.nextDouble();
    double h = input.nextDouble();
    Rectangle myRectangle = new Rectangle(w, h);
    System.out.println(myRectangle.getArea());
    System.out.println(myRectangle.getPerimeter());

    input.close();
  }
}