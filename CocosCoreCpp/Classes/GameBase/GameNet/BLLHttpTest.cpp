#include "BLLHttpTest.h"

//FV_SINGLETON_STORAGE(BLLHttpTest);

BLLHttpTest* BLLHttpTest::mBLLHttpTest = nullptr;

BLLHttpTest::BLLHttpTest(void)
{
	//HttpManager::getInstance()->setHttpDelegate(this);
	mHttpManager = new HttpManager();
	mHttpManager->setHttpDelegate(this);
}

BLLHttpTest::~BLLHttpTest(void)
{
}
BLLHttpTest* BLLHttpTest::getInstance()
{
	if (!mBLLHttpTest)
	{
		mBLLHttpTest = new BLLHttpTest();
	}
	return mBLLHttpTest;
}
void BLLHttpTest::sendGetRequest(string url,string requestTag,onResponseCallBack cb)
{
	mMapCallBack[requestTag] = cb;
	mHttpManager->sendGetRequest(url,requestTag);
}
void BLLHttpTest::sendPostRequest(string url,string requestTag,onResponseCallBack cb)
{
	mMapCallBack[requestTag] = cb;
	mHttpManager->sendPostRequest(url,requestTag);
}

void BLLHttpTest::onHttpManagerRequestCompleted(HttpClient* sender,HttpResponse* response)
{
	const char* tag = response->getHttpRequest()->getTag();
	if (!response->isSucceed())
	{
		log("response failed");
		log("error buffer:%s",response->getErrorBuffer());
		mMapCallBack.erase(tag);
		return;
	}
	std::vector<char> *buffer = response->getResponseData();
	string temp = "";
	for (unsigned int i = 0; i < buffer->size(); i++)
	{
		temp +=(*buffer)[i];
	}
	log("Http Test, dump data:%s\n",temp.c_str());
	if (mMapCallBack[tag])
	{
		onHttpRequestCompletedDataHandle(temp,tag);
		mMapCallBack[tag](temp,tag);
		mMapCallBack.erase(tag);
	}
}

void BLLHttpTest::onHttpRequestCompletedDataHandle(string data,string tag)
{

}