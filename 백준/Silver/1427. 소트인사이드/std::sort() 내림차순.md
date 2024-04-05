# std::sort()

C++ STL <algorithm>에 있는 `std::sort()`
- 기본적으로 오름차순.
- 하지만 내림차순으로 사용 가능.

## std::sort() 내림차순

_`sort()`에는 인자 값을 2개 또는 3개 줄 수 있다._
- iterator first, iterator last
- iterator first, iterator last, Compare

Compare parameter에는 default값으로 `less<>` 객체가 들어가있다.
- 그렇기 때문에 기본적으로 '오름차순'을 하게 된다.
- 따라서 이 Compare parameter에 '내림차순'을 위한 값을 넣으면 된다.

  **1. 사용자 정의 함수를 콜백하도록 만들기**
  ```cpp
  bool cmp(int i, int j)
  {
    return i > j;
  }
  
  int main()
  {
    // 중략
    sort(v.begin(), v.end(), cmp);
  }
  ```
  
  **2. greater<> 임시 객체 콜**
  ```cpp
  int main()
  {
    // 중략
    sort(v.begin(), v.end(), greater<>());
  }
  ```
    `greater<>`? 
    - STL utility에 정의되어 있는 클래스.
    - 이름에서 유추할 수 있듯 `less<>`와 반대.
