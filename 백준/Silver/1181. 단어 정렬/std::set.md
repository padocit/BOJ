# set을 알고있니?

## <1> 나의 문제 접근

1. 클래스 배열로 받고, 정렬하자. 그 후 출력하자. -> 중복 요소 삭제가 복잡해짐. (Insertion sort 써볼까 했으나, 성능이 떨어지는 것은 여전히 문제)
2. std::vector를 사용하고, 중복 요소 체크 후 push, 마지막에 sort()로 정렬해볼까? -> 여전히 중복 요소 삭제의 복잡함..
3. `std::set` 이라는 것이 있구나!?

## <2> set 개념

- **중복 요소**는 자동으로 들어가지 않는다.
- 삽입할 때마다 **자동 오름차순 정렬**.
- **사용자 정의 정렬 기준** 사용 가능.
- 내부적으로 정렬을 위해 '레드-블랙 트리'를 사용한다.
- + 레드-블랙 트리 vs 이진 힙 : 전자는 전체 요소 정렬 상태 유지, 후자는 부분 정렬을 통해 최대값 최소값 유지.
 
## <3> set 기본 사용법

```cpp
// 헤더
#include <set>

// 선언
set<int> sets; // 일반적인 int형 sets 선언

template <typename T>
set<T, less> myset; // 템플릿을 이용하고, 사용자 정렬 기준을 이용하는 myset 선언

// 추가
sets.insert(3); // 3은 index가 아니라 key 값 자체.
sets.insert(2);
sets.insert(1);
sets.insert(0);

myset.insert(Key); // Key는 T형 변수라고 가정.

// 삭제
sets.erase(0) // 0은 index가 아니라 key 값 자체.

// 순회 (1)
for (auto num : sets)
  cout << num << ' ';  // 1 2 3

// 순회 (2)
for (set<int>::iterator iter = sets.begin(); iter != sets.end(); iter++)
  cout << *iter << ' '; // 1 2 3
```

선언 시 set의 템플릿에 parameter가 1개도 되고 2개도 된다.
- 1개 : 자료형
- 2개 : 자료형, 정렬 기준

즉 사용자 정의 정렬 기준을 이용할 수 있다.

그럼 그 '사용자 정의 정렬 기준', 어떻게 하는건데?

## <4> set 정렬 기준

먼저 set의 템플릿을 알아보자. 소스 코드를 좀 볼까?
```cpp
template <class _Kty, class _Pr = less<_Kty>, class _Alloc = allocator<_Kty>>
```
말한대로 `_Pr` 이 부분이 '정렬 기준'이 들어갈 위치다.

여기서는 default 값으로 `less` 라는 것이 들어가있다. 이걸 더 알아보자.

```cpp
_EXPORT_STD template <class _Ty = void>
struct less {
    using _FIRST_ARGUMENT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS  = _Ty;
    using _SECOND_ARGUMENT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS = _Ty;
    using _RESULT_TYPE_NAME _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS          = bool;

    _NODISCARD constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
        noexcept(noexcept(_Fake_copy_init<bool>(_Left < _Right))) /* strengthened */ {
        return _Left < _Right;
    }
};
```

less는 구조체 형태다. 일단 다른건 제쳐두고, 연산자 오버로딩 부분을 주목하자!

- 'less' 이름 그대로 작으면 true를 반환 중 : set 자료구조가 기본적으로 오름차순 정렬을 하는 원리!
- `bool operator()(const _Ty& _Left, const _Ty& _Right) const` 로 되어있으니 사용자 정렬 기준 정의 시 그대로 똑같이 하자!
- + 참고로 멤버 함수의 const 빼먹고 정의 시 컴파일 오류 발생.

```
@잠깐! `const 키워드`

위의 코드에서 const는 두 가지 역할을 한다:

1. 매개변수에 대한 const: `const _Ty& _Left` 및 `const _Ty& _Right` - 이는 해당 함수 내에서 _Left와 _Right가 가리키는 값을 변경하지 않음을 나타냄.

2. 멤버 함수에 대한 const: `operator()` 함수 끝에 있는 const - 해당 함수가 호출된 객체의 내부 상태를 변경하지 않음을 나타냄. 이로써 'const 객체'에서도 이 함수를 사용할 수 있음.
```

### @나만의 정렬 기준 정의

그래서 이번 문제에 대해 정렬 기준을 한 번 만들어 보자면,
```cpp
struct Myless
{
	bool operator() (const string &left, const string &right) const
	{
		if (left.length() == right.length())
			return left < right;
		else
			return left.length() < right.length();
	}
};
```
이렇게 되겠다!

## <5> 성능 참고
- `std::vector` 중복 요소 검사 후 push -> 전체 sort() 정렬 : 1200ms 소요
- `std::set` 사용 : 24ms 소요 (약 50배 개선)
