package com.main.indep_study;

import java.util.*;

public class homework_1{

//  Problem 1
//  Checks to see if a string has all unique letters in it
//  If it does, return true, else false
    public static Boolean is_unique(String word) {
        Set<Character> unique = new HashSet<>();

        for (int i = 0; i < word.length(); i++){
            if (unique.contains(word.charAt(i))) {
                return false;
            }
            unique.add(word.charAt(i));
        }
        return true;
    }

//  Problem 2
//  Checks to see if one string is a permutation of the other
//  If it is, return true, else false
    public static Boolean is_permutation(String left, String right){
        if (left.length() != right.length()) {
            return false;
        }

        HashMap<Character, Integer> table = new HashMap<>();

        for (int i = 0; i < left.length(); i++){
            if (table.containsKey(left.charAt(i))){
                increaseKeysValue(table, left.charAt(i));
            }
            else{
                table.put(left.charAt(i), 1);
            }
        }

        for (int i = 0; i < right.length(); i++){
            if (table.containsKey(right.charAt(i))){
                decreaseKeysValue(table, right.charAt(i));
            }
            else{
                return false;
            }
        }
        return true;
    }

    private static void increaseKeysValue(HashMap<Character, Integer> table, Character letter){
        int num = table.get(letter);
        num++;
        table.replace(letter, num);
    }

    private static void decreaseKeysValue(HashMap<Character, Integer> table, Character letter){
        int value = table.get(letter);
        if (value > 1){
            value--;
            table.replace(letter, value);
        }
        else{
            table.remove(letter);
        }
    }

//  Problem 3
//  Gets rid of all spaces and replaces them with %20
    public static void changeSpace(String input, int size){
        char[] real = input.toCharArray();

        int spaces = 0;

        for (int i = size-1; i > 0 ; i--){
            if (Character.isWhitespace(real[i])){
                spaces++;
            }
        }

        char[] output = new char[size + (spaces*3)];

        int outputIndex = 0;
        for (int i = 0; i < size; i++){

            if (Character.isWhitespace(real[i])){
                output[outputIndex] = '%';
                output[outputIndex + 1] = '2';
                output[outputIndex + 2] = '0';
                outputIndex = outputIndex + 3;
            }
            else{
                output[outputIndex] = real[i];
                outputIndex++;
            }
        }
        System.out.println(new String(output));
    }

//  Problem 4
//  Checks to see if the input has a permutation which is a palindrome
//  If it does, return true, else false
    public static boolean palindromePermutation(String input){
        HashMap<Character, Integer> table = new HashMap<>();

        for (int i = 0; i < input.length(); i++){
            Character letter = input.charAt(i);
            if (Character.isWhitespace(letter)) {
                continue;
            }
            letter = Character.toLowerCase(letter);

            if (table.containsKey(letter)){
                increaseKeysValue(table, letter);
            }
            else{
                table.put(letter, 1);
            }
        }


        Collection<Integer> temp = table.values();
        Object[] output = temp.toArray();

        boolean tooManyOdd = false;

        for (int i = 0; i < temp.size(); i++){
            if ((int) output[i] % 2 != 0 && tooManyOdd) {
                return false;
            }
            else if ((int) output[i] % 2 != 0){
                tooManyOdd = true;
            }
        }

        return true;
    }

//  Problem 5
//  Checks to see if the strings are one edit distance away
//  If they are, return true, else false
    public static boolean oneAway(String left, String right){
        if (left.length() == right.length()){
            return sameSize(left, right);
        }
        else if (left.length() == right.length() + 1){
            return diffSize(right, left);
        }
        else if (left.length() + 1 == right.length()){
            return diffSize(left, right);
        }
        return false;
    }

    private static boolean sameSize(String left, String right){
        boolean once = false;

        for (int i = 0; i < left.length(); i++){
            if (left.charAt(i) != right.charAt(i) && once){
                return false;
            }
            else{
                once = true;
            }
        }
        return true;
    }

    // Need to go over this again...bc not working
    private static boolean diffSize(String left, String right){
        int indexLeft = 0;
        int indexRight = 0;

//        I should swap these to make it a bit more nice...
        while (indexRight < right.length() && indexLeft < left.length()){
            if (left.charAt(indexLeft) != right.charAt(indexRight)){
                if (indexLeft != indexRight){
                    return false;
                }
                indexRight++;
            }
            else{
                indexLeft++;
                indexRight++;
            }
        }
        return true;
    }

    public static void main(String[] args){
//         Problem 1
        System.out.println("Problem 1: Does the word have all unique letters?");
        System.out.println("is_unique(\"word\") - expect true");
        System.out.println(is_unique("word"));
        System.out.println("is_unique(\"aba\") - expect false");
        System.out.println(is_unique("aba"));
        System.out.println("\n");

//         Problem 2
        System.out.println("Problem 2: Is each string a permutation of the other?");
        System.out.println("is_permutation(\"jake\", \"goldstein\") - expect false");
        System.out.println(is_permutation("jake", "goldstein"));
        System.out.println("is_permutation(\"cisi\", \"isic\") - expect true");
        System.out.println(is_permutation("cisi", "isic"));
        System.out.println("\n");

//         Problem 3
        System.out.println("Problem 3: Print a string with spaces replaced with '%20'");
        System.out.println("changeSpace(\"Mr John Smith\t\", 13) - expect Mr%20John%20Smith");
        changeSpace("Mr John Smith	", 13);
        System.out.println("\n");

//         Problem 4
        System.out.println("Problem 4: Checks to see if the input has a permutation of a palindrome");
        System.out.println("palindromePermutation(\"tact coa\") - expect true");
        System.out.println(palindromePermutation("tact coa"));
        System.out.println("palindromePermutation(\"jake goldstein\") - expect false");
        System.out.println(palindromePermutation("jake goldstein"));
        System.out.println("\n");

//         Problem 5
        System.out.println("Problem 5: Check to see if edit distance is one away");
        System.out.println("oneAway(\"pale\", \"ple\") - expect true");
        System.out.println(oneAway("pale", "ple"));
        System.out.println("oneAway(\"pales\", \"pale\") - expect true");
        System.out.println(oneAway("pales", "pale"));
        System.out.println("oneAway(\"pale\", \"bale\") - expect true");
        System.out.println(oneAway("pale", "bale"));
        System.out.println("oneAway(\"pale\", \"bake\") - expect false");
        System.out.println(oneAway("pale", "bake"));

    }
}