#pragma once
#include "cocos2d.h"
#include "network/HttpClient.h"
#include "Core/FV/FvSingleton.h"
USING_NS_CC;
using namespace network;
using namespace std;

class HttpManagerDelegate
{
public:
	virtual void onHttpManagerRequestCompleted(HttpClient* sender,HttpResponse* response) = 0;
};

class HttpManager //: public FvSingleton<HttpManager>
{
public:
	HttpManager(void);
	~HttpManager(void);
	CC_SYNTHESIZE(HttpManagerDelegate*,_httpManagerDelegate,HttpDelegate);
	//static HttpManager* getInstance();
	void sendGetRequest(string url,string requestTag);
	void sendPostRequest(string url,string requestTag);
private:
	void onHttpRequestCompleted(HttpClient* sender,HttpResponse* response);
	//static HttpManager* mHttpManager;
};

