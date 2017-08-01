
#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
//#include "network/HttpClient.h"
#include "network/CCDownloader.h"
USING_NS_CC;
using namespace ui;

class DownloaderTests : public Layer
{
public:
	DownloaderTests(void);
	~DownloaderTests(void);
	virtual void onEnter();
	Node* createDownloadView(const char *name, const Widget::ccWidgetClickCallback &callback);

	CREATE_FUNC(DownloaderTests);
	void btnHandle(Ref* sender);
private:

	enum {
		TAG_TITLE = 1,
		TAG_BUTTON,
		TAG_PROGRESS_BAR,
		TAG_STATUS,
		TAG_SPRITE,
	};
	std::unique_ptr<network::Downloader> downloader;
	Vec2 getPositionCenter();
};