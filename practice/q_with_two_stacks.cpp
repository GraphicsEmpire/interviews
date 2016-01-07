/*!
 * Implement a MyQueue class which implements a queue using two stacks.
 */


template<typename T, int sz>
class QbyStack {
public:
  void add(T v) {
    _st1.push(v);
  }

  int size() {
    return _st1.size() + _st2.size();
  }

  T peek() {
    if(!_st2.empty())
      return _st2.peek();
    while(!_st1.empty()) {
      _st2.push(_st1.pop());
    }
    return _st2.peek();
  }

  T remove() {
    if(!_st2.empty())
      return _st2.pop();
    while(!_st1.empty()) {
      _st2.push(_st1.pop());
    }
    return _st2.pop();
  }


private:
  stack<T, sz> _st1;
  stack<T, sz> _st2;


};
