/*
<Procedure>
1. max_h ~ min_h 범위의 높이 h
2. for(h), 높이 h(key 변수)로 맞출때 시간(cost) 비교 : 
	(높아질 블럭 수) cost + (낮아질 블럭 수 * 2) cost
	그러나 만약 가진 블럭수(B)가 받춰주지 않으면 탈락 
3. 가장 빠른 case로 실행!
	**만약 cost 같을 시 가장 높은 h	
*/

#include <iostream>
#include <climits>

using namespace std;

struct block
{
	short row = 0;
	short col = 0;
	int h = 0;
};

class Minecraft
{
public:
	Minecraft()
	{
		cin >> N_ >> M_ >> B_;
		size_ = N_ * M_;

		ground_ = new block[N_ * M_];
		for (int r = 0; r < N_; r++)
		{
			for (int c = 0; c < M_; c++)
			{
				int temp;
				ground_[r * M_ + c].row = r;
				ground_[r * M_ + c].col = c;
				cin >> temp;
				ground_[r * M_ + c].h = temp;
				// 최대 높이 블록 정보 저장
				if (max_h < temp) max_h = temp;
				if (min_h > temp) min_h = temp;
			}
		}
	}

	// 무조건 max나 min으로 맞추지 않음. '적당한 중간값'
	void calculate()
	{
		// scope = max_h - min_h;
		int answer_h = 0;
		int cost = INT_MAX;

		for (int h = min_h; h <= max_h; h++)
		{
			int temp_cost = 0;
			int have_B = B_;
			for (int i = 0; i < size_; i++)
			{
				int diff = ground_[i].h - h;
				if (diff > 0) // remove
				{
					temp_cost += diff * 2;
					have_B += diff;
				}
				else if (diff < 0) // add
				{
					temp_cost -= diff;
					have_B += diff;
				}
			}

			if (have_B < 0) continue;

			if (temp_cost < cost)
			{
				cost = temp_cost;
				answer_h = h;
			}
			else if (temp_cost == cost && answer_h < h)
				answer_h = h;
		}

		cout << cost << ' ' << answer_h << endl;
	}

private:
	int N_;
	int M_;
	int size_;
	int B_;
	int max_h = 0;
	int min_h = 256;
	block* ground_;
};

int main()
{
	Minecraft mine;
	mine.calculate();
	return 0;
}
