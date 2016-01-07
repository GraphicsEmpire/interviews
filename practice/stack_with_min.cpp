/*
 * How would you design a stack which, in addition to push and pop, also has
 * a function min which returns the minimum element? Push, pop and min should
 * all operate in O(1) time.
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
 private:
   int _top;
   int _topmins;
   T _buf[sz];
   T _mins[sz];
   T _min;
 }
