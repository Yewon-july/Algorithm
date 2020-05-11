### Deque란?

- Double Ended Queue
- __Vector의 단점을 보완__하기 위해서 만들어짐.
- __Stack과 Queue의 장점__들을 모아 만들어진 자료 구조
  - Queue는 선형 리스트 방식으로, 뒤로 값을 추가하고 삭제는 앞으로 함.
- __FIFO와 LIFO__ 모두 사용
- 삽입, 삭제를 양쪽에서 다 할 수 있음.
- 크기가 __가변적__
- 앞 뒤에서 삽입 삭제 가능.
- 중간에 __데이터 삽입과 삭제가 용이하지 않음__
  - 모든 데이터를 옮겨줘야하기 때문
- 구현이 십지 않음
- Vector과 마찬가지로 무작위 접근이 가능함



### Deque 메소드

| 메소드       | 기능                                                        |
| ------------ | ----------------------------------------------------------- |
| assign()     | 특정 원소로 채운다.                                         |
| at()         | 특정 위치의 원소의 참조를 리턴한다. []기반보다 속도가 느림. |
| begin()      | 첫 번째 원소의 랜덤 접근 반복자를 리턴.                     |
| clear()      | 모든 원소를 삭제.                                           |
| empty()      | 비어있으면 True, 반대면 False를 반환.                       |
| end()        | 마지막 원소 다음의 반복자를 리턴.                           |
| erase()      | 특정 위치의 원소나, 지정 범위의 원소를 삭제.                |
| front()      | 첫 번째 원소의 참조를 리턴.                                 |
| insert()     | 특정 위치에 원소 삽입.                                      |
| pop_back()   | 마지막 원소를 삭제.                                         |
| pop_front()  | 첫 번재 원소를 삭제.                                        |
| push_back()  | 마지막에 원소를 추가.                                       |
| push_front() | 제일 앞에 원소를 추가.                                      |
| rbegin()     | 역방향으로 첫 번째 원소의 반복자를 리턴.                    |
| rend()       | 역방향으로 마지막 원소 다음의 반복자를 리턴.                |
| reserve()    | 지정된 크기의 저장 공간을 확보.                             |
| size()       | 원소의 개수를 리턴.                                         |
| swap()       | deque의 두 원소를 서로 교환.                                |
| back()       | 마지막 원소의 참조를 리턴.                                  |



### Deque 사용해보기

```c++
#include <iostream>
#include <deque>

define DEFAULT_LEN 5
  
using namespace std;

int main(){
  deque<int> dec;
  for(int i=0; i<10; i++){
    dec.push_back(i+1);
  }
  for(int i=0; i<dec.size(); i++){
    cout<<dec.at(i)<<" ";
  }
  cout<<endl;
  
  dec.pop_front();
  dec.pop_back();
  
  for(int i=0; i<dec.size(); i++){
    cout<<dec.at(i)<<" ";
  }
  return 0;
}
```







