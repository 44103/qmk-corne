
```
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
docker-compose run --rm compile qmk new-keymap
docker-compose run --rm compile
```

![layout](qmk_firmware/keyboards/crkbd/keymaps/base/layout.drawio.svg)

## references
- [QMK Firmware](https://docs.qmk.fm/#/)
- [QMK FirmwareをDockerでビルドする](https://qiita.com/akiakishitai/items/47292e29e6c4ed2d33dd)
- [QMK Firmware で Raise/Lower と変換/無変換を同じキーに割り当てる](https://okapies.hateblo.jp/entry/2019/02/02/133953)