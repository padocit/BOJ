# 정렬, 그리고 중복X

문제의 조건
- 정렬한다.
- 중복 없다.

보자마자 `std::set` 으로 접근했다.

## set, 그리고 struct

좌표를 보자마자 `struct point2D`를 만들었다.

- 지난번 **기본 자료형**으로 `std::set`을 사용할 때는 `set<자료형, 정렬조건(구조체)>` 을 통해 set을 선언했다.
- 이번에는 기본 자료형이 아니라 **사용자 정의 자료형 구조체**를 사용한다.

이 때 오히려 더 직관적일수도 있다.

```cpp
struct point2D
{
  int x;
  int y;

  bool operator< (const point2D& other) const
  {
    비교조건
  }
}
```

위 코드처럼 set에서 사용할 구조체를 정의하고, 그 안에 연산자 오버로딩을 해주면 된다!

- `set<point2D> myset;` 이렇게 set을 선언해주면 충분해진다! 
