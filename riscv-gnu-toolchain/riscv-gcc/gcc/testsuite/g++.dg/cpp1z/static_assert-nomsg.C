// { dg-options "-std=c++1z" }

template<typename T>
  struct is_float
  {
    static constexpr bool value = false;
  };

template<>
  struct is_float<float>
  {
    static constexpr bool value = true;
  };

template<typename T>
  T
  float_thing(T __x)
  {
    static_assert(is_float<T>::value, ""); // { dg-error "static assertion failed" }
    static_assert(is_float<T>::value); // { dg-error "static assertion failed" }
  }

int
main()
{
  float_thing(1);
}
