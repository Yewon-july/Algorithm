**Function Template**

- 자료형을 정의하지 않고 자유롭게 자료형을 변경하면서 사용할 수 있음.

  ```c++
  #include <iostream>
  
  using namespace std;
  
  template<typename T>
  T SUM(T _a, T _b){
    return _a+_b;
  }
  
  int main(){
    cout<<SUM<int>(1, 2);
    
    return 0;
  }
  ```

  - `template<typename T>`이런식으로 사용함. T에 자료형을 지정하면, 그 자료형에 따라 바뀜.

  - 결과: 2

    

**Class Template**

- 아래와 같이 템플릿을 이용하여 클래스 안에서도 자료형을 자유롭게 바꿀 수 있음.

```c++
#include <iostream>

using namespace std;

template<typename T>
class Test{
  public: 
  	T a;
}

int main(){
  Test<int> test;
  test.a = 20;
  cout<<test.a;
  return 0;
}
```