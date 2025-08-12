project('kilocpp', 'cpp')

tb_dep = dependency('termbox2')

sources = ['src/main.cpp', 'src/File.cpp', 'src/Editor.cpp', 'src/Renderer.cpp']

inc = include_directories('include')

executable('kilocpp', sources, dependencies: [tb_dep], include_directories: inc)
