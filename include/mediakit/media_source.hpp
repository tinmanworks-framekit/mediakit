#pragma once

#include <string>

namespace mediakit {

enum class MediaSourceKind {
    kFile,
    kStream,
    kDevice,
};

struct MediaSource {
    MediaSourceKind kind = MediaSourceKind::kFile;
    std::string uri;
};

} // namespace mediakit
