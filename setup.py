from distutils.core import setup, Extension

module1 = Extension(
    'helloworld',
    include_dirs = ['/usr/local/include'],
    libraries = [],
    sources = ['helloworldmodule.c']
)

setup(
    name = 'helloworld',
    version = '0.0.2',
    description = 'Silly module to try it out',
    author = 'zonk1024',
    url = 'http://zonk1024.net',
    ext_modules = [module1]
)
