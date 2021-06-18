
#include <iostream>
#include <vector>



// CAN ÖZLEMÝÞ - 170997
// CAN ÖZLEMÝÞ - 170997
// CAN ÖZLEMÝÞ - 170997
// CAN ÖZLEMÝÞ - 170997
// CAN ÖZLEMÝÞ - 170997


int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}


void m(std::vector <std::vector <int> > KS, std::vector<int> W, std::vector<int> V, int c, int n) {
	//n = NUMBER OF ITEMS
	//c = CAPACITY
	//w = WEIGHT
	//v = VALUE

	//GOAL, pick the items that we can carry with max ammount of value

	int cap = 0; 
	int set = 0; 

	while (cap != c + 1) {
		if (cap == 0 || set == 0) { //Setting the boundries to 0
			KS[cap][set] = 0;
			set++;
			if (set == n + 1) {
				set = 0;
				cap++;
			}
			continue;
		}

		if (cap - W[set - 1] < 0) {
			KS[cap][set] = KS[cap][set - 1];
		}
		else {
			KS[cap][set] = max(KS[cap][set - 1], KS[cap - W[set - 1]][set - 1] + V[set - 1]) ;
		}
		set++;
		if (set == n + 1) { //If we are at the end of the set, increase cap, reset set
			set = 0;
			cap++;
		}
	}


	//DISPLAY THE MATRIX
	for (int i = 0; i < KS.size(); i++) {
		for (int j = 0; j < KS[i].size(); j++)
			std::cout << KS[i][j] << "\t";
		std::cout << std::endl;
	}

	std::cout << "\n\nMax value = " << KS[c][n] << std::endl;


	//FIND THE SELECTED ITEMS
	int k = c;
	for (int i = n; i > 0; ) {
		if (KS[k][i] != KS[k][i - 1]) {
			std::cout << "Item '" << i << "' is selected with value = " << V[i-1] << "\tweigth = " << W[i-1] << std::endl;
			k -= W[i - 1];
			i--;
		}
		else
			i--;
	}
}



int main() {
	std::vector <int> w = { 1,2,3 };
	std::vector <int> v = { 6,9,18 };
	int C = 4;
	int N = 3;
	std::vector< std::vector <int> > vect(C + 1, std::vector<int>(N + 1));

	m(vect, w, v, C, N);
	return 0;
}
