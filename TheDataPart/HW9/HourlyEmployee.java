
public class HourlyEmployee extends Employee {
	
	private int weeklyHours;
	private double hourlyRate;
	private double overtimeRate;

	public HourlyEmployee()
	{
		this.hourlyRate = 12.44;
		overtimeRate = 1.5 * hourlyRate;
	}
	
	public int getWeeklyHours()
	{
		return weeklyHours;
	}
	
	public double getPayRate()
	{
		return hourlyRate;
	}
	
	public void setWeeklyHours(int weeklyHours)
	{
		this.weeklyHours = weeklyHours;
	}
	
	public void setPayRate(double payRate)
	{
		this.hourlyRate = payRate;
	}
	
	public double weeklyPay()
	{
		if(this.weeklyHours > 100 || this.weeklyHours < 0)
		{
			return -1;
		}
		
		else if(this.weeklyHours < 40)
		{
			return this.hourlyRate * this.weeklyHours;
		}
		else
		{
			return (this.overtimeRate * (this.weeklyHours - 40)) + this.weeklyHours * 40;
		}
	}
}
