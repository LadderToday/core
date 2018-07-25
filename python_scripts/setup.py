from setuptools import setup

setup( name='coredebugnode',
       version='0.1',
       description='A wrapper for launching and interacting with a Core Debug Node',
       url='https://gitlab.com/core.network/cored',
       author='Core, Inc.',
       author_email='hello@core.io',
       license='See LICENSE.md',
       packages=['coredebugnode'],
       #install_requires=['coreapi'],
       zip_safe=False )