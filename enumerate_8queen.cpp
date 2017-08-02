#include<iostream>
#include<cmath>
using namespace std;


int x = 0;      //计数（一共有多少种符合条件的排序）

//此函数作用：调用次函数的行的“皇后”的位置与此行之前的“皇后”是否在同一列或者同一个斜线，不在同一列也不在同一斜线返回true，否则返回false
bool valid(int row, int pos[]) {			

	for (int i = 0; i < row; ++i)
		if (pos[row] == pos[i] || abs(row - i) == abs(pos[row] - pos[i]))
			return false;
	return true;
}
int main() {

	int pos[8];
	for (pos[0] = 0; pos[0] < 8; ++pos[0])		//pos[0]=n代表第一个皇后的位置为第一行第n+1列		
		for (pos[1] = 0; pos[1] < 8; ++pos[1]) {	//第一个皇后位置确定，之后的皇后在与前边的皇后位置在符合条件的情况下选择列			
			if (!valid(1, pos))			//这个符合条件的情况就由valid(int row, int pos[])函数确定					
				continue;			//valid(int row, int pos[])返回值为false时，不符合条件，执行continue，
			for (pos[2] = 0; pos[2] < 8; ++pos[2]) {	//执行for语句，皇后所在列再加一，继续调用	valid(int row, int pos[])	
				if (!valid(2, pos))			//直到函数返回值为true,跳出本行的for循环，进入下一行的for循环，确定下一个皇后的位置						
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

