project('meow', 'cpp', default_options: ['cpp_std=c++23'])

tb_dep = dependency('termbox2')
spd_log_dep = dependency('spdlog')

sources = [
  'src/main.cpp',
  'src/File.cpp',
  'src/Editor.cpp',
  'src/Renderer.cpp',
  'src/TextLine.cpp',
  'src/Cursor.cpp',
]

inc = include_directories('include')

executable(
  'meow',
  sources,
  dependencies: [tb_dep, spd_log_dep],
  include_directories: inc,
)
