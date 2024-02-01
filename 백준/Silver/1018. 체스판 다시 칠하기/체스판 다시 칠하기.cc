#include <iostream>

using namespace std;

class ChessBoard
{
public:
	ChessBoard()
	{
		// Row, Column 수 입력
		cin >> R >> C;

		// 테스트 판 생성
		board = new char[R * C];
	}

	void getBoard()
	{
		// 테스트 판 입력
		for (int i = 0; i < R * C; i++)
			cin >> board[i];
	}

	// 색칠 횟수 경우의 수 중 최솟값 출력
	void printMin()
	{
		getBoard();

		// 8 x 8 커팅 경우의 수
		int min = R * C;
		for (int r0 = 0; r0 <= R - 8; r0++)
			for (int c0 = 0; c0 <= C - 8; c0++)
			{
				int temp = minDiff(r0, c0);
				if (min > temp) min = temp;
			}

		cout << min;
	}

	// 샘플(WB, BW)과 몇 개 다른지, 그 중 작은거 반환
	int minDiff(int r0, int c0)
	{
		int diffWB = 0;
		int diffBW = 0;

		for (int r = 0; r < 8; r++)
			for (int c = 0; c < 8; c++)
			{
				int rr = r + r0;
				int cc = c + c0;
				int ii = cc + rr * C;
				int i = c + r * 8;
				if (board[ii] != WB[i]) ++diffWB;
				if (board[ii] != BW[i]) ++diffBW;
			}

		return min(diffWB, diffBW);
	}

private:
	int R;
	int C;
	char WB[64] = { 'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W' 
	};
	char BW[64] = {
		'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B'
	};
	char* board = nullptr;
};


int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	ChessBoard board1;
	board1.printMin();

	return 0;
}