#include "JniUtil.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <Jni.h>
#include "platform/android/jni/JniHelper.h"
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "IosHelper.h"
#endif

#define JAVA_CLASSNAME  "org/cocos2dx/cpp/AppActivity"
using namespace cocos2d;
namespace JniUtil
{
	string callJava_getAppVersion()
	{
		string str = "";
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		JniMethodInfo minfo;  
		bool isHave = JniHelper::getStaticMethodInfo(minfo,JAVA_CLASSNAME, "getAppVersion", "()Ljava/lang/String;");
		if (isHave)  
		{  
			jstring jVersion = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID); 
			const char* version = minfo.env->GetStringUTFChars(jVersion,0);
			str = version;
			minfo.env->ReleaseStringUTFChars(jVersion, version);
			minfo.env->DeleteLocalRef(minfo.classID);  
			cocos2d::log("JniFun call callJava_getAppVersion over!===%s",str.c_str());
		}  
		else
		{
			cocos2d::log("JniFun call callJava_getAppVersion error!");
		}
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
		//IosHelper::HuiPay(kStr.c_str());
#endif
		return str;
	}
	bool callJava_copyText(string copyText)
	{
		bool isSuccess = false;
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		JniMethodInfo minfo;  
		bool isHave = JniHelper::getStaticMethodInfo(minfo,JAVA_CLASSNAME, "copyText", "(Ljava/lang/String;)Z");
		if (isHave)  
		{  
			jstring jCopyText = minfo.env->NewStringUTF(copyText.c_str());
			jboolean jIsSuccess= minfo.env->CallStaticBooleanMethod(minfo.classID, minfo.methodID,jCopyText); 
			isSuccess = jIsSuccess;
			minfo.env->DeleteLocalRef(minfo.classID);  
			cocos2d::log("JniFun call callJava_copyText over!");
		}  
		else
		{
			cocos2d::log("JniFun call callJava_copyText error!");
		}
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
		//IosHelper::HuiPay(kStr.c_str());
#endif
		return isSuccess;
	}
	string callJava_getTestAllString(bool b,int i,float f,double d,string s)
	{
		string str = "";
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		JniMethodInfo minfo;  
		bool isHave = JniHelper::getStaticMethodInfo(minfo,JAVA_CLASSNAME, "getTestAllString", "(ZIFDLjava/lang/String;)Ljava/lang/String;");
		if (isHave)  
		{  
			jstring js = minfo.env->NewStringUTF(s.c_str());
			jstring jRes = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,b,i,f,d,js); 
			const char* res = minfo.env->GetStringUTFChars(jRes,0);
			str = res;
			minfo.env->ReleaseStringUTFChars(jRes, res);
			minfo.env->DeleteLocalRef(js);
			minfo.env->DeleteLocalRef(minfo.classID);  
			cocos2d::log("JniFun call callJava_getTestAllString over!==%s",str.c_str());
		}  
		else
		{
			cocos2d::log("JniFun call callJava_getTestAllString error!");
		}
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
		//IosHelper::HuiPay(kStr.c_str());
#endif
		return str;
	}
	void callJava_callNativeFunShowText(bool b,int i,float f,double d,string s)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		JniMethodInfo minfo;  
		bool isHave = JniHelper::getStaticMethodInfo(minfo,JAVA_CLASSNAME, "callNativeFunShowText", "(ZIFDLjava/lang/String;)V");
		if (isHave)  
		{  
			jstring js = minfo.env->NewStringUTF(s.c_str());
			jstring jRes = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,b,i,f,d,js); 
			const char* res = minfo.env->GetStringUTFChars(jRes,0);
			string str = res;
			minfo.env->ReleaseStringUTFChars(jRes, res);
			minfo.env->DeleteLocalRef(js);
			minfo.env->DeleteLocalRef(minfo.classID);  
			cocos2d::log("JniFun call callJava_callNativeFunShowText over!==%s",str.c_str());
		}  
		else
		{
			cocos2d::log("JniFun call callJava_callNativeFunShowText error!");
		}
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
		//IosHelper::HuiPay(kStr.c_str());
#endif
	}
} 
