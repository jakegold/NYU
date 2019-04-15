package com.main.indep_study;

import java.io.BufferedReader;
import java.io.IOException;

public class trainTracks {
    public static void main(String[] args) throws IOException {
        BufferedReader file = fileOpener.openFileAsBufferReader("train_tracks.txt");

        int numProblems = getNumTests(file);

        for (int i = 0; i < numProblems; i++){
            System.out.println("Case " + (i+1) + ':');
            Boolean result = trainTracks(file);
            output(result);
        }
    }

    public static int getNumTests(BufferedReader file) throws IOException {
        return Integer.parseInt(file.readLine());
    }

    public static Boolean trainTracks(BufferedReader file) throws IOException {
        String line = file.readLine();
        int M = 0;
        int F = 0;

        for (int i = 0; i < line.length(); i++){
            if (line.charAt(i) == ' '){
                continue;
            }
            if (line.charAt(i) == 'M'){
                M++;
            }
            else{
                F++;
            }
        }

        return M == F;
    }

    public static void output(Boolean result){
        if (result){
            System.out.println("LOOP");
        }
        else{
            System.out.println("NO LOOP");
        }
    }

}
