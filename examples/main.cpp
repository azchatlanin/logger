#include "logger/logger.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  try {

    /* integer */
    int a{123};
    int b = 456;
    float bf = 4.56;

    LOG(a);
    WARN(a, 789, 12.3, bf);
    ERROR(a, b, 78.9, int(5), int{8});
    /*
      INFO: main/main.cpp:11: --> 123
      WARN: main/main.cpp:12: --> 123, 789, 123
      ERROR: main/main.cpp:13: --> 123, 456, 789, 5, 8
    */


    /* containers */
    std::vector v = { "string one", "string other", "string more" };
    std::list l = { 4.56, 5.89, 6.102 };
    LOG(1, 2, v);
    WARN(l, 789, 123);
    ERROR(789, int(5), int{1024}, l, v);
    /*
      INFO: main/main.cpp:25: --> 1, 2, string one, string other, string more
      WARN: main/main.cpp:26: --> 4.56, 5.89, 6.102, 789, 123
      ERROR: main/main.cpp:27: --> 789, 5, 1024, 4.56, 5.89, 6.102, string one, string other, string more
    */


    /* string */
    using namespace std::string_literals;
    char ds = 's';
    auto ss = "this is a sting"s;
    std::string ssv = "this is a sting";
    LOG(1, 2, v, ds);
    WARN(l, 789, 123, ss);
    ERROR(789, int(5), int{1024}, l, v, ssv, "text", '@');
    /*
      INFO: main/main.cpp:40: --> 1, 2, string one, string other, string more, s
      WARN: main/main.cpp:41: --> 4.56, 5.89, 6.102, 789, 123, this is a sting
      ERROR: main/main.cpp:42: --> 789, 5, 1024, 4.56, 5.89, 6.102, string one, string other, string more, this is a sting, text, !
    */


    /* tuple */
    auto tuple_value = std::make_tuple(5, "Hello", -0.1);
    LOG(tuple_value);
    WARN(l, 789, tuple_value, 123, ss);
    ERROR(789, int(5), int{1024}, l, v, ssv, tuple_value, "final string data");
    /*
      INFO: main/main.cpp:51: --> 5, Hello, -0.1
      WARN: main/main.cpp:52: --> 4.56, 5.89, 6.102, 789, 5, Hello, -0.1, 123, this is a sting
      ERROR: main/main.cpp:53: --> 789, 5, 1024, 4.56, 5.89, 6.102, string one, string other, string more, this is a sting, 5, Hello, -0.1, final string data
    */

  } catch (const std::exception& e) {
    ERROR(e.what());
  }

  return 0;
}
