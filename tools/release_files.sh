#!/bin/bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Jan Althaus (JPPeterson-lab)
# Builds the firmware and copies the four files for the web installer and the updates to docs/firmware/.
#   bash tools/release_files.sh
set -e
cd "$(dirname "$0")/.."
OUT="$(pwd)/build"
arduino-cli compile --fqbn "esp32:esp32:esp32s3:PSRAM=opi,FlashSize=16M,PartitionScheme=custom" --output-dir "$OUT" .
BOOTAPP0=$(ls ~/Library/Arduino15/packages/esp32/hardware/esp32/*/tools/partitions/boot_app0.bin ~/.arduino15/packages/esp32/hardware/esp32/*/tools/partitions/boot_app0.bin 2>/dev/null | tail -1)
mkdir -p docs/firmware
cp "$OUT/WetterCubePlus-Europe.ino.bin"            docs/firmware/firmware.bin
cp "$OUT/WetterCubePlus-Europe.ino.bootloader.bin" docs/firmware/bootloader.bin
cp "$OUT/WetterCubePlus-Europe.ino.partitions.bin" docs/firmware/partitions.bin
cp "$BOOTAPP0"                                     docs/firmware/boot_app0.bin
echo "Files copied to docs/firmware/. Check the version with: bash bump_version.sh --check"
