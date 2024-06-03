#ifndef AUDIO_EDITOR_H
#define AUDIO_EDITOR_H

#include "raylib.h"
#include <vector>

class AudioEditor {
public:
    AudioEditor();
    ~AudioEditor();

    void Init();
    void LoadSample(const char* fileName);
    void PlaySample(int index);
    void UnloadSamples();
    void Update();
    void Close();

private:
    std::vector<Sound> samples;
};

#endif // AUDIO_EDITOR_H
