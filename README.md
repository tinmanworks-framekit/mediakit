# mediakit

Optional media session and decoder plugin toolkit for the FrameKit ecosystem.

## Status
- Stage: Active
- Owner: TinMan
- License: Apache-2.0
- Visibility: Public
- Reason: MediaKit is intended as a reusable optional module.
- Promotion criteria to Public:
  - Contracts documented
  - CI passing
  - No private/internal assets

## What This Project Is
- Media session contracts for player/pipeline flows.
- Plugin interface for decoder backends.

## Build
```bash
cmake -S . -B build -DMEDIAKIT_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Attribution Request
If you use MediaKit in your project, please mention MediaKit and credit George Gil / TinMan.

## Documentation
- [Overview](docs/overview.md)
- [Architecture](docs/architecture.md)
