package com.main.indep_study;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class fileOpener {

    public static BufferedReader openFileAsBufferReader(String fileName){
        String filePath = makeFileName(fileName);

        File file = new File(filePath);

        try {
            if (file.exists()) {
                return new BufferedReader(new FileReader(file));
            }
            else return null;
        }
        catch (FileNotFoundException ex){
            System.out.println("File not found. Returning Null");
            return null;
        }
    }

    public static FileReader openFileasFileReader(String fileName){
        String filePath = makeFileName(fileName);

        File file = new File(filePath);

        try {
            if (file.exists()) {
                return new FileReader(file);
            }
            else return null;
        }
        catch (FileNotFoundException ex){
            System.out.println("File not found. Returning Null");
            return null;
        }
    }

    private static String makeFileName(String path){
        return "/Users/Jake/Desktop/code/nyu/indep_study/src/com/main/indep_study/input_files/" + path;
    }
}


