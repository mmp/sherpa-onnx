// sherpa-onnx/csrc/offline-tts-model-config.h
//
// Copyright (c)  2023  Xiaomi Corporation

#ifndef SHERPA_ONNX_CSRC_OFFLINE_TTS_MODEL_CONFIG_H_
#define SHERPA_ONNX_CSRC_OFFLINE_TTS_MODEL_CONFIG_H_

#include <string>

#include "sherpa-onnx/csrc/offline-tts-kitten-model-config.h"
#include "sherpa-onnx/csrc/offline-tts-kokoro-model-config.h"
#include "sherpa-onnx/csrc/offline-tts-matcha-model-config.h"
#include "sherpa-onnx/csrc/offline-tts-pocket-model-config.h"
#include "sherpa-onnx/csrc/offline-tts-vits-model-config.h"
#include "sherpa-onnx/csrc/offline-tts-zipvoice-model-config.h"
#include "sherpa-onnx/csrc/parse-options.h"

namespace sherpa_onnx {

struct OfflineTtsModelConfig {
  OfflineTtsVitsModelConfig vits;
  OfflineTtsMatchaModelConfig matcha;
  OfflineTtsKokoroModelConfig kokoro;
  OfflineTtsZipvoiceModelConfig zipvoice;
  OfflineTtsKittenModelConfig kitten;
  OfflineTtsPocketModelConfig pocket;

  int32_t num_threads = 1;
  bool debug = false;
  std::string provider = "cpu";
  bool low_priority = false;

  // When non-null, use these pre-loaded buffers instead of reading from disk.
  // The caller must keep these alive for the lifetime of the TTS instance.
  const void *shared_model_data = nullptr;
  size_t shared_model_data_size = 0;
  const void *shared_voices_data = nullptr;
  size_t shared_voices_data_size = 0;

  OfflineTtsModelConfig() = default;

  OfflineTtsModelConfig(const OfflineTtsVitsModelConfig &vits,
                        const OfflineTtsMatchaModelConfig &matcha,
                        const OfflineTtsKokoroModelConfig &kokoro,
                        const OfflineTtsZipvoiceModelConfig &zipvoice,
                        const OfflineTtsKittenModelConfig &kitten,
                        const OfflineTtsPocketModelConfig &pocket,
                        int32_t num_threads, bool debug,
                        const std::string &provider)
      : vits(vits),
        matcha(matcha),
        kokoro(kokoro),
        zipvoice(zipvoice),
        kitten(kitten),
        pocket(pocket),
        num_threads(num_threads),
        debug(debug),
        provider(provider) {}

  void Register(ParseOptions *po);
  bool Validate() const;

  std::string ToString() const;
};

}  // namespace sherpa_onnx

#endif  // SHERPA_ONNX_CSRC_OFFLINE_TTS_MODEL_CONFIG_H_
