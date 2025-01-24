zathura-jpg
===========

zathura is a highly customizable and functional document viewer based on the girara user interface
library and several document libraries. This plugin for zathura provides JPG support.

Requirements
------------

The following dependencies are required:

* `zathura` (>= 0.5.3)
* `girara`
* `cairo_jpg`

Installation
------------

To build and install the plugin using meson:

```sh
meson setup build
meson compile -Cbuild
meson install -Cbuild
```
