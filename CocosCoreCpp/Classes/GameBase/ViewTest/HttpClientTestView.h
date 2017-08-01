#pragma once
#include "cocos2d.h"
#include "network/HttpClient.h"
#include <string>
#include "GameBase/WidgetEx/LayerEx.h"
USING_NS_CC;
using namespace network;
using namespace std;
class HttpClientTest : public LayerEx
{
public:
	HttpClientTest(void);
	~HttpClientTest(void);
	virtual bool init();
	CREATE_FUNC(HttpClientTest);

	//Menu Callbacks
	void onMenuGetTestClicked(cocos2d::Ref *sender, bool isImmediate);
	void onMenuPostTestClicked(cocos2d::Ref *sender, bool isImmediate);
	void onMenuPostBinaryTestClicked(cocos2d::Ref *sender, bool isImmediate);
	void onMenuPutTestClicked(cocos2d::Ref *sender, bool isImmediate);
	void onMenuDeleteTestClicked(cocos2d::Ref *sender, bool isImmediate);

	//Http Response Callback
	void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);

	void onResponseCallBack(std::string responseData,const char* tag);
private:
	cocos2d::Label* _labelStatusCode;
};

