{
  pkgs ? import <nixpkgs> { },
}:

with pkgs;
mkShell {
  name = "zathura-jpg";
  buildInputs = [
    meson
    ninja
    pkg-config
    zathura
    girara
    # for cairo_jpg
    git
  ];
}
