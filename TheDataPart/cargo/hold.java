import java.util.ArrayList;
public class Hold {
    
    private int max;
    private ArrayList<Suitcase> List;
    
    public Hold(int max)
    {
        
        this.max = max;
        this.List = new ArrayList<>();
    }
    
    public void addSuitcase(Suitcase suitcase)
    {
        int total = 0;
        for(int i = 0; i < this.List.size(); i++)
        {
            total += this.List.get(i).totalWeight();
        }
        if(!(total + suitcase.totalWeight() > max))
        {
            this.List.add(suitcase);
        }
        
    }
    
    public void printItems()
    {
        
        for(int i = 0; i < this.List.size(); i++)
        {
           this.List.get(i).printItems();
        }
    }
    
    @Override
    public String toString()
    {
        int total = 0;
        for(int i = 0; i < this.List.size(); i++)
        {
            total += this.List.get(i).totalWeight();
        }
        return this.List.size() + " suitcases (" + total + " kg)";
    }
}
