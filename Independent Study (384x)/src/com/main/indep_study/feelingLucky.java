package com.main.indep_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;


public class feelingLucky {
    public static void main(String[] args) throws IOException {
        BufferedReader file = fileOpener.openFileAsBufferReader("feeling_lucky.txt");

        int numProblems = getNumTests(file);

        for (int i = 0; i < numProblems; i++){
            System.out.println("Case " + (i+1) + ':');
            ArrayList<String> results = feelingLucky(file);
            printResults(results);
        }
    }

    public static int getNumTests(BufferedReader file) throws IOException{
        return Integer.parseInt(file.readLine());
    }

    public static ArrayList<String> feelingLucky(BufferedReader file) throws IOException{
        int numLines = 0;
        String line;
        int best = 0;
        ArrayList<String> results = new ArrayList<>();

        while (numLines < 10){
            line = file.readLine();

            String[] split = line.split(" ");

            if (Integer.parseInt(split[1]) > best){
                best = Integer.parseInt(split[1]);
                newBest(results, split[0]);
            }
            else if(Integer.parseInt(split[1]) == best){
                results.add(split[0]);
            }
            numLines++;
        }
        return results;
    }

    public static void newBest(ArrayList<String> results, String site){
        if (results.size() != 0)
            results.clear();
        results.add(site);
    }

    public static void printResults(ArrayList<String> results){
        for (String item: results){
            System.out.println(item);
        }
    }

}
