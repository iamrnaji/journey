
public class Employee {
	
	private String id;
	private String fName;
	private String lName;
	private int yearPay;

	public Employee()
	{
		id = "ID111";
	}
	
	public String getId()
	{
		return this.id;
	}
	
	public void setId(String id)
	{
		this.id = id;
	}
	
	public void setfName(String fName)
	{
		this.fName = fName;
	}
	
	public void setlName(String lName)
	{
		this.lName = lName;
	}
	
	public void setYearPay(int yearPay)
	{
		this.yearPay = yearPay;
	}
}
