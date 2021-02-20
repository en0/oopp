from setuptools import setup


with open("README.md", "r") as fh:
    long_description = fh.read()


setup(
    name="oopp",
    version="1.0.0",
    description="A OOP Discuession",
    long_description=long_description,
    long_description_content_type="text/markdown",
    author="Ian Laird",
    author_email="irlaird@gmail.com",
    url="https://github.com/en0/oopp",
    packages=["oopp"],
    classifiers=[
        "Programming Language :: Python :: 3.5",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
)
