
```
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
docker-compose run --rm compile qmk new-keymap
docker-compose run --rm compile
```

![layout](qmk_firmware/keyboards/crkbd/keymaps/base/layout.drawio.svg)