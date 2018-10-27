/* Jacob Leuquire
 * Project1Main.cpp
 * Project 1, COSC 2030
 * October 2018
 * Takes user input for storing blood sugar data in arrays of linked lists, and performing functions on the data to find 
 * sum, max, min, count, and deltas.
 */



#include "LinkedList.h"
#include <string>
//#include <utility>

using std::cin;
using std::string;

string input;
int i;
float data;

int main()
{
	//Initialize the day array
	List dayArray[14];
	for (int index = 0; index < 14; index++) 
	{
		dayArray[index] = List();
	}
	
	while (input != "Q")
	{
		//Section to list options for user
		cout << "\nWhat would you like to do? Please enter:\n	'I' for inserting data,\n	'D' for the daily summary,\n	"
				"'W' for the weekly summary,\n	'P' to print the stored values,\n	'Q' to quit." << endl;
		cin >> input;
		//Section for inserting data
		if (input == "I")
		{
			string in = "";
			i = 1;
			cout << "Please input blood sugar values. Enter 'N' to advance the day and enter 'Q' when you're done." << endl;
			while (1)
			{
				if (i > 14)
				{
					cout << "Only storing data for 14 days, starting over." << endl;
					i = 1;
				}
				cout << "Day " << i << endl;
				cin >> in;
				if (in == "N")
				{
					i++;
				}
				else if (in != "Q" && in != "N")
				{
					data = strtof(in.c_str(), NULL);
					if (data > 0)
					{
						dayArray[i - 1].insertAsLast(data);
					}
				}
				else if (in == "Q")
				{
					break;
				}
			}
		}
		//Section for daily summary
		else if (input == "D")
		{
			//Sum
			double sum[14];
			cout << "\nSum per Day" << endl;
			for (i = 0; i < 14; i++)
			{
				sum[i] = dayArray[i].sum();
				if (sum[i] > 0)
				{
					cout << "Day " << i + 1 << ": " << sum[i] << endl;
				}
				else
				{
					cout << "Day " << i + 1 << ": " << "No data yet" << endl;
				}
			}
			//Max
			double max[14];
			cout << "\nMax per Day" << endl;
			for (i = 0; i < 14; i++)
			{
				max[i] = dayArray[i].max();
				if (max[i] > 0)
				{
					cout << "Day " << i + 1 << ": " << max[i] << endl;
				}
				else
				{
					cout << "Day " << i + 1 << ": " << "No data yet" << endl;
				}
			}
			//Min
			double min[14];
			cout << "\nMin per Day" << endl;
			for (i = 0; i < 14; i++)
			{
				min[i] = dayArray[i].min();
				if (min[i] < INT_MAX)
				{
					cout << "Day " << i + 1 << ": " << min[i] << endl;
				}
				else
				{
					cout << "Day " << i + 1 << ": " << "No data yet" << endl;
				}
			}
			//Count
			int count[14];
			cout << "\nCount per Day" << endl;
			for (i = 0; i < 14; i++)
			{
				count[i] = dayArray[i].size();
				if (count[i] != 0)
				{
					cout << "Day " << i + 1 << ": " << count[i] << endl;
				}
				else
				{
					cout << "Day " << i + 1 << ": " << "No data yet" << endl;
				}
			}
		}
		/*Section for weekly summary ---- 
		* Note that this section could be made simpler with a lot of reformatting, but since it is only two weeks,
		* I figure this less efficient format of doubling everything is fine.
		*/
		else if (input == "W")
		{
			//Sum
			double sum = 0;
			for (i = 0; i < 7; i++)
			{
				sum = sum + dayArray[i].sum();
			}
			double sum2 = 0;
			for (i = 7; i < 14; i++)
			{
				sum2 = sum2 + dayArray[i].sum();
			}
			//Max
			double max = 0;
			double placehold = 0;
			for (i = 0; i < 7; i++)
			{
				placehold = dayArray[i].max();
				if (placehold > max)
				{
					max = placehold;
				}
			}
			double max2 = 0;
			double placehold2 = 0;
			for (i = 7; i < 14; i++)
			{
				placehold2 = dayArray[i].max();
				if (placehold2 > max2)
				{
					max2 = placehold2;
				}
			}
			//Min
			double min = INT_MAX;
			double holder = 0;
			for (i = 0; i < 7; i++)
			{
				holder = dayArray[i].min();
				if (holder < min)
				{
					min = holder;
				}
			}
			double min2 = INT_MAX;
			double holder2 = 0;
			for (i = 7; i < 14; i++)
			{
				holder2 = dayArray[i].min();
				if (holder2 < min2)
				{
					min2 = holder2;
				}
			}
			//Count
			int count = 0;
			for (i = 0; i < 7; i++)
			{
				count = count + dayArray[i].size();
			}
			int count2 = 0;
			for (i = 7; i < 14; i++)
			{
				count2 = count2 + dayArray[i].size();
			}
			//Delta
			int countx[7];
			int countxMinOne[7];
			int hold = 0;
			int day = 0;
			int maximum = 0;
			for (i = 7; i > 0; i--)
			{
				countx[7-i] = dayArray[i].size();
				countxMinOne[7-i] = dayArray[i - 1].size();
			}
			for (int num = 0; num < 7; num++)
			{
				hold = countx[num] - countxMinOne[num];
				if (hold > maximum)
				{
					maximum = hold;
					day = num + 1;
				}
			}
			int countx2[7];
			int countxMinOne2[7];
			int hold2 = 0;
			int day2 = 0;
			int maximum2 = 0;
			for (i = 13; i > 6; i--)
			{
				countx2[13-i] = dayArray[i].size();
				countxMinOne2[13-i] = dayArray[i - 1].size();
			}
			for (int num = 0; num < 7; num++)
			{
				hold2 = countx2[num] - countxMinOne2[num];
				if (hold2 > maximum2)
				{
					maximum2 = hold2;
					day2 = num + 8;
				}
			}
			cout << "Week 1 Sum: " << sum << endl;
			cout << "Week 2 Sum: " << sum2 << endl;
			cout << "Week 1 Max: " << max << endl;
			cout << "Week 2 Max: " << max2 << endl;
			cout << "Week 1 Min: " << min << endl;
			cout << "Week 2 Min: " << min2 << endl;
			cout << "Week 1 Count: " << count << endl;
			cout << "Week 2 Count: " << count2 << endl;
			cout << "Week 1 Largest Delta: " << day << endl;
			cout << "Week 2 Largest Delta: " << day2 << endl;
		}
		//Section for printing data values
		else if (input == "P")
		{
			for (i = 0; i < 14; i++)
			{
				cout << "Day " << i + 1 << ": " << dayArray[i] << endl;
			}
		}
	}
	cout << "\nDone" << endl;
	system("pause");
	return 0;
}
