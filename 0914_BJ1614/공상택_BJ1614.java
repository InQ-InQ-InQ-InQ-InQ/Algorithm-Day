package BaekJoon.Finger;

import java.util.Scanner;

public class Main {
    int solution(int finger, int count) {
        int answer;
        switch (finger) {
            case 1:
            case 5:
                answer = finger + (count * 8) - 1;
                break;
            case 2: {
                if (count % 2 == 0) {
                    answer = finger + (count / 2) * 8 - 1;
                } else {
                    answer = finger + ((count / 2) * 8) + 6 - 1;
                }
                break;
            }
            case 3:
                answer = finger + (count * 4) - 1;
                break;
            case 4:
                if (count % 2 == 0) {
                    answer = finger + (count / 2) * 8 - 1;
                } else {
                    answer = finger + ((count / 2) * 8) + 2 - 1;
                }
                break;
            default:
                return 0;
        }
        return answer;
    }

    public static void main(String[] args) {
        Main m = new Main();
        Scanner scanner = new Scanner(System.in);
        int num1, num2;
        num1 = scanner.nextInt();
        num2 = scanner.nextInt();
        System.out.println(m.solution(num1, num2));
    }
}
