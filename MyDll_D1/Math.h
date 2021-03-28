#pragma once

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

	_declspec(dllexport) int add_d1(int a, int b);


#ifdef __cplusplus
}
#endif // __cplusplus

_declspec(dllexport) int reduce_d1(int a, int b);
_declspec(dllexport) double reduce_d1(double a, double b);//两个重载函数无法同时放入extern "C"中，放在外面测试结果也是只有一个可以使用


int multiply_d1(int a, int b);
int divide_d1(int a, int b);



