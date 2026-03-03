#include "mediakit/media_session.hpp"

namespace mediakit {

bool MediaSession::Prepare(const MediaSessionConfig& config) {
    config_ = config;
    state_ = SessionState::kPrepared;
    return true;
}

bool MediaSession::Play() {
    if (state_ != SessionState::kPrepared && state_ != SessionState::kPaused) {
        return false;
    }
    state_ = SessionState::kPlaying;
    return true;
}

bool MediaSession::Pause() {
    if (state_ != SessionState::kPlaying) {
        return false;
    }
    state_ = SessionState::kPaused;
    return true;
}

bool MediaSession::Stop() {
    if (state_ == SessionState::kIdle) {
        return false;
    }
    state_ = SessionState::kStopped;
    return true;
}

} // namespace mediakit
