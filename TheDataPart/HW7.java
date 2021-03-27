package hw;

import java.util.Arrays;
import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		
		int[][] StoreProd = new int [4][8];
		Scanner kbd = new Scanner(System.in);
		
		int store = 0;
		int item = 0;
		int value = 0;
		
		while(true)
		{
			System.out.println("Which store would you like to edit? (-1 to exit)");
			System.out.println("North = 0, West = 1, South = 2, East = 3");
			store = Integer.valueOf(kbd.nextLine());
			if(store == -1)
			{
				break;
			}
			System.out.println("Which item would you like to edit?");
			System.out.println("0 = 500MB SSD drives, 1 = 1TB SSD drives, 2 = Intel Motherboards, 3 = AMD Motherboards");
			System.out.println("4 = Intel CPU Chips, 5 = AMD CPU Chips, 6 = 16GB Memory Chips, 7 = 32GB Memory Chips");
			item = Integer.valueOf(kbd.nextLine());
			System.out.println("Please enter your value: ");
			value = Integer.valueOf(kbd.nextLine());
			StoreProd[store][item] = value;
			System.out.println("Changed!");
			
		}
		
		
		for(int i = 0; i < 4; i++)
		{
			if(i == 0)
			{
				System.out.println("North store:");
			}
			else if (i == 1)
			{
				System.out.println("East store: ");
			}
			else if (i == 2)
			{
				System.out.println("South store: ");
			}
			else if (i == 3)
			{
				System.out.println("West store: ");
			}
			for(int j = 0; j < 8; j++)
			{
				if(j == 0)
				{
					System.out.println(StoreProd[i][j] + " 500MB SSD drives");
				}
				else if (j == 1)
				{
					System.out.println(StoreProd[i][j] + " 1TB SSD drives");
				}
				else if (j == 2)
				{
					System.out.println(StoreProd[i][j] + " Intel Motherboards");
				}
				else if (j == 3)
				{
					System.out.println(StoreProd[i][j] + " AMD Motherboards");
				}
				else if (j == 4)
				{
					System.out.println(StoreProd[i][j] + " Intel CPU Chips");
				}
				else if (j == 5)
				{
					System.out.println(StoreProd[i][j] + " AMD CPU Chips");
				}
				else if (j == 6)
				{
					System.out.println(StoreProd[i][j] + " 16GB Memory Chips");
				}
				else if (j == 7)
				{
					System.out.println(StoreProd[i][j] + " 32GB Memory Chips");
				}
			}
			
			System.out.println();
		}

	}

}
