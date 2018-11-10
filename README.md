# Converts 1920x1080 YUV to RGB

This converts the uncompressed raw color data from the KinectV2's raw color stream into an rgb image.

This image happens to be encoded in YUV so this uses opencv to convert it to a three channel rgb image.

## Tutorial (OSX)
1. Install opencv with `brew install opencv`
2. Run to compile `g++ $(pkg-config --cflags --libs opencv) -std=c++11  yuv2Rgb.cpp -o OUTPUT`
3. Run with `OUTPUT INPUT_FILENAME OUTPUT_FILENAME`
