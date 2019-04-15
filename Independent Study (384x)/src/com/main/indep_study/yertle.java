package com.main.indep_study;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class yertle {
    public static void main(String[] args) throws IOException{
        Scanner scanner = new Scanner(System.in);
        int numberOfCases = getNumberFromScanner(scanner);

        for (int i = 0; i < numberOfCases; i++){
            stackTurtles(scanner);
            System.out.println();
        }
    }

    public static void stackTurtles(Scanner scanner) throws IOException{
        int heightOfTurtleStack = getNumberFromScanner(scanner);

        ArrayList<String> currentTurtleStack = getNamesFromScanner(scanner, heightOfTurtleStack);
        ArrayList<String> desiredTurtleStack = getNamesFromScanner(scanner, heightOfTurtleStack);

        HashMap<String, Integer> turtleNumberMap = buildTurtleNumberMap(desiredTurtleStack);

        ArrayList<Integer> intsToSort = convertArrayFromStringsToInts(currentTurtleStack, turtleNumberMap);

        ArrayList<Integer> movedNumbers = shellSort(intsToSort);

        for (Integer movedNumber : movedNumbers) {
            System.out.println(desiredTurtleStack.get(movedNumber));
        }
    }

    public static int getNumberFromScanner(Scanner scanner) throws IOException{
        return Integer.parseInt(scanner.nextLine());
    }

    public static ArrayList<String> getNamesFromScanner(Scanner scanner, int numberOfNames) throws IOException{
        ArrayList<String> ListOfNames = new ArrayList<>();
        for (int i = 0; i < numberOfNames; i++){
            ListOfNames.add(scanner.nextLine());
        }
        return ListOfNames;
    }

//    Returns HashMap<turtle, number>
    public static HashMap<String, Integer> buildTurtleNumberMap(ArrayList<String> turtleStack){
        HashMap<String, Integer> turtleNumberMap = new HashMap<>();
        for (int i = 0; i < turtleStack.size(); i++){
            turtleNumberMap.put(turtleStack.get(i), i);
        }
        return turtleNumberMap;
    }

    public static ArrayList<Integer> convertArrayFromStringsToInts(ArrayList<String> keyStrings, HashMap<String, Integer> hashMap){
        ArrayList<Integer> valueInts = new ArrayList<>();

        for (String turtleName : keyStrings) {
            valueInts.add(hashMap.get(turtleName));
        }

        return valueInts;
    }

    public static ArrayList<Integer> shellSort(ArrayList<Integer> intsToSort){
        ArrayList<Integer> movedInts = new ArrayList<>();

        int spotsOff = 0;
        for (int i = intsToSort.size() - 1; i >= 0; i--){
            if (intsToSort.get(i) - spotsOff != i){
                movedInts.add(intsToSort.get(i));
                spotsOff++;
            }
        }
        return movedInts;
    }

}
