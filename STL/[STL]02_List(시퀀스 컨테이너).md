

### List

- Template으로 구현한 것으로 *서로 연결*되어 있음.

- 배열처럼 크기가 정해져있지는 않고, *동적으로 크기를 변경*할 수 있음.

- *자료구조*에 있는 *연결 리스트를 대체*하여 사용 가능

- 순차적으로 접근 가능하지만, *랜덤적으로는 접근 불가*

- 단방향이 아닌 *양방향 연결 리스트*

- *중간에 데이터 삽입 및 삭제*가 자유롭게 가능

  

- 리스트는 순차적 접근만 가능하기에 데이터 양이 많으면 원하는 데이터를 찾는 데 오랜 시간이 걸림. 즉, 비효율적!

  

### List 메소드

| 메소드                  | 기능                                                       |
| ----------------------- | ---------------------------------------------------------- |
| begin()                 | 첫 번째 위치를 가리킴.                                     |
| end()                   | 마지막 위치를 가리킴.                                      |
| rbegin()                | 역방향으로 첫 번째 위치를 가리킴.                          |
| rend()                  | 역방향으로 마지막 위치를 가리킴.                           |
| push_front(T _value)    | 첫 번째 위치에 값을 넣음.                                  |
| pop_front()             | 첫 번째 위치에 있는 값을 삭제함.                           |
| push_back(T _value)     | 마지막 위치에 값을 넣음.                                   |
| pop_back()              | 마지막 위치에 값을 삭제함.                                 |
| front()                 | 첫 번째 위치에 있는 값을 반환함.                           |
| back()                  | 마지막 위치에 있는 값을 반환함.                            |
| clear()                 | 모든 값들을 삭제함.                                        |
| empty()                 | 원소들이 비워져있는지 확인. (1=없음, 0=있음)               |
| size()                  | 전체적으로 들어있는 원소들의 개수를 반환.                  |
| insert(iterator, value) | 원하는 위치에 값을 넣음.                                   |
| erase(iterator)         | 원하는 위치의 값을 삭제함.                                 |
| remove(T _value)        | 지정된 값과 일치하는 모든 값을 삭제.                       |
| sort()                  | 원소들을 정렬.                                             |
| unique()                | 인접한 원소가 같으면 유일함.                               |
| merge()                 | 두 list의 요소들이 각각 정렬되어 있으면, 두 리스트를 병합. |
| reverse()               | 리스트에 들어있는 원소를 역순.                             |
| splice()                | 다른 리스트의 원소들을 잘라서 붙임.                        |
| resize()                | 리스트의 크기 변경.                                        |
| assign()                | 리스트의 원소를 지정한 값으로 채움.                        |



### Deque 사용해보기

push_back()과 back()

```c++
#include <iostream>
#include <list>

using namespace std;
int main(){
  list<int> li;
  li.push_back(1);
  cout<<li.back()<<endl;
  li.push_back(2);
  cout<<li.back()<<endl;
  li.push_back(3);
  cout<<li.back()<<endl;
  li.pop_back();
  cout<<li.back()<<endl;
  li.pop_back();
  cout<<li.back()<<endl;
  return 0;
}
```



push_front()와 front()

```c++
#include <iostream>
#include <list>

using namespace std;
int main(){
  list<int> li;
  li.push_front(1);
  cout<<li.front()<<endl;
  li.push_front(2);
  cout<<li.front()<<endl;  
  li.push_front(3);
  cout<<li.front()<<endl;
  li.pop_front();
  cout<<li.front()<<endl;
  li.pop_front();
  cout<<li.front()<<endl;
  return 0;
```



resize()

```c++
#include <iostream>
#include <list>

using namespace std;
int main(){
  list<int> li;
  li.resize(5);
  cout<<li.size()<<endl;
  return 0;
}
```



remove()

```c++
#include <iostream>
#include <list>

using namespace std;
int main(){
  list<char> li;
  li.push_back('A');
  li.push_back('B');
  li.push_back('C');
  li.remove('C');
  
  cout<<li.back();
  
  return 0;
}
```



remove_if()

```c++
#include <iostream>
#include <list>

using namespace std;

bool isC(char _n){
  if(_n == 'C'){
    return true;
  }
  return false;
}
int main(){
  list<char> li;
  li.push_back('A');
  li.push_back('B');
  li.push_back('C');
  li.remove_if(isC);
  
  cout<<li.back();
  
  return 0;
}
```

iterator로 순차적 삭제

```c++
#include <iostream>
#include <list>

using namespace std;
int main(){
  list<char> li;
  li.push_back('A');
  li.push_back('B');
  li.push_back('C');
  
  list<char>::iterator iter;
  for(iter=&li; iter!=li.end(); iter++){
    if((*iter)=='C'){
      li.erase(iter);
    }
  }
  cout<<li.back();
  
  return 0;
}
```







