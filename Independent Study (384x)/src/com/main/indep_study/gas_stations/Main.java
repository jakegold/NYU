package com.main.indep_study.gas_stations;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Integer.min;
import static java.lang.String.valueOf;

public class Main{
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();

        while (reader.canRead()){
            String line = reader.readLine();

            Road gasStation = Road.buildRoad(line);

            for (int i = 0; i < gasStation.getNumOfStations(); i++){
                line = reader.readLine();
                gasStation.addStationToAllStations(line);
            }

            int result;
            if (gasStation.getNumOfStations() != 0 && gasStation.coversWholeRoad()){
                result = gasStation.findExtraStations();
            }
//            BUGS FOR THE LAST CASE OF 0 0
            else{
                result = -1;
            }
            System.out.println(result);
        }
    }
}

class Road {
    private int lengthOfRoad;
    private int numOfStations;
    private ArrayList<Station> allStations = new ArrayList<>();

    private Road(){}

    static Road buildRoad(String data){
        Road road = new Road();
        road.roadBuilder(data);
        return road;
    }

    private void roadBuilder(String data){
        String[] temp = data.split(" ");
        this.lengthOfRoad = Integer.parseInt(temp[0]);
        this.numOfStations = Integer.parseInt(temp[1]);
    }

    void addStationToAllStations(String data){
        Station station = Station.buildStation(data, this.lengthOfRoad);
        this.allStations.add(station);
    }

    int getNumOfStations() {
        return numOfStations;
    }

    int findExtraStations(){
        int best = -1;
        for (int i = 0; i < this.numOfStations; i++) {
            int a = other(i, 0, this.lengthOfRoad);

            System.out.println("HERE?");



//            EfficientRoad efficientRoad = EfficientRoad.buildEfficientRoad(this.allStations, i);
//            efficientRoad.setLengthOfRoad(this.lengthOfRoad);
//            int curr = efficientRoad.findOnlyNeededStations();
//            if (curr > best){
//                best = curr;
//            }
        }
        return best;
    }

    @Override
    public String toString(){
        String result = "Length of road: " + lengthOfRoad;
        result += "Number of Gas Stations: " + numOfStations;
        result += "Road Covered: " + allStations;
        return result;
    }

    boolean coversWholeRoad(){
        Station firstStation = this.allStations.get(0);
        int min = firstStation.getMin();
        int max = firstStation.getMax();

        for (int i = 1; i < this.numOfStations; i ++){
            Station curr = this.allStations.get(i);

            if (curr.hasSmallerMinThan(min) && curr.maxFallsInRange(min, max)){
                min = curr.getMin();
            }
            if (curr.hasLargerMaxThan(max) && curr.minFallsInRange(min, max)){
                max = curr.getMax();
            }
        }
        return min == 0 && max == this.lengthOfRoad;
    }

    int other(int index, int left, int right){
//        T(n, [a,b]) = min{ T( n-1, [a,b] ), T( n-1, [a, n_left ] )+1 } where this second recurrance is only called if n_right >= b.

//        System.out.println(index);

        int first, second;
        first = other(index-1, left, right);


        if (this.allStations.get(index).getMax() >= right) {
            second = other(index - 1, left, this.allStations.get(index).getMin()) + 1;
        }
        else{
            second = first + 1;
        }
        return min(first, second);
//        System.out.println()
    }
}

class Station{
    private int min;
    private int max;

    private Station(){}

    static Station buildStation(String data, int maxSize){
        Station station = new Station();
        station.stationBuilder(data, maxSize);
        return station;
    }

    private void stationBuilder(String data, int maxSize){
        String[] temp = data.split(" ");
        int location = Integer.parseInt(temp[0]);
        int range = Integer.parseInt(temp[1]);

        this.min = 0;
        if (location - range > 0)
            this.min = location - range;

        this.max = maxSize;
        if (location + range < maxSize)
            this.max = location + range;
    }

    int getMin() {
        return min;
    }

    int getMax() {
        return max;
    }

//    CAN I CHANGE THIS TO LESS THAN OR EQUALS TO??
    boolean hasSmallerMinThan(int min){
        return this.min <= min;
    }

    //    CAN I CHANGE THIS TO GREATER THAN OR EQUALS TO??
    boolean hasLargerMaxThan(int max){
        return this.max >= max;
    }

    boolean maxFallsInRange(int min, int max){
        return this.max >= min && this.max <= max;
    }

    boolean minFallsInRange(int min, int max){
        return this.min >= min && this.min <= max;
    }

    @Override
    public String toString() {
        return "[Min: " + valueOf(this.min) + ", Max: " + valueOf(this.max) + "]";
    }
}

class EfficientRoad{
    private List<Station> allNeededStations = new ArrayList<>();
    private List<Station> allStations;
    private int indexOfMyStation;
    private int lengthOfRoad;

    private EfficientRoad(){}

    static EfficientRoad buildEfficientRoad(ArrayList<Station> allStations, int index){
        EfficientRoad efficientRoad = new EfficientRoad();
        efficientRoad.efficientRoadBuilder(allStations, index);
        return efficientRoad;
    }

    private void efficientRoadBuilder(ArrayList<Station> allStations, int index) {
        this.indexOfMyStation = index;
        this.allStations = allStations;
        this.allNeededStations.add(allStations.get(index));
    }

    void setLengthOfRoad(int lengthOfRoad) {
        this.lengthOfRoad = lengthOfRoad;
    }

    int findOnlyNeededStations(){
        addStationsWithLargerMax();
        addStationsWithSmallerMin();

        return this.allStations.size() - this.allNeededStations.size();
    }

    private Station getLastStation(){
        return this.allNeededStations.get(this.allNeededStations.size()-1);
    }

    private Station getFirstStation(){
        return this.allNeededStations.get(0);
    }

    private void addStationsWithLargerMax(){
//        THESE TWO COULD GO IN LOOP?
        Station lastStation = getLastStation();
        int currentMax = lastStation.getMax();

        int startingIndex = this.indexOfMyStation + 1;

        while (currentMax < this.lengthOfRoad){
            Station bestChoiceForIteration = null;
            for (int i = startingIndex; i < this.allStations.size(); i++){
                Station temp = this.allStations.get(i);
                if (temp.hasLargerMaxThan(currentMax) && temp.hasSmallerMinThan(lastStation.getMax())){
                    bestChoiceForIteration = temp;
                    currentMax = bestChoiceForIteration.getMax();
                    startingIndex = i;
                }
            }
            if (bestChoiceForIteration == null){
                break;
            }
            this.allNeededStations.add(bestChoiceForIteration);
            lastStation = bestChoiceForIteration;
        }
    }

    private void addStationsWithSmallerMin(){
        Station myStation = getFirstStation();

        int currentMin = myStation.getMin();
        int startingIndex = this.indexOfMyStation - 1;

        while (currentMin > 0){
            Station best = null;
            for (int j = startingIndex; j >= 0; j--) {
                Station temp = this.allStations.get(j);
                if (temp.hasSmallerMinThan(currentMin) && temp.hasLargerMaxThan(myStation.getMin())){
                    currentMin = temp.getMin();
                    best = temp;
                    startingIndex = j;
                }
            }
            if (best == null){
                break;
            }
            this.allNeededStations.add(best);
            myStation = best;
        }
    }
}

class InputReader{
    private BufferedReader buffer = openFile();
    private Scanner scanner = new Scanner(System.in);

    InputReader() throws FileNotFoundException {
    }

    boolean canRead() throws IOException {
        if (this.buffer != null)
            return this.buffer.ready();
        return this.scanner.hasNext();
    }

    String readLine() throws IOException {
        if (this.buffer != null)
            return this.buffer.readLine();
        return this.scanner.nextLine();
    }

    private BufferedReader openFile() throws FileNotFoundException {
        String filePath = getFileName();

        try {
            BufferedReader buffer = new BufferedReader(new FileReader(new File(filePath)));
            this.scanner = null;
            return buffer;
        } catch (Exception e) {
            return null;
        }
    }

    private static String getFileName(){
        return "/Users/Jake/Desktop/code/nyu/indep_study/src/com/main/indep_study/gas_stations/gas_stations.txt";
    }
}
