/*
 * Imagine a (literal) stack of plates. If the stack gets too high, it might
 * topple. Therefore, in real life, we would likely start a new stack when the
 * previous stack exceeds some threshold. Implement a data structure SetOfStacks
 * that mimics this. SetOfStacks should be composed of several stacks, and
 * should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a
 * single stack (that is, pop() should return the same values as it would if
 * there were just a single stack).
 * FOLLOW UP: Implement a function popAt(int index) which performs a pop
 * operation on a specific sub-stack.
 */
 template<typename T, int sz>
  class Stack {
  public:
    Stack() {
      _min = 0;
      _top = -1;
      _topmins = -1;
    }

    void push(T v) {
      if(_topmins >= 0) {
         if(v < _mins[_topmins]) {
           _topmins++;
           _mins[_topmins] = v;
         }
       }
       else {
         _topmins++;
         _mins[_topmins] = v;
       }

       _top++;
       _buf[_top] = v;
    }

    T pop() {
      T r = _buf[_top];
      if(r == _mins[_topmins]) {
        _topmins--;
      }
      _top--;
      return r;
    }


    T min() {
      if(_topmins >= 0)
        return _mins[_topmins];
      else
        return MAX_INT;
    }

    int space() {
      return (sz - (_top + 1));
    }
  private:
    int _top;
    int _topmins;
    T _buf[sz];
    T _mins[sz];
    T _min;
  }


 template<typename T, int _threshold>
 class SetOfStacks {
public:
  SetOfStacks() {
    _all.push_front(new Stack<T, _threshold>());
  }
  void push(T v) {
    if(_all.front().space() == 0) {
      _all.push_front(new Stack<T, _threshold>());
    }

    _all.front().push(v);
  }

  T pop() {
    if(_all.front().space() == _threshold) {
      _all.pop_front();
    }

    return _all.front().pop();
  }

  T popAt(int index) {
    if(index >= 0 || index < _all.size()) {
      return _all[index].pop();
    }

  }

private:
  std::list<Stack*> _all;

 };
