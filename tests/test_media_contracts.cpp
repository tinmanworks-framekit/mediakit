#include "mediakit/mediakit.hpp"

#include <cassert>

int main() {
    mediakit::MediaSession session;

    mediakit::MediaSessionConfig config;
    config.session_name = "test-session";
    config.source.kind = mediakit::MediaSourceKind::kFile;
    config.source.uri = "sample.mp4";

    assert(session.Prepare(config));
    assert(session.State() == mediakit::SessionState::kPrepared);

    assert(session.Play());
    assert(session.State() == mediakit::SessionState::kPlaying);

    assert(session.Pause());
    assert(session.State() == mediakit::SessionState::kPaused);

    assert(session.Stop());
    assert(session.State() == mediakit::SessionState::kStopped);

    return 0;
}
