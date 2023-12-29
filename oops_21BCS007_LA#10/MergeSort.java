//LA #10
//Problem 02

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MergeSort {

    public static void mergeSort(List<PointN> points) {
        if (points.size() <= 1) {
            return;
        }

        int middle = points.size() / 2;
        List<PointN> left = points.subList(0, middle);
        List<PointN> right = points.subList(middle, points.size());

        mergeSort(left);
        mergeSort(right);

        merge(points, left, right);
    }

    private static void merge(List<PointN> result, List<PointN> left, List<PointN> right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left.get(i).norm() < right.get(j).norm()) {
                result.set(k++, left.get(i++));
            } else {
                result.set(k++, right.get(j++));
            }
        }

        while (i < left.size()) {
            result.set(k++, left.get(i++));
        }

        while (j < right.size()) {
            result.set(k++, right.get(j++));
        }
    }

    public static void main(String[] args) {
        // Dummy test case for correctness check
        List<PointN> dummyPoints = generateRandomPoints(10);
        System.out.println("Original Array:");
        printPoints(dummyPoints);
        mergeSort(dummyPoints);
        System.out.println("\nSorted Array:");
        printPoints(dummyPoints);

        // Measure execution time for different array sizes
        measureExecutionTime(100);
        measureExecutionTime(1000);
        measureExecutionTime(10000);
        measureExecutionTime(100000);
    }

    private static List<PointN> generateRandomPoints(int size) {
        List<PointN> points = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < size; i++) {
            List<Double> coords = new ArrayList<>();
            for (int j = 0; j < 3; j++) {  // Generate 3-dimensional points for simplicity
                coords.add(random.nextDouble() * 100);
            }
            points.add(new PointN(coords));
        }

        return points;
    }

    private static void printPoints(List<PointN> points) {
        for (PointN point : points) {
            point.print();
        }
    }

    private static void measureExecutionTime(int size) {
        List<PointN> points = generateRandomPoints(size);
        long startTime = System.currentTimeMillis();

        mergeSort(points);

        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;

        System.out.println("\nExecution time for array of size " + size + ": " + executionTime + " milliseconds");
    }
}
