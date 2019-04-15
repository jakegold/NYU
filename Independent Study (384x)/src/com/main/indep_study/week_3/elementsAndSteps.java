package com.main.indep_study.week_3;

import java.util.ArrayList;

public class elementsAndSteps {
    private int numElements;
    private int steps;
    private ArrayList<Integer> elements;

    public elementsAndSteps(String line1, String line2) {
        String[] temp = line1.split(" ");

        this.numElements = Integer.parseInt(temp[0]);
        this.steps = Integer.parseInt(temp[1]);

        this.elements = new ArrayList<Integer>();
        setElements(line2);
    }

    public int getNumElements() {
        return numElements;
    }

    public int getNumSteps(){
        return steps;
    }

    private void setElements(String stringElements){
        String[] temp = stringElements.split(" ");
        for (int i = 0; i < temp.length; i++){
            this.elements.add(Integer.parseInt(temp[i]));
        }
    }

    public void display(){
        System.out.println("Number of elements: " + this.numElements);
        System.out.println("Number of steps: " + this.steps);

        System.out.println(this.elements);
    }


    public void change(int index, int value){
        this.elements.set(index, value);
    }

    public productOutput product(int first, int last){
        int product = this.elements.get(first);
        for (int i = first + 1; i < last; i++)
            product = product * this.elements.get(i);
        return productOutput.getProductOutput(product);
    }

}
