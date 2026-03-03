#pragma once

#include "mediakit/media_source.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace mediakit::plugin {

struct DecoderFrame {
    std::vector<std::uint8_t> payload;
    std::uint64_t pts = 0;
};

class IDecoderPlugin {
public:
    virtual ~IDecoderPlugin() = default;

    virtual std::string Name() const = 0;
    virtual bool Supports(const mediakit::MediaSource& source) const = 0;
    virtual bool Open(const mediakit::MediaSource& source) = 0;
    virtual DecoderFrame DecodeNext() = 0;
    virtual void Close() = 0;
};

} // namespace mediakit::plugin
