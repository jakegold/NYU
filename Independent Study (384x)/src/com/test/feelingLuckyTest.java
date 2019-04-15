package com.test;

import com.main.indep_study.feelingLucky;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class feelingLuckyTest {
    @org.junit.jupiter.api.Test
    void main() {
    }

    @org.junit.jupiter.api.Test
    void getNumTests() {
    }

    @org.junit.jupiter.api.Test
    void feelingLucky() {
    }

    @org.junit.jupiter.api.Test
    void newBest() {
        ArrayList<String> testArray1 = new ArrayList<>(Arrays.asList("one.com", "two.com", "three.com"));
        ArrayList<String> testArray2 = new ArrayList<>();
        String testString = "test.com";

        feelingLucky.newBest(testArray1, testString);
        feelingLucky.newBest(testArray2, testString);

        assertEquals(1, testArray1.size());
        assertEquals(testString, testArray1.get(0));

        assertEquals(1, testArray2.size());
        assertEquals(testString, testArray2.get(0));
    }

    @org.junit.jupiter.api.Test
    void printResults() {
    }

}