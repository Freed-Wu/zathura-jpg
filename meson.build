project(
  'zathura-jpg',
  'c',
  version: '0.3.3',
  meson_version: '>=0.61',
  default_options: ['c_std=c17', 'warning_level=3'],
)

version = meson.project_version()
version_array = version.split('.')

cc = meson.get_compiler('c')

datadir = get_option('datadir')
metainfodir = join_paths(datadir, 'metainfo')
desktopdir = join_paths(datadir, 'applications')

# required dependencies
zathura = dependency('zathura', version: '>=0.5.3', fallback: ['zathura', 'zathura_dependency'])
girara = dependency('girara-gtk3', fallback: ['girara', 'girara_dependency'])
cairo_jpg = dependency('cairo_jpg', fallback: ['cairo_jpg', 'cairo_jpg_dep'])

build_dependencies = [zathura, girara, cairo_jpg]

if get_option('plugindir') == ''
  if zathura.type_name() == 'pkgconfig'
    plugindir = zathura.get_variable(pkgconfig: 'plugindir')
  else
    zathura_subproject = subproject('zathura')
    plugindir = zathura_subproject.get_variable('plugindir')
  endif
else
  plugindir = get_option('plugindir')
endif

# defines
defines = [
  '-DVERSION_MAJOR=@0@'.format(version_array[0]),
  '-DVERSION_MINOR=@0@'.format(version_array[1]),
  '-DVERSION_REV=@0@'.format(version_array[2]),
  '-D_DEFAULT_SOURCE',
]

# compile flags
flags = [
  '-Werror=implicit-function-declaration',
  '-Werror=vla',
]
flags = cc.get_supported_arguments(flags)

sources = files(
  'zathura-jpg/document.c',
  'zathura-jpg/page.c',
  'zathura-jpg/plugin.c',
)

shared_module(
  'jpg',
  sources,
  dependencies: build_dependencies,
  c_args: defines + flags,
  install: true,
  install_dir: plugindir,
  gnu_symbol_visibility: 'hidden',
)

subdir('data')
