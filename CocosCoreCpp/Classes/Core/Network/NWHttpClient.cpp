#include "NWHttpClient.h"

NWHttpClient* NWHttpClient::m_http = nullptr;

NWHttpClient::NWHttpClient(void)
{
}
NWHttpClient::~NWHttpClient(void)
{
	CC_SAFE_DELETE(m_http);
}

NWHttpClient* NWHttpClient::getInstance()
{
	if (m_http == nullptr)
	{
		m_http = new NWHttpClient();
	}
	return m_http;
}

void NWHttpClient::sendHttpData(const string tag,const char* url,HttpRequest::Type type,bool isImmediate)
{
	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setUrl(url);
	request->setRequestType(type);
	request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted,this));
	if (isImmediate)
	{
		std::string str = "immediate"+tag;
		request->setTag(str.c_str());
		HttpClient::getInstance()->sendImmediate(request);
	}else
	{
		request->setTag(tag.c_str());
		HttpClient::getInstance()->send(request);
	}
	request->release();
}
void NWHttpClient::onHttpRequestCompleted(HttpClient* sender,HttpResponse* response)
{
	if (!response)
	{
		return;
	}
	if (0 != strlen(response->getHttpRequest()->getTag()))
	{
		log("%s completed",response->getHttpRequest()->getTag());
	}
	log("response code:%ld",response->getResponseCode());
	if (!response->isSucceed())
	{
		log("response failed");
		log("error buffer:%s",response->getErrorBuffer());
		return;
	}
	log("response json is : %s",response->getResponseDataString());
}

void NWHttpClient::onGetTest(bool isImmediate)
{
	char* url = "http://just-make-this-request-failed.com";
	sendHttpData("11",url,HttpRequest::Type::GET,true);
	url = "http://httpbin.org/ip";
	sendHttpData("12",url,HttpRequest::Type::GET,true);
	url = "https://httpbin.org/get";
	sendHttpData("13",url,HttpRequest::Type::GET,true);

}
void NWHttpClient::onPostTest(cocos2d::Ref *sender,bool isImmediate)
{
	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setUrl("http://httpbin.org/post");
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted, this));

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
}
void NWHttpClient::onPutTest(bool isImmediate)
{
	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://httpbin.org/put");
		request->setRequestType(HttpRequest::Type::PUT);
		request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted, this));

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
		request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted, this));

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
}
void NWHttpClient::onDeleteTest(bool isImmediate)
{
	// test 1
	{
		HttpRequest* request = new (std::nothrow) HttpRequest();
		request->setUrl("http://just-make-this-request-failed.com");
		request->setRequestType(HttpRequest::Type::DELETE);
		request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted, this));
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
		request->setResponseCallback(CC_CALLBACK_2(NWHttpClient::onHttpRequestCompleted, this));
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
}