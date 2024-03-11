#include <iostream>
#include <vector>

using namespace std;

class Fibonacci
{
public:
    struct fibo
    {
        int sum0 = 0;
        int sum1 = 0;

        fibo operator + (fibo op)
        {
            return fibo({ this->sum0 + op.sum0, this->sum1 + op.sum1 });
        }
    };

    Fibonacci()
    {
        for (int i = 0; i <= 40; i++)
        {
            if (i == 0)
                count.push_back({ 1, 0 });
            else if (i == 1)
                count.push_back({ 0, 1 });
            else
            {
                count.push_back(count[i - 2] + count[i - 1]);
            }
        }
    }

    void print(int N)
    {
        cout << count[N].sum0 << ' ' << count[N].sum1 << '\n';
    }

private:
    vector<fibo> count;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    Fibonacci fib;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        fib.print(N);
    }

	return 0;
}