/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author spide
 */

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class UserInterface {
    
    private Scanner scan;
    private JokeManager list;
    
    public UserInterface(JokeManager joke, Scanner scanner)
    {
        this.list = joke;
        this.scan = scanner;
    }
    
    public void start()
    {
        while(true)
        {
            System.out.println("Commands:");
            System.out.println("1 - add a joke");
            System.out.println("2 - draw a joke");
            System.out.println("3 - list jokes");
            System.out.println("X - stop");
            String word = this.scan.nextLine();
            if(word.equals("1"))
            {
                System.out.println("Write a joke to be added:");
                String joke = this.scan.nextLine();
                list.addJoke(joke);
            }
            if(word.equals("2"))
            {
                System.out.println("Drawing joke.");
                String wow = this.list.drawJoke();
                System.out.println(wow);
            }
            if(word.equals("3"))
            {
                System.out.println("Printing the jokes.");
                this.list.printJokes();
            }
            if(word.equals("X"))
            {
                break;
            }
            
        }
    }
}
