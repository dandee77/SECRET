#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "raylib.h"

class ResourceManager {
public:
    // Get the singleton instance of the ResourceManager
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    // Delete copy and move constructors and assignment operators to enforce singleton pattern
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Load a texture if it hasn't been loaded, otherwise return existing texture
    Texture2D& getTexture(const std::string& filename) {
        if (textures.find(filename) == textures.end()) {
            textures[filename] = std::make_unique<Texture2D>(LoadTexture(filename.c_str()));
        }
        return *textures[filename];
    }

    // Load a sound if it hasn't been loaded, otherwise return existing sound
    Sound& getSound(const std::string& filename) {
        if (sounds.find(filename) == sounds.end()) {
            sounds[filename] = std::make_unique<Sound>(LoadSound(filename.c_str()));
        }
        return *sounds[filename];
    }

    // Load a font if it hasn't been loaded, otherwise return existing font
    Font& getFont(const std::string& filename) {
        if (fonts.find(filename) == fonts.end()) {
            fonts[filename] = std::make_unique<Font>(LoadFont(filename.c_str()));
        }
        return *fonts[filename];
    }

    // Load a music file if it hasn't been loaded, otherwise return existing music
    Music& getMusic(const std::string& filename) {
        if (music.find(filename) == music.end()) {
            music[filename] = std::make_unique<Music>(LoadMusicStream(filename.c_str()));
        }
        return *music[filename];
    }

    // Cleanup resources on exit
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
    // Private constructor to enforce singleton pattern
    ResourceManager() = default;
    ~ResourceManager() {
        unloadAllResources();
    }

    // Maps to store loaded resources
    std::unordered_map<std::string, std::unique_ptr<Texture2D>> textures;
    std::unordered_map<std::string, std::unique_ptr<Sound>> sounds;
    std::unordered_map<std::string, std::unique_ptr<Font>> fonts;
    std::unordered_map<std::string, std::unique_ptr<Music>> music;
};
