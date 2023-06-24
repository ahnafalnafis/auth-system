# Welcome to Login and Registration system contributing guide

Thank you for investing your time in contributing this project!

## Getting started

If you are a new contributor, I hope that you read the [README](README.md) you
will get the overview of the project.

Project structure:

`*` marked files or folders should not be included in the git repository. They
should exists in the project folder when it is being developed.

```
[PROJECT DIRECTORY]
├── bin                 - This is where your binaries(*) will go to.
│   └── app
├── build.sh            - To automate the build process.
├── .clang-format       - Code formatting settings.
├── CONTRIBUTING.md
├── database.json       - This is where the data(*) will be stored.
├── .gitignore
├── LICENSE
├── README.md
└── src
    ├── database.cpp    - Database handler.
    ├── database.h
    ├── main.cpp
    ├── user.cpp        - User handler.
    ├── user.h
    ├── utils.cpp       - Utility functions.
    └── utils.h
```
