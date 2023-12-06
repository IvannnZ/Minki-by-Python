from setuptools import Extension, setup

setup(
    name="foreign",
    version="1.0.0",
    description="Python interface for printing something from C",
    author="dbg",
    author_email="ivan.ugliansky@gmail.com",
    ext_modules=[
        Extension(
            name="foreign",
            sources=["foreignmodule.c"],
        ),
    ]
)
