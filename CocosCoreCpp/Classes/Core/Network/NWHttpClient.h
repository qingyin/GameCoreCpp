#pragma once

#include "cocos2d.h"
#include "network/HttpClient.h"

#include <string>
using namespace std;

USING_NS_CC;
using namespace network;

class NWHttpClient
{
public:
	virtual ~NWHttpClient(void);
	NWHttpClient(void);
	static NWHttpClient* getInstance();
	void sendHttpData(const string tag,const char* url,HttpRequest::Type type,bool isImmediate);
	void onHttpRequestCompleted(HttpClient* sender,HttpResponse* response);

	void onGetTest(bool isImmediate);
	void onPostTest(cocos2d::Ref *sender,bool isImmediate);
	void onPutTest(bool isImmediate);
	void onDeleteTest(bool isImmediate);
private:
	static NWHttpClient* m_http;

};

