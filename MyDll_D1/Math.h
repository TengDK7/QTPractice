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
_declspec(dllexport) double reduce_d1(double a, double b);//�������غ����޷�ͬʱ����extern "C"�У�����������Խ��Ҳ��ֻ��һ������ʹ��


int multiply_d1(int a, int b);
int divide_d1(int a, int b);



