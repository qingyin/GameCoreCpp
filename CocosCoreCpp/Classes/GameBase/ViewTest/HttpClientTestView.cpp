#include "HttpClientTestView.h"

#include "GameBase/GameNet/BLLHttpTest.h"

#include "GameBase/JniCross/JniUtil.h"

HttpClientTest::HttpClientTest(void)
{
}
HttpClientTest::~HttpClientTest(void)
{
}

bool HttpClientTest::init()
{
	auto winSize = Director::getInstance()->getWinSize();

	const int MARGIN = 40;
	const int SPACE = 35;

	const int LEFT = winSize.width / 4;
	const int RIGHT = winSize.width / 4 * 3;

	auto menuRequest = Menu::create();
	menuRequest->setPosition(Vec2::ZERO);
	addChild(menuRequest);

	// Get 
	auto labelGet = Label::createWithTTF("Test Get", "fonts/arial.ttf", 22);
	auto itemGet = MenuItemLabel::create(labelGet, CC_CALLBACK_1(HttpClientTest::onMenuGetTestClicked, this, false));
	itemGet->setPosition(LEFT, winSize.height - MARGIN - SPACE);
	menuRequest->addChild(itemGet);

	// Post
	auto labelPost = Label::createWithTTF("Test Post", "fonts/arial.ttf", 22);
	auto itemPost = MenuItemLabel::create(labelPost, CC_CALLBACK_1(HttpClientTest::onMenuPostTestClicked, this, false));
	itemPost->setPosition(LEFT, winSize.height - MARGIN - 2 * SPACE);
	menuRequest->addChild(itemPost);

	// Post Binary
	auto labelPostBinary = Label::createWithTTF("Test Post Binary", "fonts/arial.ttf", 22);
	auto itemPostBinary = MenuItemLabel::create(labelPostBinary, CC_CALLBACK_1(HttpClientTest::onMenuPostBinaryTestClicked, this, false));
	itemPostBinary->setPosition(LEFT, winSize.height - MARGIN - 3 * SPACE);
	menuRequest->addChild(itemPostBinary);

	// Put
	auto labelPut = Label::createWithTTF("Test Put", "fonts/arial.ttf", 22);
	auto itemPut = MenuItemLabel::create(labelPut, CC_CALLBACK_1(HttpClientTest::onMenuPutTestClicked, this, false));
	itemPut->setPosition(LEFT, winSize.height - MARGIN - 4 * SPACE);
	menuRequest->addChild(itemPut);

	// Delete
	auto labelDelete = Label::createWithTTF("Test Delete", "fonts/arial.ttf", 22);
	auto itemDelete = MenuItemLabel::create(labelDelete, CC_CALLBACK_1(HttpClientTest::onMenuDeleteTestClicked, this, false));
	itemDelete->setPosition(LEFT, winSize.height - MARGIN - 5 * SPACE);
	menuRequest->addChild(itemDelete);

	// Get for sendImmediate
	labelGet = Label::createWithTTF("Test Immediate Get", "fonts/arial.ttf", 22);
	itemGet = MenuItemLabel::create(labelGet, CC_CALLBACK_1(HttpClientTest::onMenuGetTestClicked, this, true));
	itemGet->setPosition(RIGHT, winSize.height - MARGIN - SPACE);
	menuRequest->addChild(itemGet);

	// Post for sendImmediate
	labelPost = Label::createWithTTF("Test Immediate Post", "fonts/arial.ttf", 22);
	itemPost = MenuItemLabel::create(labelPost, CC_CALLBACK_1(HttpClientTest::onMenuPostTestClicked, this, true));
	itemPost->setPosition(RIGHT, winSize.height - MARGIN - 2 * SPACE);
	menuRequest->addChild(itemPost);

	// Post Binary for sendImmediate
	labelPostBinary = Label::createWithTTF("Test Immediate Post Binary", "fonts/arial.ttf", 22);
	itemPostBinary = MenuItemLabel::create(labelPostBinary, CC_CALLBACK_1(HttpClientTest::onMenuPostBinaryTestClicked, this, true));
	itemPostBinary->setPosition(RIGHT, winSize.height - MARGIN - 3 * SPACE);
	menuRequest->addChild(itemPostBinary);

	// Put for sendImmediate
	labelPut = Label::createWithTTF("Test Immediate Put", "fonts/arial.ttf", 22);
	itemPut = MenuItemLabel::create(labelPut, CC_CALLBACK_1(HttpClientTest::onMenuPutTestClicked, this, true));
	itemPut->setPosition(RIGHT, winSize.height - MARGIN - 4 * SPACE);
	menuRequest->addChild(itemPut);

	// Delete for sendImmediate
	labelDelete = Label::createWithTTF("Test Immediate Delete", "fonts/arial.ttf", 22);
	itemDelete = MenuItemLabel::create(labelDelete, CC_CALLBACK_1(HttpClientTest::onMenuDeleteTestClicked, this, true));
	itemDelete->setPosition(RIGHT, winSize.height - MARGIN - 5 * SPACE);
	menuRequest->addChild(itemDelete);

	// Response Code Label
	_labelStatusCode = Label::createWithTTF("HTTP Status Code", "fonts/arial.ttf", 18);
	_labelStatusCode->setPosition(winSize.width / 2,  winSize.height - MARGIN - 6 * SPACE);
	addChild(_labelStatusCode);
	
	return true;
}

void HttpClientTest::onMenuGetTestClicked(cocos2d::Ref *sender, bool isImmediate)
{    
	JniUtil::callJava_callNativeFunShowText(false,1,2.3,4.5,"nimen����women");
	JniUtil::callJava_copyText("copyText---women");
	return;

	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://just-make-this-request-failed.com");
		request->setRequestType(HttpRequest::Type::GET);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
		if (isImmediate)
		{
			request->setTag("GET immediate test1");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("GET test1");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	//// test 2
	//{
	//	HttpRequest* request = new (std::nothrow) HttpRequest();
	//	// required fields
	//	request->setUrl("http://httpbin.org/ip");
	//	request->setRequestType(HttpRequest::Type::GET);
	//	request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
	//	if (isImmediate)
	//	{
	//		request->setTag("GET immediate test2");
	//		HttpClient::getInstance()->sendImmediate(request);
	//	}else
	//	{
	//		request->setTag("GET test2");
	//		HttpClient::getInstance()->send(request);
	//	}
	//	// don't forget to release it, pair to new
	//	request->release();
	//}

	//// test 3   
	//{
	//	HttpRequest* request = new (std::nothrow) HttpRequest();
	//	request->setUrl("https://httpbin.org/get");
	//	request->setRequestType(HttpRequest::Type::GET);
	//	request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
	//	if (isImmediate)
	//	{
	//		request->setTag("GET immediate test3");
	//		HttpClient::getInstance()->sendImmediate(request);
	//	}else
	//	{
	//		request->setTag("GET test3");
	//		HttpClient::getInstance()->send(request);
	//	}
	//	request->release();
	//}

	//// waiting
	//_labelStatusCode->setString("waiting...");

}
void HttpClientTest::onMenuPostTestClicked(cocos2d::Ref *sender, bool isImmediate)
{
	string str = JniUtil::callJava_getAppVersion();
	log("--------callJava_getAppVersion-----str---%s",str.c_str());
	str = JniUtil::callJava_getTestAllString(false,11,2.3,4.5,"nimen����women1+1");
	log("-------callJava_getTestAllString------str---%s",str.c_str());
	return;
	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/post");
		request->setRequestType(HttpRequest::Type::POST);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));

		// write the post data
		const char* postData = "visitor=cocos2d&TestSuite=Extensions Test/NetworkTest";
		request->setRequestData(postData, strlen(postData));
		if (isImmediate)
		{
			request->setTag("POST immediate test1");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("POST test1");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// test 2: set Content-Type
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/post");
		request->setRequestType(HttpRequest::Type::POST);
		std::vector<std::string> headers;
		headers.push_back("Content-Type: application/json; charset=utf-8");
		request->setHeaders(headers);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));

		// write the post data
		const char* postData = "visitor=cocos2d&TestSuite=Extensions Test/NetworkTest";
		request->setRequestData(postData, strlen(postData));
		if (isImmediate)
		{
			request->setTag("POST immediate test2");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("POST test2");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// waiting
	_labelStatusCode->setString("waiting...");
}

void HttpClientTest::onResponseCallBack(string responseData,const char* tag)
{
	log("----====%s,tag=%s",responseData.c_str(),tag);
}
void HttpClientTest::onMenuPostBinaryTestClicked(cocos2d::Ref *sender, bool isImmediate)
{
	BLLHttpTest::getInstance()->sendGetRequest("www.baidu.com","baidu",CC_CALLBACK_2(HttpClientTest::onResponseCallBack,this));
	return;
	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setUrl("http://httpbin.org/post");
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));

	// write the post data
	char postData[22] = "binary=hello\0\0cocos2d";  // including \0, the strings after \0 should not be cut in response
	request->setRequestData(postData, 22); 
	if (isImmediate)
	{
		request->setTag("POST Binary immediate test");
		HttpClient::getInstance()->sendImmediate(request);
	}else
	{
		request->setTag("POST Binary test");
		HttpClient::getInstance()->send(request);
	}
	request->release();

	// waiting
	_labelStatusCode->setString("waiting...");
}



void HttpClientTest::onMenuPutTestClicked(Ref *sender, bool isImmediate)
{
	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/put");
		request->setRequestType(HttpRequest::Type::PUT);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));

		// write the post data
		const char* postData = "visitor=cocos2d&TestSuite=Extensions Test/NetworkTest";
		request->setRequestData(postData, strlen(postData));
		if (isImmediate)
		{
			request->setTag("PUT Binary immediate test1");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("PUT Binary test1");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// test 2: set Content-Type
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/put");
		request->setRequestType(HttpRequest::Type::PUT);
		std::vector<std::string> headers;
		headers.push_back("Content-Type: application/json; charset=utf-8");
		request->setHeaders(headers);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));

		// write the post data
		const char* postData = "visitor=cocos2d&TestSuite=Extensions Test/NetworkTest";
		request->setRequestData(postData, strlen(postData));
		if (isImmediate)
		{
			request->setTag("PUT Binary immediate test2");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("PUT Binary test2");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// waiting
	_labelStatusCode->setString("waiting...");
}

void HttpClientTest::onMenuDeleteTestClicked(Ref *sender, bool isImmediate)
{
	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://just-make-this-request-failed.com");
		request->setRequestType(HttpRequest::Type::DELETE);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
		if (isImmediate)
		{
			request->setTag("DELETE immediate test1");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("DELETE test1");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// test 2
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/delete");
		request->setRequestType(HttpRequest::Type::DELETE);
		request->setResponseCallback(CC_CALLBACK_2(HttpClientTest::onHttpRequestCompleted, this));
		if (isImmediate)
		{
			request->setTag("DELETE immediate test2");
			HttpClient::getInstance()->sendImmediate(request);
		}else
		{
			request->setTag("DELETE test2");
			HttpClient::getInstance()->send(request);
		}
		request->release();
	}

	// waiting
	_labelStatusCode->setString("waiting...");
}

void HttpClientTest::onHttpRequestCompleted(HttpClient *sender, HttpResponse *response)
{
	if (!response)
	{
		return;
	}

	// You can get original request type from: response->request->reqType
	if (0 != strlen(response->getHttpRequest()->getTag())) 
	{
		log("%s completed", response->getHttpRequest()->getTag());
	}

	long statusCode = response->getResponseCode();
	char statusString[64] = {};
	sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
	_labelStatusCode->setString(statusString);
	log("response code: %ld", statusCode);

	if (!response->isSucceed()) 
	{
		log("response failed");
		log("error buffer: %s", response->getErrorBuffer());
		return;
	}

	// dump data
	std::vector<char> *buffer = response->getResponseData();
	string temp = "";
	for (unsigned int i = 0; i < buffer->size(); i++)
	{
		temp +=(*buffer)[i];
	}
	log("Http Test, dump data:%s\n",temp.c_str());

	buffer = response->getResponseHeader();
	temp = "";
	for (unsigned int i = 0; i < buffer->size(); i++)
	{
		temp +=(*buffer)[i];
	}
	log("Http Test, ResponseHeader:%s\n",temp.c_str());

	if (response->getHttpRequest()->getReferenceCount() != 2)
	{
		log("request ref count not 2, is %d", response->getHttpRequest()->getReferenceCount());
	}
}
