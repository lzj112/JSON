
class RegularPolygon extends shape {
    private int n;
    private double side;
    public RegularPolygon(int n, double side) {
        this.n = n;
        this.side = side;
    }
    public double getArea() {
        return n*side*side/(Math.tan(Math.toRadians(180/n))*4);
    }
    public double getPerimeter() {
        return n*side;
    }
}
