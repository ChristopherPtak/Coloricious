
project('Coloricious', 'c', default_options: ['c_std=c99'])

# Depend on libm only if it is present
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

sources = [
    'src/main.c',
    'src/options.c',
    'src/colors.c',
    'src/output.c'
]

executable('coloricious', sources, dependencies: m_dep)

