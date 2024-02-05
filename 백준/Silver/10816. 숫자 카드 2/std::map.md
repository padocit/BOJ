# std::map 사용법

> 정수를 입력받고, 그 정수의 개수를 세고, 없는 숫자는 0으로 출력한다.

보자마자 '심볼 테이블' 형태가 생각났다.

따라서 C++ STL 상의 std::map 사용법을 묻는다고 생각했다.

## 1) map 요소 존재 유무

- `map.count()`

  - 해당 key에 대한 pair가 있으면 1을 반환.
  - 없으면 0 반환.

## 2) map 요소 추가하는 방법

map에 요소를 추가하는 방법은 두 가지가 있다.

- `operator[]`
- `map.insert()`

### operator[]
```cpp
    // operator[]를 사용하여 요소 추가
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // 이미 있는 키에 대해 값 덮어쓰기
    myMap[2] = "NewTwo";
```

- 특징
  - 간결하고 직관적
  - 이미 존재하는 경우 덮어쓴다.


### map.insert()
```cpp
    // insert 함수를 사용하여 요소 추가
    myMap.insert(std::make_pair(1, "One"));
    myMap.insert(std::make_pair(2, "Two"));
    myMap.insert(std::make_pair(3, "Three"));

    // 이미 있는 키에 대해 값 덮어쓰기 -> operator[]
    myMap[2] = "NewTwo";
```

- 특징
  - `std::pair` 객체로 넣어준다.
  - 이미 존재하는 경우 아무것도 하지 않는다.

## 3) 여기서는?

이 문제에서는 
- 이미 존재하는 Key:Value의 경우 : value에 1 추가해서 덮어쓰기. (counting)
- 존재하지 않는 Key:Value의 경우 : value에 1을 넣어줌.

즉 존재하는 경우 아무것도 하지 않는게 아니라, value에 1을 더해줘야 한다.

따라서 `count()` 반환값에 분기하고, `operator[]`를 이용해 추가하든, 덮어쓰든 한다.
