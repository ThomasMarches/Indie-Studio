/*
** EPITECH PROJECT, 2020
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Image.hpp
*/

#ifndef RAYLIB_IMAGE_HPP_
#define RAYLIB_IMAGE_HPP_

#include <string>
#include "raylib.hpp"

namespace ray {
    class Image : public ::Image {
    public:
        Image(const ::Image& image);
        Image(const std::string& fileName);
        void set(const ::Image& image);
        ~Image();
        void Unload();
        void Load(const std::string& fileName);
        // Image(const std::string& fileName, int width, int height, int format, int headerSize);
        // Image(const std::string& fileName, int* frames);
        // Image(const std::string& fileType, const unsigned char* fileData, int dataSize);
        // Image(const ::Texture2D& texture);
        // Image(int width, int height, ::Color color = {255, 255, 255, 255});
        // Image(const ::Font& font, const std::string& text, float fontSize, float spacing, ::Color tint = {255, 255, 255, 255});
        // ::Image Text(const std::string& text, int fontSize, ::Color color = {255, 255, 255, 255});
        // ::Image Text(const ::Font& font, const std::string& text, float fontSize, float spacing, ::Color tint = {255, 255, 255, 255});
        // ::Image GetScreenData();
        // ::Image Color(int width, int height, ::Color color = {255, 255, 255, 255});
        // ::Image GradientV(int width, int height, ::Color top, ::Color bottom);
        // ::Image GradientH(int width, int height, ::Color left, ::Color right);
        // ::Image GradientRadial(int width, int height, float density, ::Color inner, ::Color outer);
        // ::Image Checked(int width, int height, int checksX, int checksY, ::Color col1 = {255, 255, 255, 255}, ::Color col2 = {0, 0, 0, 255});
        // ::Image WhiteNoise(int width, int height, float factor);
        // ::Image PerlinNoise(int width, int height, int offsetX, int offsetY, float scale = 1.0f);
        // ::Image Cellular(int width, int height, int tileSize);
        // Image& operator=(const ::Image& image);
        // void LoadRaw(const std::string& fileName, int width, int height, int format, int headerSize);
        // void LoadAnim(const std::string& fileName, int *frames);
        // void LoadFromMemory(const std::string& fileType, const unsigned char *fileData, int dataSize);
        // bool Export(const std::string& fileName);
        // bool ExportAsCode(const std::string& fileName);
        // Vec2 GetSize();
        // ::Image Copy();
        // ::Image FromImage(::Rectangle rec);
        // Image& ToPOT(::Color fillColor);
        // Image& Format(int newFormat);
        // Image& AlphaMask(const ::Image& alphaMask);
        // Image& AlphaCrop(float threshold);
        // Image& AlphaPremultiply();
        // Image& Crop(::Rectangle crop);
        // Image& Crop(Vec2 size);
        // Image& Crop(int offsetX, int offsetY, int newWidth, int newHeight);
        // Image& Resize(int newWidth, int newHeight);
        // Image& ResizeNN(int newWidth, int newHeight);
        // Image& ResizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, ::Color color = {255, 255, 255, 255});
        // Image& Mipmaps();
        // Image& Dither(int rBpp, int gBpp, int bBpp, int aBpp);
        // Image& FlipVertical();
        // Image& FlipHorizontal();
        // Image& RotateCW();
        // Image& RotateCCW();
        // Image& ColorTint(::Color color = {255, 255, 255, 255});
        // Image& ColorInvert();
        // Image& ColorGrayscale();
        // Image& ColorContrast(float contrast);
        // Image& ColorBrightness(int brightness);
        // Image& ColorReplace(::Color color, ::Color replace);
        // Rectangle GetAlphaBorder(float threshold) const;
        // Image& ClearBackground(::Color color = {0, 0, 0, 255});
        // Image& DrawPixel(int posX, int posY, ::Color color = {255, 255, 255, 255});
        // Image& DrawPixel(Vec2 position, ::Color color = {255, 255, 255, 255});
        // Image& DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, ::Color color = {255, 255, 255, 255});
        // Image& DrawLine(Vec2 start, Vec2 end, ::Color color = {255, 255, 255, 255});
        // Image& DrawCircle(int centerX, int centerY, int radius, ::Color color = {255, 255, 255, 255});
        // Image& DrawCircle(Vec2 center, int radius, ::Color color = {255, 255, 255, 255});
        // Image& DrawRectangle(int posX, int posY, int width, int height, ::Color color = {255, 255, 255, 255});
        // Image& DrawRectangle(Vec2 position, Vec2 size, ::Color color = {255, 255, 255, 255});
        // Image& DrawRectangle(::Rectangle rec, ::Color color = {255, 255, 255, 255});
        // Image& DrawRectangleLines(::Rectangle rec, int thick = 1, ::Color color = {255, 255, 255, 255});
        // Image& Draw(const ::Image& src, ::Rectangle srcRec, ::Rectangle dstRec, ::Color tint = {255, 255, 255, 255});
        // Image& DrawText(const std::string& text, Vec2 position, int fontSize, ::Color color = {255, 255, 255, 255});
        // Image& DrawText(const std::string& text, int x, int y, int fontSize, ::Color color = {255, 255, 255, 255});
        // Image& DrawText(const ::Font& font, const std::string& text, Vec2 position, float fontSize, float spacing, ::Color tint = {255, 255, 255, 255});
        // ::Color* LoadColors();
        // ::Color* LoadPalette(int maxPaletteSize, int *colorsCount);
        // void UnloadColors(::Color* colors);
        // void UnloadPalette(::Color* colors);
        // ::Texture2D LoadTexture();
        // operator::Texture2D();
        // int GetPixelDataSize(int width, int height, int format = PIXELFORMAT_UNCOMPRESSED_R32G32B32A32);
        // int GetPixelDataSize();
    };
}  // namespace ray

#endif  // RAYLIB_IMAGE_HPP_