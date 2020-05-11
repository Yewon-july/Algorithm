### MultiSet이란?

- Set과 비슷하나, set에서는 안되는 __중복 저장__이 가능하게 되는 것이 바로 MultiSet.
- lower_bound()와 upper_bound()라는 함수가 존재.
  - `lower_bound()`: 자신과 __같거나 당므으로 큰 값__의 iterator를 반환
  - `upper_bound()`: __자신보다 다음으로 큰 값__의 iterator를 반환



### MultiSet 코드

```c++
#include <iostream>
#include <set>

using namespace std;

int main(){
  multiset<int> data;
  
  for(int i=1; i<=10; i++){
    data.insert(i);
  }
  data.insert(4);
  data.insert(4);
  data.insert(4);
  
  cout<<"Lower_bound: "<<(*data.lower_bound(0))<<endl;
  cout<<"Upper_bound: "<<(*data.upper_bound(5))<<endl<<endl;
  
  cout<<"Data 원소: ";
  
  for(set<int>::iterator iter=data.begin(); iter!=data.end(); iter++){
    cout<<(*iter)<<" ";
  }
  cout<<endl<<"DATA 사이즈: ";
  cout<<dta.size()<<endl;
  
  cout<<"count: "<<data.count(4)<<endl;
  
  cout<<endl<<"(0) 원소 있음|(1) 원소 없음"<<data.empty()<<endl;
  
  data.clear();
  
  cout<<endl<<"DATA 사이즈: ";
  cout<<data.size()<<endl;
  
  return 0;
}
```

