// SetOperations

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class SetOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Set<Integer> setA = new HashSet<>();
        Set<Integer> setB = new HashSet<>();

        int choice;
        do {
            System.out.println("1. Add element to set A");
            System.out.println("2. Add element to set B");
            System.out.println("3. Delete element from set A");
            System.out.println("4. Delete element from set B");
            System.out.println("5. Display elements from set A");
            System.out.println("6. Display elements from set B");
            System.out.println("7. Search element in set A");
            System.out.println("8. Search element in set B");
            System.out.println("9. Size of set A");
            System.out.println("10. Size of set B");
            System.out.println("11. Union of sets");
            System.out.println("12. Intersection of sets");
            System.out.println("13. Difference of sets");
            System.out.println("14. Check if set A is a subset of set B");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter element to add to set A: ");
                    setA.add(scanner.nextInt());
                    break;
                case 2:
                    System.out.print("Enter element to add to set B: ");
                    setB.add(scanner.nextInt());
                    break;
                case 3:
                    System.out.print("Enter element to delete from set A: ");
                    setA.remove(scanner.nextInt());
                    break;
                case 4:
                    System.out.print("Enter element to delete from set B: ");
                    setB.remove(scanner.nextInt());
                    break;
                case 5:
                    System.out.println("Elements in set A: " + setA);
                    break;
                case 6:
                    System.out.println("Elements in set B: " + setB);
                    break;
                case 7:
                    System.out.print("Enter element to search in set A: ");
                    System.out.println("Element found in set A: " + setA.contains(scanner.nextInt()));
                    break;
                case 8:
                    System.out.print("Enter element to search in set B: ");
                    System.out.println("Element found in set B: " + setB.contains(scanner.nextInt()));
                    break;
                case 9:
                    System.out.println("Size of set A: " + setA.size());
                    break;
                case 10:
                    System.out.println("Size of set B: " + setB.size());
                    break;
                case 11:
                    Set<Integer> unionSet = new HashSet<>(setA);
                    unionSet.addAll(setB);
                    System.out.println("Union of sets: " + unionSet);
                    break;
                case 12:
                    Set<Integer> intersectionSet = new HashSet<>(setA);
                    intersectionSet.retainAll(setB);
                    System.out.println("Intersection of sets: " + intersectionSet);
                    break;
                case 13:
                    Set<Integer> differenceSet = new HashSet<>(setA);
                    differenceSet.removeAll(setB);
                    System.out.println("Difference of sets (A - B): " + differenceSet);
                    break;
                case 14:
                    System.out.println("Set A is a subset of set B: " + setB.containsAll(setA));
                    break;
                case 0:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 0);
    }
}
