package com.test.week_3;

import com.main.indep_study.week_3.elementsAndSteps;
import com.main.indep_study.week_3.productOutput;
import org.junit.jupiter.api.Test;


import static org.junit.jupiter.api.Assertions.*;

class elementsAndStepsTest {
    @Test
    void getNumElements() {
        elementsAndSteps tester = new elementsAndSteps("2 10", "1 2");

        assertEquals(2, tester.getNumElements());
    }

    @Test
    void getNumSteps() {
        elementsAndSteps tester = new elementsAndSteps("2 10", "1 2");

        assertEquals(10, tester.getNumSteps());
    }


    @Test
    void product() {
//        System.out.println("ONE");
        elementsAndSteps tester1 = new elementsAndSteps("5 10", "1 2 3 4 5");

        assertEquals(productOutput.PLUS, tester1.product(0, 2));
        assertEquals(productOutput.PLUS, tester1.product(1, 5));

//        System.out.println("TWO");
        elementsAndSteps tester2 = new elementsAndSteps("5 10", "-1 2 3 4 5");

        assertEquals(productOutput.MINUS, tester2.product(0, 2));
        assertEquals(productOutput.PLUS, tester2.product(2, 5));

//        System.out.println("THREE");
        elementsAndSteps tester3 = new elementsAndSteps("5 10", "-1 2 0 4 5");

        assertEquals(productOutput.MINUS, tester3.product(0, 2));
        assertEquals(productOutput.ZERO, tester3.product(2, 5));

//        System.out.println("FOUR");
        elementsAndSteps tester4 = new elementsAndSteps("5 10", "-1 -2 0 4 5");

        assertEquals(productOutput.PLUS, tester4.product(0, 2));
        assertEquals(productOutput.ZERO, tester4.product(2, 3));
    }

}