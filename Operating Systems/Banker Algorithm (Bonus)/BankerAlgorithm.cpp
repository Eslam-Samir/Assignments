#include <iostream>
#include <vector>

using namespace std;

int m, n; // number or resources, number of processes

void calcNeed(vector<vector<int>> & need, vector<vector<int>> & max, vector<vector<int>> & allocation)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			need[i].push_back(max[i][j] - allocation[i][j]);
		}
	}
}

bool bankerAlgorithm(vector<vector<int>> & need, vector<vector<int>> & allocation, vector<int> & work, vector<bool> & finish)
{
	while(true)
	{
		bool end = true, flag = false;
		for(int i = 0; i < n; i++)
		{
			bool executable = true;
			if(finish[i])
				continue;
			end = false;
			for(int j = 0; j < m; j++)
			{
				if(need[i][j] > work[j])
				{
					executable = false;
					break;
				}
			}
			if(executable)
			{
				flag = true;
				for(int j = 0; j < m; j++)
				{
					work[j] += allocation[i][j];
				}
				finish[i] = true;
				cout << "P" << i << endl;
			}
		}
		if(end)
		{
			cout << "System is safe" << endl;
			return true;
		}
		else if(!flag)
		{
			cout << "can't continue system is unsafe" << endl;
			return false;
		}
	}
}

bool RequestAlgorithm(vector<int> & request, int requestingProcess, vector<vector<int>> & need, vector<bool> & finish,
					  vector<vector<int>> & max, vector<vector<int>> & allocation, vector<int> & work)
{
	for(int i = 0; i < m; i++)
	{
		if(work[i] < request[i])
			return false;
		else
		{
			work[i] -= request[i];
			allocation[requestingProcess][i] += request[i];
		}
	}
	calcNeed(need, max, allocation);
	bool isSafe;
	isSafe = bankerAlgorithm(need, allocation, work, finish);
	if(isSafe)
	{
		cout << "The request can be granted" << endl;
	}
	else
	{
		cout << "The request can't be granted" << endl;
	}
	return isSafe;
}

void main()
{
	cout << "Enter number of resources" << endl;
	cin >> m;
	vector<int> work(m);
	vector<int> available(m);

	int tmp;
	cout << "Enter Available Resources" << endl;
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		available[i] = tmp;
	}

	cout << "Enter number of processes" << endl;
	cin >> n;

	vector<bool> finish(n);

	for(int i = 0; i < n; i++)
	{
		finish[i] = false;
	}

	vector< vector<int> > max(n);

	vector< vector<int> > allocation(n);

	for(int i = 0; i < n; i++)
	{
		cout << "Enter the max resources of processes P" << i << endl;
		for(int j = 0; j < m; j++)
		{
			cin >> tmp;
			max[i].push_back(tmp);
		}

		cout << "Enter the allocated resources to processes P" << i << endl;
		for(int j = 0; j < m; j++)
		{
			cin >> tmp;
			allocation[i].push_back(tmp);
		}
	}

	vector< vector<int> > need(n);
	
	calcNeed(need, max, allocation);

	for(int i = 0; i < m; i++)
	{
		work[i] = available[i];
	}

	bankerAlgorithm(need, allocation, work, finish);

	for(int i = 0; i < n; i++)
	{
		finish[i] = false;
	}
	for(int i = 0; i < m; i++)
	{
		work[i] = available[i];
	}


	cout << "\nDo you want a process to request (enter 1 for yes, enter 2 for no)" << endl;
	cin >> tmp;
	if(tmp == 1)
	{
		vector<int> request(m);

		cout << "Enter the requesting process number (Ex. 0 for P0, 1 for P1...etc)" << endl;
		int requesting;
		cin >> requesting;

		cout << "Enter the requested resources" << endl << endl;
		for(int i = 0; i < m; i++)
		{
			cin >> tmp;
			request[i] = tmp;
		}

		RequestAlgorithm(request, requesting, need, finish, max, allocation, work);
	}

	system("pause");
}