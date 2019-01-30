from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

import numpy

setup(name='SubsequenceFinder',
      version='0.1dev',
      packages=['SubsequenceFinder'],
      ext_modules=[Extension("SubsequenceFinder_core", ["cpp/wrapper.pyx", "cpp/SubsequenceFinder.cpp"],
                             language="c++", include_dirs=[numpy.get_include()])],
      cmdclass = {'build_ext': build_ext})
