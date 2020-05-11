### Vector란?

- 시퀀스 컨테이너 중 하나.
- 임의 접근 반복자(Random Access Iterator)를 지원하는 배열 기반 컨테이너.
- **크기가 동적**으로 변함. (배열과 가장 큰 차이점)
- 저장할 데이터의 개수가 가변적이라면, Vector를 사용하는게 빠르고 편리.
- **복사 비용이 발생**하므로, 데이터를 중간에 삽입하거나 삭제해야하는 경우에는 추천X
- __많은 데이터를 저장__하게 될 경우, 원하는 값을 찾기 위해서는 오랜 시간이 소요됨.



### Vector의 메소드

| 메소드      | 기능                                                         |
| ----------- | ------------------------------------------------------------ |
| assign()    | 특정 원소로 채움.                                            |
| at()        | 특정 위치의 원소의 값을 리턴.                                |
| back()      | 마지막 원소의 값을 리턴.                                     |
| begin()     | 첫 번째 원소의 랜덤 접근 반복자를 리턴.                      |
| clear()     | 모든 원소를 삭제.                                            |
| empty()     | 비어있으면 True, 아니면 False.                               |
| end()       | 마지막 원소의 다음 반복자를 리턴.                            |
| erase()     | 특정 위치의 원소나 지정 범위의 원소를 삭제.                  |
| front()     | 첫 번째 원소의 참조를 리턴.                                  |
| insert()    | 특정 위치에 원소를 삽입.                                     |
| pop_back()  | 마지막 원소를 삭제.                                          |
| push_back() | 마지막에 원소를 추가.                                        |
| rbegin()    | 역방향으로 첫 번째 원소의 반복자를 리턴.                     |
| rend()      | 역방향으로 마지막 원소의 다음 반복자를 리턴. 마찬가지로, 이 영역은 사용하지 않는 영역. |
| reserve()   | 지정된 크기의 저장 공간을 확보.                              |
| size()      | 원소의 개수를 리턴.                                          |
| swap()      | vector의 두 원소를 서로 교환                                 |
| resize()    | 크기를 받아온 인자로 크기를 변경. 더 커졌을 경우 default로 0으로 채워짐. |
| capacity()  | 할당된 공간의 크기를 리턴.                                   |



### Vector의 Size와 Capacity 관계

- Size: 현재 원소의 개수를 출력하는 것.
- Capacity: 전체 할당된 공간의 크기를 의미.
- push_back()을 하여 값이 점점 늘어날 때, 하나씩 할당해주지 않음.
  - 하나씩 할당하게 되면 비용이 많이 발생하기 때문.
  - 하나씩이 아닌 일정한 조건에 따라 할당 되는 것으로 추정.

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> vec;
  
  for(int i=0; i<100; i++){
    vec.push_back(i+1);
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
  }
  return 0;
}
```



### Vector 사용하기

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> vec;
  vec.reserve(5);
  for(int i=0; i<10; i++){
    vec.push_back(i+1);
  }
  
  for(int i=0; i<10; i++){
    cout<<vec.at(i)<<" ";
  }
  cout<<endl;
  
  cout<<"할당된 공간: "<<vec.capacity()<<endl;
  
  cout<<endl;
  
  vec.pop_back();
  
  for(int i=0; i<vec.size(); i++){
    cout<<vec.at(i)<<" ";
  }
  
  return 0;
}
```

