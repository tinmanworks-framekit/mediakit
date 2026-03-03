#pragma once

#include "mediakit/media_source.hpp"

#include <string>

namespace mediakit {

enum class SessionState {
    kIdle,
    kPrepared,
    kPlaying,
    kPaused,
    kStopped,
};

struct MediaSessionConfig {
    std::string session_name;
    MediaSource source;
};

class MediaSession {
public:
    MediaSession() = default;

    bool Prepare(const MediaSessionConfig& config);
    bool Play();
    bool Pause();
    bool Stop();

    SessionState State() const { return state_; }

private:
    MediaSessionConfig config_;
    SessionState state_ = SessionState::kIdle;
};

} // namespace mediakit
