#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void zd1() {

	int m, n, buf;
	cout << "Enter m and n : ";

	cin >> m >> n;

	vector< vector<int> > A(m, vector<int>(n));

	cout << "Enter elements matrix : " << endl;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	int max = -1e8, min = 1e8, ma_ind, mi_ind;
	for (int i = 0; i < m; i++) {

		max = -1e8, min = 1e8;

		for (int j = 0; j < n; j++) {

			if (A[i][j] >= max) {
				max = A[i][j];
				ma_ind = j;
			}

			if (A[i][j] <= min) {

				min = A[i][j];
				mi_ind = j;

			}

		}

		if (ma_ind != mi_ind) {

			A[i][ma_ind] = min;
			A[i][mi_ind] = max;

		}

	}

	cout << "Matrix : ";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	return;

}

void zd2() {

	int m, n, buf;
	cout << "Enter m and n : ";

	cin >> m >> n;

	vector< vector<int> > A(m, vector<int>(n));
	vector<int> Buf;

	cout << "Enter elements matrix : " << endl;

	int max = -1e8, min = 1e8;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];

			if (A[i][j] > max) {
				max = A[i][j];
			}

			if (A[i][j] < min)
				min = A[i][j];
		}

	}


	for (int j = 0; j < n; j++) {

		int fl = 0;

		for (int i = 0; i < m; i++) {

			if (A[i][j] == max) {
				fl = 1;
			}

		}

		if (fl == 0)
			continue;

		for (int i = 0; i < m; i++) {

			if (A[i][j] == min) {
				fl = 2;
			}

		}

		if (fl == 2) {
			Buf.push_back(j);
		}

	}

	if (Buf.size() % 2 == 0) {

		for (int g = 0; g < Buf.size(); g += 2) {

			for (int i = 0; i < m; i++) {

				swap(A[i][Buf[g]], A[i][Buf[g + 1]]);

			}

		}

	}
	else {

		for (int g = 0; g < Buf.size() - 1; g += 2) {

			for (int i = 0; i < m; i++) {

				swap(A[i][Buf[g]], A[i][Buf[g + 1]]);

			}

		}

		for (int i = 0; i < m; i++) {

			swap(A[i][Buf[0]], A[i][Buf[Buf.size() - 1]]);

		}

	}

	cout << "Matrix : " << endl;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}


	return;

}

void zd3() {

	int m, n;

	cout << "Enter m and n : ";

	cin >> m >> n;

	vector< vector<int> > A(m, vector<int>(n));

	cout << "Enter matrix : " << "\n";

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	int og1 = m / 2, og2 = n / 2 , k1 = m / 2 , k2 = n / 2;


	for (int i = 0; i < og1; i++) {

		for (int j = 0; j < og2; j++) {

			swap(A[i][j], A[i + k1][j + k2]);

		}

	}

	cout << "New matrix : " << "\n";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
		


}

void zd4() {

	int m, n;
	cout << "Enter m and n : ";

	cin >> m >> n;

	vector< vector<int> > A(m, vector<int>(n));

	cout << "Enter elements matrix : " << endl;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	vector<pair<int, int> > G;

	for (int j = 0; j < n; j++) {

		G.push_back(make_pair(A[0][j], j));

	}

	sort(G.begin(), G.end());

	vector< vector<int> > Ans(m, vector<int>(n, 0));

	for (int g = 0; g < G.size(); g++) {

		for (int i = 0; i < m; i++) {

			Ans[i][g] = A[i][G[g].second];

		}

	}

	cout << "Matrix : " << "\n";

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++)
			cout << Ans[i][j] << " ";
		cout << "\n";
	}

	return;
}

void zd5() {

	int m;

	cout << "Enter m : ";

	cin >> m;

	vector< vector<int> > A(m, vector<int>(m));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	
	if (m == 1) {
		cout << A[0][0];
		return;
	}

	int sum = 0 , id1 = m - 1 , id2 = 0 , i1 , i2;

	bool fl = true;

	while (id1 >= 0 || id2 != m - 1) {

		if (fl) {

			i1 = id1 , i2 = id2;

			while (i1 >= 0 && i2 >= 0) {
				sum += A[i1][i2];
				i1--;
				i2--;
			}

			id2++;

			if (id1 == m - 1 && id2 == m - 1) {

				fl = false;
				id1--;

			}

		}
		else {

			i1 = id1, i2 = id2;

			while (i1 >= 0 && i2 >= 0) {
				sum += A[i1][i2];
				i1--;
				i2--;
			}

			id1--;

		}

	}
	
	cout << sum;

}

int main() {

	int t;

	while (true) {

		cout << "Enter number job or zero for exit : ";
		cin >> t;

		switch (t)
		{

		case 1: {
			zd1();
			break;
		}
		case 2: {
			zd2();
			break;
		}
		case 3: {
			zd3();
			break;
		}
		case 4: {
			zd4();
			break;
		}
		case 5: {
			zd5();
			break;
		}
		case 0: {
			cout << "Exit";
			return 0;
		}

		default:
			break;
		}

	}

	return 0;
}