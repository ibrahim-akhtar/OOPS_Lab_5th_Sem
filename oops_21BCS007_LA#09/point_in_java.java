//LA #09
//Problem 02

class Point {
    private double x;
    private double y;

    // Default constructor
    public Point() {
        this.x = 0.0;
        this.y = 0.0;
    }

    // Parameterized constructor
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Getter methods
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    // Method to calculate distance from another point
    public double distFrom(Point other) {
        double deltaX = this.x - other.x;
        double deltaY = this.y - other.y;
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // Method to calculate midpoint with another point
    public Point midPoint(Point other) {
        double midX = (this.x + other.x) / 2.0;
        double midY = (this.y + other.y) / 2.0;
        return new Point(midX, midY);
    }
}

// Element class
class Element {
    // Non-virtual method
    public void displayInfo() {
        System.out.println("This is an element.");
    }
}

// Example subclass
class PointElement extends Element {
    // Override the displayInfo method
    @Override
    public void displayInfo() {
        System.out.println("This is a point element.");
    }
}

// Main class for testing
class point_in_java {
    public static void main(String[] args) {
        // Test the Point class
        Point point1 = new Point(1.0, 2.0);
        Point point2 = new Point(4.0, 6.0);

        System.out.println("Distance between points: " + point1.distFrom(point2));
        Point midpoint = point1.midPoint(point2);
        System.out.println("Midpoint: (" + midpoint.getX() + ", " + midpoint.getY() + ")");

        // Test the Element and PointElement classes
        Element element = new Element();
        element.displayInfo();

        PointElement pointElement = new PointElement();
        pointElement.displayInfo();
    }
}
