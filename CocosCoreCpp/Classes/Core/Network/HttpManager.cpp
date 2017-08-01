#include "HttpManager.h"


//FV_SINGLETON_STORAGE(HttpManager);
//HttpManager* HttpManager::mHttpManager = nullptr;

HttpManager::HttpManager(void)
{
	_httpManagerDelegate = nullptr;
	HttpClient::getInstance()->setTimeoutForConnect(5);
}

HttpManager::~HttpManager(void)
{
}
//HttpManager* HttpManager::getInstance()
//{
//	if (mHttpManager == nullptr)
//	{
//		mHttpManager = new HttpManager();
//	}
//	return mHttpManager;
//}
void HttpManager::sendGetRequest(string url,string requestTag)
{
	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setRequestType(HttpRequest::Type::GET);
	request->setUrl(url.c_str());
	request->setResponseCallback(CC_CALLBACK_2(HttpManager::onHttpRequestCompleted,this));
	request->setTag(requestTag.c_str());
	HttpClient::getInstance()->send(request);
	request->release();
}

void HttpManager::sendPostRequest(string url,string requestTag)
{
	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setRequestType(HttpRequest::Type::POST);
	request->setUrl(url.c_str());
	request->setResponseCallback(CC_CALLBACK_2(HttpManager::onHttpRequestCompleted,this));
	request->setTag(requestTag.c_str());
	request->setRequestData("",0);
	HttpClient::getInstance()->send(request);
	request->release();
}
void HttpManager::onHttpRequestCompleted(HttpClient* sender,HttpResponse* response)
{
	if (!response)
	{
		return;
	}
	const char* tag = response->getHttpRequest()->getTag();
	if (0 != strlen(tag))
	{
		log("%s completed",tag);
	}
	log("HTTP Status Code::%ld, tag = %s",response->getResponseCode(),tag);
	//if (!response->isSucceed())
	//{
	//	log("response failed");
	//	log("error buffer:%s",response->getErrorBuffer());
	//	mMapCallBack.erase(tag);
	//	return;
	//}
	if (_httpManagerDelegate)
	{
		_httpManagerDelegate->onHttpManagerRequestCompleted(sender,response);
	}
}