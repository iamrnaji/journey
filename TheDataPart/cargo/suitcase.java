import java.util.ArrayList;

public class Suitcase {
    
    private ArrayList<Item> List;
    private int maxW;
    
    public Suitcase(int max)
    {
        this.maxW = max;
        this.List = new ArrayList<>();
    }
    
    public void addItem(Item item)
    {
        int currentW = this.totalWeight();
        
        if(!(currentW + item.getWeight() > maxW))
        {
            this.List.add(item);
        }
        
    }
    
    public void printItems()
    {
        for(int i = 0; i < this.List.size(); i++)
        {
            System.out.println(this.List.get(i).getName() + " (" + this.List.get(i).getWeight() + " kg)");
        }
    }
    
    public int totalWeight()
    {
        int currentW = 0;
        for(int i = 0; i < this.List.size(); i++)
        {
            currentW += this.List.get(i).getWeight();
        }
        
        return currentW;
    }
    
    public Item heaviestItem()
    {
        
        if(this.List.isEmpty())
        {
            return null;
        }
        int heavy = 0;
        int count = 0;
        for(int i =0; i < this.List.size(); i++)
        {
            if(heavy < this.List.get(i).getWeight())
            {
                heavy = this.List.get(i).getWeight();
                count = i;
            }
        }
        
        return this.List.get(count);
    }
    
    @Override
    public String toString()
    {
        if(this.List.isEmpty())
        {
            return "no items (0 kg)";
        }
     
        int currentW = this.totalWeight();
        
        if (this.List.size() == 1)
        {
            return this.List.size() + " item (" + currentW + " kg)";
        }
        else
        {
            return this.List.size() + " items (" + currentW + " kg)";
        }
    }
}
