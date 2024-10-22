// Problem: Closest Pair on the plane
// Description
// Cho N điểm trên mặt phẳng, hãy tìm một cặp điểm với khoảng cách euclid nhỏ nhất giữa chúng. Biết rằng không có hai điểm nào trùng nhau và có duy nhất một cặt có khoảng cách nhỏ nhất.

// Input
// Dòng đầu tiên chứa một số nguyên N (2 <= N <= 100000). 
// N dòng tiếp theo mỗi dòng chứa hai số nguyên là tọa độ X và Y của một điểm (Giá trị tuyệt đối của X, Y không vượt quá 10^6).

// Output
// Ghi ra c là khoảng cách giữa chúng, làm tròn c đến 6 chữ số sau dấu phẩy động.

// Example
// Input 
// 5
// 0 0
// 1 1
// 100 45
// 2 3
// 9 9

// Output
// 1.414214

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
const int INF = 1e9;

int p1, p2;
double res;

struct point{
	long long x, y;
	int id;
};

point a[MAX];

bool cmpX(point a, point b){
	return a.x < b.x;
}

bool cmpY(point a, point b){
	return a.y < b.y;
}

double dist(point a, point b){
	return sqrt((double)(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void update(point a, point b){
	double x = dist(a, b);
	if (x < res) {
		res = x;
		p1 = a.id;
		p2 = b.id;
	}
}

void closest(int l, int r){
	if (l >= r) return;
	if (l + 1 == r) {
		update(a[l], a[r]);
		return;
	}

	int mid = (l + r) / 2;
	int mid_x = a[mid].x;

	closest(l, mid);
	closest(mid + 1, r);

	vector<point> vt;
	for (int i = l; i <= r; i++){
		if (abs(a[i].x - mid_x) <= res) {
			vt.push_back(a[i]);
		}
	}

	sort(vt.begin(), vt.end(), cmpY);

	double temp = res;
	for (int i = 0; i < vt.size(); i++){
		int j = i + 1;
		while(j < vt.size() && vt[j].y - vt[i].y <= temp){
			update(vt[i], vt[j]);
			j++;
		}
	}
}

int main(int argc, const char** argv) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}

	sort(a, a + n, cmpX);
	res = INF;
	
	closest(0, n - 1);
	cout << fixed << setprecision(6) << res;

	return 0;
}