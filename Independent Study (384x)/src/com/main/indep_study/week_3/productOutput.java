package com.main.indep_study.week_3;

public enum productOutput {
    PLUS, MINUS, ZERO;

    public static productOutput getProductOutput(int number){
        if (number == 0)
            return ZERO;
        else if (number > 0)
            return PLUS;
        return MINUS;
    }
}
