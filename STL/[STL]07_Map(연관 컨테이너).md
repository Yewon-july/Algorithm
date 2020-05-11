### Map이란?

- __연관 컨테이너 노드 기반__의 균형 이진 트리 구조.
- set과 비슷하나, __key__라고 불리는 원소들과 데이터 __value__를 가지고 있는 사전적 자료구조.
- key를 알면 value에 __바로 접근__이 가능. key는 중복 불가.
- key를 삽입하면 __오름차순으로 자동 정렬__
- []연산자를 제공하여, key에 해당하는 데이터를 쉽게 __접근__ 가능



| 메소드          | 기능                                                   |
| --------------- | ------------------------------------------------------ |
| begin()         | 첫 번째 원소의 iterator을 반환                         |
| end()           | 마지막 원소의 iterator을 반환                          |
| rbegin()        | 거꾸로 했을 때 첫번째 원소의 iterator을 반환.          |
| rend()          | 거꾸로 했을 때 마지막 원소의 iterator을 반환           |
| clear()         | 모든 원소를 제거                                       |
| count()         | 키 개수를 리턴                                         |
| empty()         | 비어있으면 true, 아니면 false 반환.                    |
| insert()        | pair 객체를 이용해 삽입                                |
| insert()        | iterator이 가리키는 위치에 값을 삽입                   |
| erase(n,y)      | n에서 y까지의 범위의 키를 모두 제거                    |
| erase(iterator) | iterator이 가리키는 위치의 키 제거                     |
| find(x)         | x 값의 키를 찾음. 없으면 마지막 위치의 iterator을 반환 |
| swap()          | 서로의 맵을 바꿈                                       |
| upper_bound()   | x 키보다 큰 값인 iterator를 리턴                       |
| lower_bound()   | x키가 시작하는 곳의 iterator를 리턴                    |
| value_comp()    | 값의 정렬 기준이 되는 조건자를 리턴                    |
| key_comp()      | 키의 정렬 기준이 되는 조건자를 리턴                    |
| size()          | 키 개수를 리턴                                         |
| max_size()      | 메모리에 할당되어 있는 사이즈를 리턴.                  |



### Map 사용하기

```c++
#include <iostream>
#include <map>

using namespace std;

map<string, int> mData;

void PrintMap(){
  for(map<string, int>::iterator iter = mData.begin(); iter != mData.end(); iter++){
    cout<<iter->first<<", "<<iter->second<<endl;
    cout<<endl;
  }
}
int main(){
  mData["zero"] = 0;
  mData.insert(make_pair("one", 1));
  mData.insert(make_pair("two", 2));
  mData.insert(make_pair("three", 3));
  cout<<"전체 데이터: "<<endl;
  PrintMap();
}
```



### 원하는 값 삭제하기

```c++
#include <iostream>
#include <map>

using namespace std;

map<string, int> mData;

int main(){
  mData["zero"] = 0;
  mData.insert(make_pair("one", 1));
  mData.insert(make_pair("two", 2));
  mData.insert(make_pair("three", 3));
  
  cout<<"원하는 데이터 삭제"<<endl;
  
  for(map<string, int>::iterator iter = mData.begin(); iter != mData.end(); iter++){
    if(iter->second == 3){
      iter = mData.erase(iter);
    }
  }
  
  cout<<"원하는 키 삭제"<<endl;
  
  for(map<string, int>::iter iter = mData.begin(); iter != mData.end(); iter++){
    if(iter->first == "zero"){
      iter = mData.erase(iter);
    }
  }
  
  return 0;
}
```

