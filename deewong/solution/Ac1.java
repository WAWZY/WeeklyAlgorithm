package deewong.solution;

import java.util.Scanner;

public class Ac1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int userInput = scanner.nextInt();

        if(userInput < 4) {
            System.out.println("NO");
            System.exit(0);
        }

        System.out.println("YES");
        printDetail(userInput);

        scanner.close();
    }

    private static void printDetail(int n) {

        String result4 = "2 * 4 = 8\n3 * 8 = 24\n1 * 24 = 24";
        String result5 = "5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24";
        // default set to even
        boolean odd = false;
        int endNumber = 4;

        if(n % 2 != 0) {
            odd = true;
            endNumber = 5;
        }

        while(n > endNumber) {

            System.out.println(Integer.toString(n) + " - " + Integer.toString(n-1) + " = " + Integer.toString(n - (n-1)));
            n -= 2;
            System.out.println(Integer.toString(n) + " * 1 = " + Integer.toString(n));
            
        }

        System.out.println(odd ? result5 : result4);

    }

}
