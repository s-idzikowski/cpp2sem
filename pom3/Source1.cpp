#include<iostream>
#include<vector>

using namespace std;

vector<double> suma(vector<double> t1, vector<double> t2);

int n;
int k;

int main() {

	vector<double> t1;
	cout << "podaj liczbe elementow w kontenerze 1: " << endl;
	cin >> n;

	cout << "Podaj elementy kontenera 1: " << endl;
	for (int i = 0; i < n; ++i)
	{
		t1.push_back(i);
		cin >> t1[i];

	}

	vector<double> t2;
	cout << "Podaj liczbe elementow w kontenerze 2: " << endl;
	cin >> k;

	cout << "Podaj elementy kontenera 2: " << endl;
	for (int i = 0; i < k; i++)
	{
		t2.push_back(i);
		cin >> t2[i];
	}

	suma; {
		if (n == k) {
			cout << "Oto ciag  " << endl;
			for (int i = 0; i < t1.size(); i++)
			{
				cout << t1[i] + t2[i] << " ";
				cout << endl;
			}
			cout << " ok " << endl;
		}
		else if (n < k) {
			cout << "Oto ciag  " << endl;
			for (int i = 0; i < t1.size(); i++)
			{
				cout << t2[i] + t1[i] << " ";
				cout << endl;
			}
			cout << " i pozostale elementy " << endl;
			for (int i = n; i < t2.size(); i++)
			{
				cout << t2[i] << " ";
				cout << endl;
			}

		}
		else if (n > k) {
			cout << "Oto ciag  " << endl;
			for (int i = 0; i < t2.size(); i++)
			{
				cout << t1[i] + t2[i] << " ";
				cout << endl;
			}
			cout << " i pozostale elementy " << endl;
			for (int i = k; i < t1.size(); i++)
			{
				cout << t1[i] << " ";
				cout << endl;
			}




		}

	}
}