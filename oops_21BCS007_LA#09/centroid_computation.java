//LA #09
//Problem 03

import java.util.Random;

class Element {
    // Non-virtual method
    public void displayInfo() {
        System.out.println("This is an element.");
    }
}

class Point extends Element {
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

// Example subclass
class PointElement extends Element {
    // Override the displayInfo method
    @Override
    public void displayInfo() {
        System.out.println("This is a point element.");
    }
}

public class centroid_computation {
    public static void main(String[] args) {
        // Instantiating 10000 points with random locations and find the centroid
        Point[] pointCloud = generateRandomPointCloud(10000);
        Point centroid = calculateCentroid(pointCloud);
        System.out.println("Centroid of the point cloud: (" + centroid.getX() + ", " + centroid.getY() + ")");

        // Using an Element pointer to instantiate a Point object
        Element elementPointer = new Point(3.0, 5.0);

        // Using instanceOf to find what kind of object the pointer points to
        if (elementPointer instanceof Point) {
            System.out.println("The pointer points to a Point object.");

            // Casting the pointer to Point type
            Point castedPoint = (Point) elementPointer;
            System.out.println(
                    "Casting successful. Point coordinates: (" + castedPoint.getX() + ", " + castedPoint.getY() + ")");
        } else {
            System.out.println("The pointer does not point to a Point object.");
        }
    }

    // Function to generate a random point cloud
    private static Point[] generateRandomPointCloud(int numPoints) {
        Point[] pointCloud = new Point[numPoints];
        Random random = new Random();

        for (int i = 0; i < numPoints; i++) {
            double x = random.nextDouble() * 10; // Adjust range as needed
            double y = random.nextDouble() * 10; // Adjust range as needed
            pointCloud[i] = new Point(x, y);
        }

        return pointCloud;
    }

    // Function to calculate the centroid of a point cloud
    private static Point calculateCentroid(Point[] points) {
        double sumX = 0.0;
        double sumY = 0.0;

        for (Point point : points) {
            sumX += point.getX();
            sumY += point.getY();
        }

        double centroidX = sumX / points.length;
        double centroidY = sumY / points.length;

        return new Point(centroidX, centroidY);
    }
}