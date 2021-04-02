package hw;

import java.util.ArrayList;

public class Store {
    
    ArrayList<Integer> store;
    
    public Store()
    {
        store = new ArrayList<>();
        for(int i = 0; i < 8; i++)
        {
            store.add(0);
        }
    }
    
    public void add(int item, int add)
    {
        store.set(item, store.get(item) + add);
    }
    
    public void displayData()
    {
        System.out.println(store.get(0) + " 500MB SSD drives");
        System.out.println(store.get(1) + " 1TB SSD drives");
        System.out.println(store.get(2) + " Intel Motherboards");
        System.out.println(store.get(3) + " AMD Motherboards");
        System.out.println(store.get(4) + " Intel CPU Chips");
        System.out.println(store.get(5) + " AMD CPU Chips");
        System.out.println(store.get(6) + " 16 GB Memory Chips");
        System.out.println(store.get(7) + " 32 GB Memory Chips");
        
    }
    
}
