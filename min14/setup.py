from setuptools import Extension, setup

setup(
    name="foreign",
    version="1.0.0",
    description="",
    author="",
    author_email="",
    ext_modules=[
        Extension(
            name="foreign",
            sources=["foreign.c"],
        ),
    ]
)