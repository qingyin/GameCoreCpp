#pragma  once
#include <string>
using namespace std;
namespace JniUtil
{
	string callJava_getAppVersion();
	bool callJava_copyText(string copyText);
	string callJava_getTestAllString(bool b,int i,float f,double d,string s);
	void callJava_callNativeFunShowText(bool b,int i,float f,double d,string s);
} 

