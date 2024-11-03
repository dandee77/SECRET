#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "raylib.h"

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    Texture2D& getTexture(const std::string& filename) {
        if (textures.find(filename) == textures.end()) {
            textures[filename] = std::make_unique<Texture2D>(LoadTexture(filename.c_str()));
        }
        return *textures[filename];
    }

    Sound& getSound(const std::string& filename) {
        if (sounds.find(filename) == sounds.end()) {
            sounds[filename] = std::make_unique<Sound>(LoadSound(filename.c_str()));
        }
        return *sounds[filename];
    }

    Font& getFont(const std::string& filename) {
        if (fonts.find(filename) == fonts.end()) {
            fonts[filename] = std::make_unique<Font>(LoadFont(filename.c_str()));
        }
        return *fonts[filename];
    }

    Music& getMusic(const std::string& filename) {
        if (music.find(filename) == music.end()) {
            music[filename] = std::make_unique<Music>(LoadMusicStream(filename.c_str()));
        }
        return *music[filename];
    }

    void unloadAllResources() {
        for (auto& texture : textures) UnloadTexture(*texture.second);
        for (auto& sound : sounds) UnloadSound(*sound.second);
        for (auto& font : fonts) UnloadFont(*font.second);
        for (auto& musicItem : music) UnloadMusicStream(*musicItem.second);

        textures.clear();
        sounds.clear();
        fonts.clear();
        music.clear();
    }

private:
    ResourceManager() = default;
    ~ResourceManager() {
        unloadAllResources();
    }

    std::unordered_map<std::string, std::unique_ptr<Texture2D>> textures;
    std::unordered_map<std::string, std::unique_ptr<Sound>> sounds;
    std::unordered_map<std::string, std::unique_ptr<Font>> fonts;
    std::unordered_map<std::string, std::unique_ptr<Music>> music;
};
