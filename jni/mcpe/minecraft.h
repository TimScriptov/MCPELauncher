#pragma once
class Level;
class Timer;
namespace mce {
class TextureGroup;
} // namespace mce
class Mob;
class Options;
class AbstractScreen;
class ScreenChooser;
class GuiData;
class MinecraftCommands;
class Minecraft {
public:
	Level* getLevel();
	Timer* getTimer();
	MinecraftCommands* getCommands();
};

class MinecraftClient {
public:
	Minecraft* getServer();
	Player* getLocalPlayer();
	mce::TextureGroup& getTextures() const;
	void setCameraEntity(Entity*);
	void setCameraTargetEntity(Entity*);
	Options* getOptions();
	AbstractScreen* getScreen();
	ScreenChooser& getScreenChooser() const;
	GuiData* getGuiData();
	void onResourcesLoaded();
};
