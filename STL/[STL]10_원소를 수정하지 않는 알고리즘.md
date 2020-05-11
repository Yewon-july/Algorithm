### 원소를 수정하지 않는 알고리즘이란?

- 말 그대로, 원소를 수정하지 않고 __읽기만 하여 해당 결괏값을 리턴__ 해주는 알고리즘을 지칭함.



### 중복된 값의 시작점을 찾는 함수

- `adjacent_find()` 를 사용함.
- 중복이 되는 값의 시작 지점의 iterator을 반환함.
- 중복되는 값이 없으면 마지막 원소의 iterator를 반환함



```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  
  vector<int>::iterator iter = adjacent_find(v.begin(), v.end());
  
  for(; iter !- v.end(); iter++){
    cout<<(*iter)<<endl;
  }
  return 0;
}
```



### 원하는 원소의 값의 개수 찾기

- `count()` 를 사용.
- 배열 또는 컨테이너 안의 요소 중 원하는 값의 개수를 리턴함.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int v[6]{1, 2, 2, 4, 5, 5};
  int cnt = count(&v[0], &v[6], 5);
  cout<<cnt;
  return 0;
}
```



### 원소를 찾을 때 조건을 넣기

- `count_if()` 를 사용. 

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool countif(int _value){
  return _value > 3;
}

int main(){
  vector<int> v = {1, 2, 3, 4, 5};
  int count = count_if(v.begin(), v.end(), countif);
  cout<<cnt;
  return 0;
}
```



### 두 순차열의 원소를 비교

- `equal()` 을 사용함.
- v1의 범위를 기준으로 v2의 값을 비교함.
- 그래서, v2 범위 안의 값이 모두 맞으면 참을 반환함.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};
  if(equal(v1.begin(), v1.end(), v2.begin())){
    cout<<"두 개의 벡터의 원소들이 모두 같습니다."<<endl;
  }
  return 0;
}
```



### 원하는 원소 찾기

- `find()` 를 사용함.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> v = {1, 2, 3, 4, 5};
  auto iter = find(v.begin(), v.end(), 4);
  cout<<*iter<<endl;
  
  return 0;
}
```



### 원하는 원소 찾기2

- `find_if()` 를 사용함.
- 컨테이너 안의 원소 중 제일 처음 조건에 맞았던 iterator를 반환함.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cond(int _value){
  return _value > 2;
}

int main(){
  vector<int> v = {1, 2, 3, 4, 5};
  auto iter = find_if(v.begin(), v.end(), cond);
  cout<< *iter <<endl;
  
  return 0;
}
```



### for_each 알고리즘

- c++에서도 for each가 있지만 함수로도 존재함.

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int _value){
  cout<<_value<<endl;
}

int main(){
  vector<int> v = {1, 2, 3, 4, 5};
  for_each(v.begin(), v.end(), print);
  return 0;
}
```



### 순차적 비교

- 원소를 순차적으로 돌며 비교함.
- 모든게 같거나 첫 번째 인자 값이 더 크면 false를 반환.
- 그 외의 좌측의 인자 값이 더 크면 true를 반환.



