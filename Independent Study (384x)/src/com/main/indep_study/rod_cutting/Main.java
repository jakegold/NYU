package com.main.indep_study.rod_cutting;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader inputReader = new InputReader();

        while (inputReader.canRead()){
            int lengthOfRod = inputReader.readLineAsInt();

            if (lengthOfRod == 0){
                break;
            }

            String[] prices = inputReader.readLineAsArray();

            Rod rod = Rod.buildRod(lengthOfRod, prices);
            int max = rod.findMaxValue();
            System.out.println(max);
        }
    }
}

class Rod {
    private static String[] prices;
    private static int length;

    private Rod(){}

    static Rod buildRod(int length, String[] prices){
        Rod rod = new Rod();
        rod.setLength(length);
        rod.setPrices(prices);
        return rod;
    }

    private void setPrices(String[] prices) {
        Rod.prices = prices;
    }

    private void setLength(int length) {
        Rod.length = length;
    }

    int findMaxValue(){
        int[] bestPrice = new int[length + 1];

        bestPrice[0] = 0;

        for (int i = 1; i < length + 1; i++){
            int currBest = -1;

            for (int j = 0; j < i; j++){
                currBest = Integer.max(currBest, Integer.parseInt(prices[j]) + bestPrice[i-j-1]);
            }

            bestPrice[i] = currBest;
        }

        return bestPrice[length];
    }
}


class InputReader{
    private BufferedReader buffer = openFile();
    private Scanner scanner = new Scanner(System.in);

    InputReader() throws FileNotFoundException {
    }

    boolean canRead() throws IOException {
        if (this.buffer != null)
            return this.buffer.ready();
        return this.scanner.hasNext();
    }

    private String readLine() throws IOException {
        if (this.buffer != null)
            return this.buffer.readLine();
        return this.scanner.nextLine();
    }

    int readLineAsInt() throws IOException {
        String line = readLine();
        return Integer.parseInt(line);
    }

    String[] readLineAsArray() throws IOException {
        return readLine().split(" ");
    }

    private BufferedReader openFile() throws FileNotFoundException {
        String filePath = getFileName();

        try {
            BufferedReader buffer = new BufferedReader(new FileReader(new File(filePath)));
            this.scanner = null;
            return buffer;
        } catch (Exception e) {
            return null;
        }
    }

    private static String getFileName(){
        return "/Users/Jake/Desktop/code/nyu/indep_study/src/com/main/indep_study/rod_cutting/input.txt";
    }
}