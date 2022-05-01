
```sh
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
docker-compose run --rm compile qmk <new-keymap>
docker-compose run --rm compile
```

```sh
git clone https://github.com/qmk/qmk_toolbox.git
./avrdude.sh qmk_firmware/.build/crkbd_rev1_<new-keymap>.hex
```

```sh
./eeprom.sh left
./eeprom.sh right
```

![layout](qmk_firmware/keyboards/crkbd/keymaps/base/layout.drawio.svg)

## references
- [QMK Firmware](https://docs.qmk.fm/#/)
- [QMK FirmwareをDockerでビルドする](https://qiita.com/akiakishitai/items/47292e29e6c4ed2d33dd)
- [QMK Firmware で Raise/Lower と変換/無変換を同じキーに割り当てる](https://okapies.hateblo.jp/entry/2019/02/02/133953)
- [Corne CherryでレイヤーごとにLEDを切り替える](https://zenn.dev/eholic/articles/qmk-crkbd-led#rgb-lighting%E3%81%AE%E5%A0%B4%E5%90%88)
- [WSL2だけで自作キーボードを楽しみたい](https://techracho.bpsinc.jp/miyason/2020_09_01/96931)
- [feiz/avrdude.sh](https://gist.github.com/feiz/21293cbdff8a2e70b2d0af1389f2f279)
- [QMKの環境構築～レイヤ状態ごとのLEDの設定(Windows)](https://jpdebug.com/p/2303879)