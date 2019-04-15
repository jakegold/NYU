package com.main.indep_study.count_ways;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws IOException {
        WaysToMakeChange result = WaysToMakeChange.buildWaysToMakeChange();

        InputReader reader = new InputReader();

        while (reader.canRead()){
            int change = reader.readLineAsInt();
            result.makeChange(change);
        }
    }
}

class WaysToMakeChange {
    private static long[][] waysOfChange;

    private WaysToMakeChange(){}

    static WaysToMakeChange buildWaysToMakeChange(){
        WaysToMakeChange waysToMakeChange = new WaysToMakeChange();
        waysToMakeChange.resultWaysToMakeChange();
        return waysToMakeChange;
    }

    private void resultWaysToMakeChange(){
        waysOfChange = new long[6][30001];
        fillTable();
    }

    private void fillTable(){
        for (int i = 1; i < 6; i++){
            Coin coin = new Coin(i);
            for (int j = 0; j < 30001; j++){
                if (i == 1){
                    waysOfChange[i][j] = 1;
                }
                else{
                    if (j < coin.getValue()){
                        waysOfChange[i][j] = waysOfChange[i-1][j];
                    }
                    else{
                        waysOfChange[i][j] = waysOfChange[i-1][j] + waysOfChange[i][j-coin.getValue()];
                    }
                }
            }
        }
    }

    void makeChange(int change){
        long waysToMakeCorrectChange = waysOfChange[5][change];

        if (waysToMakeCorrectChange == 1){
            System.out.println(String.format("There is only 1 way to produce %s cents change.", change));
        }
        else{
            System.out.println(String.format("There are %s ways to produce %s cents change.", waysToMakeCorrectChange, change));
        }
    }

}

class Coin{
    private int value;

    Coin(int index){
        switch (index){
            case 1:
                this.value = 1;
                break;
            case 2:
                this.value = 5;
                break;
            case 3:
                this.value = 10;
                break;
            case 4:
                this.value = 25;
                break;
            case 5:
                this.value = 50;
                break;
        }
    }

    int getValue() {
        return this.value;
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

    String readLine() throws IOException {
        if (this.buffer != null)
            return this.buffer.readLine();
        return this.scanner.nextLine();
    }

    int readLineAsInt() throws IOException {
        String line = readLine();
        return Integer.parseInt(line);
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
        return "/Users/Jake/Desktop/code/nyu/indep_study/src/com/main/indep_study/count_ways/input.txt";
    }
}