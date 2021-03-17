public class Item {
    
    private int weight;
    private String name;
    public Item(String n, int w)
    {
        this.weight = w;
        this.name = n;
    }
    
    public String getName()
    {
        return this.name;
    }
    
    public int getWeight()
    {
        return this.weight;
    }
    
    @Override
    public String toString()
    {
       return this.name + " (" + this.weight + " kg)" ;
    }  
}
