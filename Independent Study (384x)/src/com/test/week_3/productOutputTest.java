package com.test.week_3;

import com.main.indep_study.week_3.productOutput;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class productOutputTest {
    @Test
    void getProductOutput() {
        assertEquals(productOutput.PLUS, productOutput.getProductOutput(10));
        assertNotEquals(productOutput.PLUS, productOutput.getProductOutput(0));
        assertNotEquals(productOutput.PLUS, productOutput.getProductOutput(-10));

        assertEquals(productOutput.MINUS, productOutput.getProductOutput(-10));
        assertNotEquals(productOutput.MINUS, productOutput.getProductOutput(0));
        assertNotEquals(productOutput.MINUS, productOutput.getProductOutput(10));

        assertEquals(productOutput.ZERO, productOutput.getProductOutput(0));
        assertNotEquals(productOutput.ZERO, productOutput.getProductOutput(10));
        assertNotEquals(productOutput.ZERO, productOutput.getProductOutput(-10));
    }

}