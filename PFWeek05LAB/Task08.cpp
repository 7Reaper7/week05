#include<iostream>
#include<cmath>
using namespace std;

float CalFill(int, int, float);
int CalPipeContribution(int, float, float);

main()
{

	system("cls");
	int vol;
	int pipe1, pipe2, pipe1_con_percent, pipe2_con_percent;
	int overflown;
	float pool_filled, pool_filled_percent;
	float hour;

	cout << "Enter the Volume of pool in liters=> ";
	cin >> vol;
	cout << "Enter the Flow rate of Pipe one=> ";
	cin >> pipe1;
	cout << "Enter the Flow rate of Pipe two=> ";
	cin >> pipe2;
	cout << "Enter the amount of Hours absent=> ";
	cin >> hour;
	
	pool_filled = CalFill(pipe1,pipe2,hour);
	pipe1_con_percent = CalPipeContribution(pipe1,pool_filled,hour);
	pipe2_con_percent = CalPipeContribution(pipe2,pool_filled,hour);

	pool_filled_percent = (pool_filled/vol) * 100;
	
	
	if(pool_filled<=vol)
	{
	
		cout << "The pool is " << pool_filled_percent << "% full. "; 
		cout << "Pipe 1: " << pipe1_con_percent << "%. ";
		cout << "Pipe 2: " << pipe2_con_percent << "%.";
	
	}
	if(pool_filled>vol)
	{
		
		overflown = pool_filled - vol;
		cout << "For " << hour << " hours the pool overflows with " << overflown << " liters.";

	}

}

float CalFill(int p1, int p2, float hour)
{

	int total_flow, pool_filled_percent;
	float p_f;

	total_flow = p1 + p2;
	p_f = total_flow * hour;

	return p_f; 

}

int CalPipeContribution(int pipe, float pool_filled, float hour)
{

	int pipe_con, pipe_con_percent;

	pipe_con = pipe * hour;
	pipe_con_percent = (pipe_con / pool_filled) * 100;

	return pipe_con_percent;

}