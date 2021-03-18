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

public class TextUI {
    
    private Scanner kbdy;
    private SimpleDictionary dic;
    
    public TextUI(Scanner kbd, SimpleDictionary dic)
    {
        this.kbdy = kbd;
        this.dic = dic;
    }
    
    public void start()
    {
        System.out.println("Command:");
        String command = "";
        while(true)
        {
            
            command = kbdy.nextLine();
            if(command.equals("end"))
            {
                System.out.println("Bye bye!");
                break;
            }
            else if (command.equals("add"))
            {
                String word;
                String trans;
                System.out.println("Word:");
                word = kbdy.nextLine();
                System.out.println("Translation:");
                trans = kbdy.nextLine();
                this.dic.add(word, trans);
                
                
            }
            else if(command.equals("search"))
            {
                
                String search;
                String found;
                System.out.println("To be translated:");
                search = kbdy.nextLine();
                found = this.dic.translate(search);
                if(found == null)
                {
                    System.out.println("Word " + search + " was not found");
                }
                else
                {
                    System.out.println("Translation: " + found);
                }
                
                
            }
            else 
            {
                System.out.println("Unknown command");
                
            }
            System.out.println("Command:");
        }
        
    }
    
}
