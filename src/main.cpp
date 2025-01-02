#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/binding/MusicDownloadManager.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
class $modify(MyEditLevelLayer, EditLevelLayer) {
    bool init(GJGameLevel* p0) {
        if (!EditLevelLayer::init(p0)) return false;

        auto levelactionmenu = this->getChildByID("level-actions-menu");

        auto downloadSongButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_downloadBtn_001.png"),
            this,
            menu_selector(MyEditLevelLayer::downloadSongButtonPressed)
        );
        downloadSongButton->setUserObject(p0);

        levelactionmenu->addChild(downloadSongButton);
        downloadSongButton->setID("download-song-button");

        levelactionmenu->updateLayout();

        return true;
    }


    void downloadSongButtonPressed(CCObject*) {

        auto levelActionMenu = this->getChildByID("level-actions-menu");
            
        auto downloadSongButton = levelActionMenu->getChildByID("download-song-button");

        auto p0 = dynamic_cast<GJGameLevel*>(downloadSongButton->getUserObject());

        int songId;
        songId = p0->m_songID;

        MusicDownloadManager::sharedState()->downloadSong(songId);
    }
};