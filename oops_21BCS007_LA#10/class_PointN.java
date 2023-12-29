//LA #10
//Problem 01

import java.util.ArrayList;
import java.util.List;

abstract class Element {
    public abstract double norm();

    public abstract void print();
}

class PointN extends Element {
    private List<Double> coordinates;

    // Default constructor
    public PointN() {
        coordinates = new ArrayList<>();
    }

    // Parameterized constructor
    public PointN(List<Double> coords) {
        coordinates = new ArrayList<>(coords);
    }

    // Override norm function for n-dimensional point
    @Override
    public double norm() {
        double sum = 0.0;
        for (double coord : coordinates) {
            sum += coord * coord;
        }
        return Math.sqrt(sum);
    }

    // Override print function to display details of PointN
    @Override
    public void print() {
        System.out.print("PointN: ");
        for (int i = 0; i < coordinates.size(); ++i) {
            System.out.print("Coord" + (i + 1) + ": " + coordinates.get(i) + " ");
        }
        System.out.println("Norm: " + norm());
    }
}

class class_PointN {
    public static void main(String[] args) {
        // Example usage of PointN
        List<Double> coords = List.of(1.0, 2.0, 3.0);
        PointN point = new PointN(coords);

        // Call print and norm functions
        point.print();
        System.out.println("Norm: " + point.norm());
    }
}