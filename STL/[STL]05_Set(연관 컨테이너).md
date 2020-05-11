### Set란?

- 노드 형태의 연관 컨테이너.
- __이진 트리의 모양__.
- 오름차순 혹은 내림차순 형태로 __정렬-_되어 저장.
- 똑같은 형태의 값을 담을 수 있음.
- 중복 값 안됨.



### Set 멤버 함수

| 메소드   | 기능                                                        |
| -------- | ----------------------------------------------------------- |
| insert() | 데이터 삽입                                                 |
| erase()  | 데이터 삭제                                                 |
| begin()  | 첫 번째 원소를 가리키는 iterator 반환.                      |
| end()    | 마지막 원소를 가리키는 iterator 반환                        |
| empty()  | 비어있으면 true, 아니면 false 반환                          |
| find()   | 해당 값이 원소로 있는지 찾아주고, 해당 값의 iterator를 반환 |
| count()  | 해당 count가 몇 개 있는지 반환                              |
| clear()  | 모든 데이터 삭제                                            |



### Set 사용하기

```c++
#include <iostream>
#include <set>

using namespace std;

int main(){
  set<int> data;
  
  for(int i=1; i<=10; i++){
    data.insert(i);
  }
  
  data.insert(4);
  data.insert(4);
  data.insert(4);
  
  cout<<"DATA 원소: ";
  
  for(set<int>::iterator iter = data.begin(); iter != data.end(); iter++){
    cout<<(*iter)<<" ";
  }
  cout<<endl<<"DATA size: ";
  cout<<data.size()<<endl;
  
  cout<<endl<<"(0) 원소 있음 | (1) 원소 없음"<<data.empty()<<endl;
  
  data.clear();
  
  cout<<endl<<"DATA 사이즈: ";
  cout<<data.size()<<endl;
  
  return 0;
}
```



