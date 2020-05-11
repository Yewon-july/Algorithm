### MultiMap이란?

- map이랑 기본적으로는 비슷. 단, 
- [] 연산자를 사용할 수 없음.
- 같은 키의 값을 여러 개 사용 가능



### Multimap 사용하기

```c++
#include <iostream>
#include <map>

using namespace std;

multimap<string, int> mData;

int main(){
  mData.insert(make_pair("zero", 0));
  mData.insert(make_pair("one", 1));
  mData.insert(make_pair("one", 1));
  mData.insert(make_pair("two", 2));
  mData.insert(make_pair("three", 3));
  
  cout<<"lower_bound"<<endl;
  cout<<(*mData.lower_bound("zero")).first<<endl;
  
  cout<<"upper_bound"<<endl;
  cout<<(*mData.upper_bound("one")).first<<endl;
  
  cout<<"원하는 키 삭제"<<endl;
  
  for(multimap<string, int>::iterator iter = mData.begin(); iter != mData.end(); iter++){
    if((*iter).first._Equal("one")){
      mData.erase(iter);
      break;
    }
  }
  return 0;
}
```





