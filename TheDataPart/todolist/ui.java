/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author spide
 */

import java.util.Scanner;


public class UserInterface {
    
    
    private Scanner scan;
    private TodoList list;
    
    
    public UserInterface(TodoList list, Scanner scan)
    {
        this.scan = scan;
        this.list = list;
    }
    
    public void start()
    {
        
        while(true)
        {
            System.out.println("Command: ");
            String command;
            command = scan.nextLine();
            if(command.equals("stop"))
            {
                break;
            }
            else if(command.equals("add"))
            {
                System.out.println("To add: ");
                String in = scan.nextLine();
                this.list.add(in);
            }
            else if(command.equals("list"))
            {
                this.list.print();
            }
            else if(command.equals("remove"))
            {
                System.out.println("Which one is removed? ");
                int in = Integer.valueOf(scan.nextLine());
                this.list.remove(in - 1);
            }
            
        }
    }
    
}
