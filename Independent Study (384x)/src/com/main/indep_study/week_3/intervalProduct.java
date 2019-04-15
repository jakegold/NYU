package com.main.indep_study.week_3;

import com.main.indep_study.fileOpener;
import com.main.indep_study.week_3.elementsAndSteps;

import java.io.BufferedReader;
import java.io.IOException;

public class intervalProduct {
    public static void main(String[] args) throws IOException{
        BufferedReader file = fileOpener.openFileAsBufferReader("interval_product.txt");

        while (file.ready()){
            run(file);
            System.out.println();
        }
    }

    private static void run(BufferedReader file) throws IOException{
        elementsAndSteps testCase = buildElementsAndSteps(file);


//        testCase.display();

        for (int i = 0; i < testCase.getNumSteps(); i++){
            String command = file.readLine();
            String[] temp = command.split(" ");

            if (changeCommand(temp[0])){
                int intIndex = Integer.parseInt(temp[1]) - 1;
                int changeValue = Integer.parseInt(temp[2]);

                testCase.change(intIndex, changeValue);
            }
            else{
                int first = Integer.parseInt(temp[1]) - 1;
                int last = Integer.parseInt(temp[2]);

                System.out.print(testCase.product(first, last));
                System.out.print(" ");
            }
        }
    }

    private static elementsAndSteps buildElementsAndSteps(BufferedReader file) throws IOException{
        String line1 = file.readLine();
        String line2 = file.readLine();

        return new elementsAndSteps(line1, line2);
    }

    private static boolean changeCommand(String command){
        return command.equals("C");
    }
}
