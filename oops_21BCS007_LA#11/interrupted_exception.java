import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.RecursiveAction;
import java.util.concurrent.ForkJoinPool;

abstract class Element {
    public abstract double norm();

    public abstract void print();
}

class PointN extends Element {
    private List<Double> coordinates;

    public PointN(List<Double> coords) {
        coordinates = new ArrayList<>(coords);
    }

    @Override
    public double norm() {
        try {
            double sum = 0.0;
            for (double coord : coordinates) {
                sum += coord * coord;
            }
            return Math.sqrt(sum);
        } catch (ArithmeticException e) {
            System.err.println("Exception in norm calculation: " + e.getMessage());
            return Double.NaN; // Return NaN for invalid norm
        }
    }

    @Override
    public void print() {
        System.out.print("PointN: ");
        for (int i = 0; i < coordinates.size(); ++i) {
            System.out.print("Coord" + (i + 1) + ": " + coordinates.get(i) + " ");
        }
        System.out.println("Norm: " + norm());
    }
}

class MergeSortTask extends RecursiveAction {
    private static final int THRESHOLD = 1000;
    private List<PointN> points;
    private static int interruptions = 0;

    public MergeSortTask(List<PointN> points) {
        this.points = points;
    }

    @Override
    protected void compute() {
        try {
            if (points.size() <= THRESHOLD) {
                mergeSort(points);
            } else {
                int middle = points.size() / 2;
                List<PointN> left = points.subList(0, middle);
                List<PointN> right = points.subList(middle, points.size());

                MergeSortTask leftTask = new MergeSortTask(left);
                MergeSortTask rightTask = new MergeSortTask(right);

                invokeAll(leftTask, rightTask);

                // Handle InterruptedException here
                try {
                    leftTask.get();
                    rightTask.get();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Thread interrupted");
                    interruptions++;
                }

                merge(points, left, right);
            }
        } catch (Exception e) {
            System.err.println("Exception during merge sort: " + e.getMessage());
        }
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

    public static int getInterruptions() {
        return interruptions;
    }
}

class interrupted_exception {

    public static void main(String[] args) {
        try {
            // Dummy test case for correctness check
            List<PointN> dummyPoints = generateRandomPoints(10);
            System.out.println("Original Array:");
            printPoints(dummyPoints);

            // Multithreaded Merge Sort
            ForkJoinPool pool = new ForkJoinPool();
            MergeSortTask task = new MergeSortTask(dummyPoints);
            pool.invoke(task);

            System.out.println("\nSorted Array:");
            printPoints(dummyPoints);

            // Measure execution time for different array sizes
            measureExecutionTime(100);
            measureExecutionTime(1000);
            measureExecutionTime(10000);
            measureExecutionTime(100000);

            // Print the number of interruptions
            System.out.println("Number of interruptions: " + MergeSortTask.getInterruptions());
        } catch (Exception e) {
            System.err.println("Exception in main: " + e.getMessage());
        }
    }

    private static List<PointN> generateRandomPoints(int size) {
        List<PointN> points = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < size; i++) {
            List<Double> coords = new ArrayList<>();
            for (int j = 0; j < 3; j++) { // Generate 3-dimensional points for simplicity
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
        try {
            // Multithreaded Merge Sort
            List<PointN> multiThreadedPoints = generateRandomPoints(size);
            ForkJoinPool pool = new ForkJoinPool();
            MergeSortTask multiThreadedTask = new MergeSortTask(multiThreadedPoints);

            long startTimeMultiThreaded = System.currentTimeMillis();
            pool.invoke(multiThreadedTask);
            long endTimeMultiThreaded = System.currentTimeMillis();
            long executionTimeMultiThreaded = endTimeMultiThreaded - startTimeMultiThreaded;

            // Print results
            System.out.println("\nExecution time for array of size " + size + ":");
            System.out.println("Multithreaded: " + executionTimeMultiThreaded + " milliseconds");
        } catch (Exception e) {
            System.err.println("Exception during multithreaded execution time measurement: " + e.getMessage());
        }
    }
}
