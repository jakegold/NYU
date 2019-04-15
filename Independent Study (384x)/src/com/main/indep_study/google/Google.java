package com.main.indep_study.google;
import java.util.*;
import java.io.*;


public class Google {
    public static void main(String[] args){
        Node root = new Node(5, 3);
        buildRoad(root);
        printRoad(root);
    }

    private static void buildRoad(Node root){
        if (root == null)
            return;

        int robots = root.robots;
        int length = root.length;

//      Left we add a robot
        if (robots > 0 && robots <= length){
            int newLength = length - 1;
            int newRobots = robots - 1;

            root.left = new Node(newLength, newRobots);
            buildRoad(root.left);
        }

//      Right we add a road
        if (length > 0 && length > robots){
            int newLength = length - 1;

            root.right = new Node(newLength, robots);
            buildRoad(root.right);
        }
    }

    private static void levelOrder(Node root) {
        if (root == null)
            return;

        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);

        while (!queue.isEmpty()){
            Node curr = queue.remove();

            if (curr != null){
                System.out.println(curr.length + " " + curr.robots);

                queue.add(curr.left);
                queue.add(curr.right);
            }
        }

    }

    private static void printRoad(Node root){
        ArrayList<String> allRoadsList = new ArrayList<>();

        if (root == null){
            return;
        }
        getAllPaths(root, allRoadsList, "");

        System.out.println(allRoadsList);
    }

    private static void getAllPaths(Node root, ArrayList<String> roads, String path){
        if (root.left == null && root.right == null){
            roads.add(path);
        }
        if (root.left != null){
            getAllPaths(root.left, roads, path + " X " );
        }
        if (root.right != null){
            getAllPaths(root.right, roads, path + " _ ");
        }
    }



}

class Node {
    Node left;
    Node right;
    int length;
    int robots;

    Node(int length, int robots) {
        this.length = length;
        this.robots = robots;
        left = null;
        right = null;
    }
}
