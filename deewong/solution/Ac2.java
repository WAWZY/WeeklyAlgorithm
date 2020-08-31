package deewong.solution;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Ac2 {

    public static void main(String[] args) {

        int output = 0;
        
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();
        
        ArrayList<Integer> input = new ArrayList<>();

        for(int i = 0; i < n; i ++) {
            input.add(sc.nextInt());
        }

        sc.close();
        
        // Solution

        Collections.sort(input);

        if(x == 0) {
            if(input.get(0) == 0) {
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }else {

            for(int i = 0; i < input.size(); i ++) {

                int temp = input.get(i);
                if(temp < x) {
                    output --;
                }else if(temp == x){
                    output ++;
                }else {
                    break;
                }
            }

            System.out.println(x + output);

        }
    }
}