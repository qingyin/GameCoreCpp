#pragma once

#include "Core/FV/FvSingleton.h"
#include "Core/Network/HttpManager.h"
using namespace std;
class BLLHttpTest : public HttpManagerDelegate//,public FvSingleton<BLLHttpTest>
{
public:
	BLLHttpTest(void);
	~BLLHttpTest(void);

	static BLLHttpTest* getInstance();

	typedef std::function<void(string responseData,const char* tag)> onResponseCallBack;
	void sendGetRequest(string url,string requestTag,onResponseCallBack cb);
	void sendPostRequest(string url,string requestTag,onResponseCallBack cb);
	virtual void onHttpManagerRequestCompleted(HttpClient* sender,HttpResponse* response);
private:
	void onHttpRequestCompletedDataHandle(string data,string tag);
	std::map<string, onResponseCallBack> mMapCallBack;
	static BLLHttpTest* mBLLHttpTest;
	HttpManager* mHttpManager;
};

