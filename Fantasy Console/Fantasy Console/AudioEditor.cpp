#include "AudioEditor.h"

AudioEditor::AudioEditor() {
}

AudioEditor::~AudioEditor() {
}

void AudioEditor::Init() {
    InitAudioDevice();
}

void AudioEditor::LoadSample(const char* fileName) {
    samples.push_back(LoadSound(fileName));
}

void AudioEditor::PlaySample(int index) {
    PlaySound(samples[index]);
}

void AudioEditor::UnloadSamples() {
    for (int i = 0; i < samples.size(); ++i) {
        UnloadSound(samples[i]);
    }
    samples.clear();
}

void AudioEditor::Update() {
}

void AudioEditor::Close() {
    CloseAudioDevice();
}
