#include<iostream>
#include<cmath>
using namespace std;


int x = 0;   
bool valid(int row, int pos[]) {

	for (int i = 0; i < row; ++i)
		if (pos[row] == pos[i] || abs(row - i) == abs(pos[row] - pos[i]))
			return false;
	return true;
}
int main() {

	int pos[8];
	for (pos[0] = 0; pos[0] < 8; ++pos[0])				
		for (pos[1] = 0; pos[1] < 8; ++pos[1]) {			
			if (!valid(1, pos))								
				continue;
			for (pos[2] = 0; pos[2] < 8; ++pos[2]) {			
				if (!valid(2, pos))									
					continue;											
				for (pos[3] = 0; pos[3] < 8; ++pos[3]) {
					if (!valid(3, pos))
						continue;
					for (pos[4] = 0; pos[4] < 8; ++pos[4]) {
						if (!valid(4, pos))
							continue;
						for (pos[5] = 0; pos[5] < 8; ++pos[5]) {
							if (!valid(5, pos))
								continue;
							for (pos[6] = 0; pos[6] < 8; ++pos[6]) {
								if (!valid(6, pos))
									continue;
								for (pos[7] = 0; pos[7] < 8; ++pos[7]) {
									if (!valid(7, pos))
										continue;
									for (int i = 0; i < 8; ++i)
										cout << " " << pos[i];
									cout << endl;
									x += 1;
								}
							}
						}
					}
				}
			}

		}

	cout << endl << x << endl;  

	return 0;

}

