package hw;

import java.util.Scanner;

public class main {

    public static void main(String[] args) {
    
        
        Scanner kbd = new Scanner(System.in);
    
    
        Store North = new Store();
        Store South = new Store();
        Store West = new Store();
        Store East = new Store();
        
        while(true)
        {
            int item = 0;
            int add = 0;
            int store = 0;
            System.out.println("Which store would you like to edit? (-1 to break)");
            System.out.println("North = 0, East = 1, South = 2, West = 3");
            store = Integer.valueOf(kbd.nextLine());
            if(store == -1)
            {
                break;
            }
            System.out.println("Which item would you like to add?");
            System.out.println("0 = 500MB SSD drives, 1 = 1TB SSD drives, 2 = Intel Motherboards, 3 = AMD Motherboards");
            System.out.println("4 = Intel CPU Chips, 5 = AMD CPU Chips, 6 = 16GB Memory Chips, 7 = 32GB Memory Chips");
            item = Integer.valueOf(kbd.nextLine());
            System.out.println("How many would you like to add?");
            add = Integer.valueOf(kbd.nextLine());
            if(store == 0)
            {
                North.add(item,  add);
            }
            else if(store == 1)
            {
                East.add(item,  add);
            }
            else if(store == 2)
            {
                South.add(item,  add);
            }
            else if(store == 3)
            {
                West.add(item,  add);
            }
        }
        kbd.close();
        
        System.out.println("North: ");
        North.displayData();
        
        System.out.println("East: ");
        East.displayData();
        
        System.out.println("South: ");
        South.displayData();
        
        System.out.println("West: ");
        West.displayData();

    }
}
